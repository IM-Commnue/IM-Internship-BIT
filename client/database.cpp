#include "database.h"

void DataBase::connect_database(const char* database_name){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(database_name);
    db.open();
};
void DataBase::disconnect_database(){
    db.close();
};
bool DataBase::database_tabal_exist(const char* tabal_name){
    QString sql = QString("select * from sqlite_master where name = '%1';").arg(tabal_name);
    QSqlQuery query;
    query.exec(sql);
    return query.next();
};


/*QString("create table user(\
            username varchar(50) primary key,\
            password varchar(50),\
            nickname varchar(50))")*/
void DataBase::database_tabal_creat(QString sql_statement){
    QSqlQuery query;
    query.exec(sql_statement);
}

bool DataBase::database_username_repetition(const char* username){
    QString qstr = QString("select username from user");
    QSqlQuery query;
    query.exec(qstr);
    bool tf = true;
    while(query.next()){
        qDebug()<<query.value(0)<<"\n";
        if (username == query.value(0).toString()){
            tf = false;
        }
    }
    return tf;
}
bool DataBase::mail_correct(const char s[]){
    int x = 0;
    int len = strlen(s);
    if (len > 6) {
        for(int i = 0; i<len; i++){
            if(s[i] == '@'){
                x++;
            }
        }
    }
    if(x>0){
        return 1;
    }
    else{
        return 0;
    }
}

bool DataBase::password_correct(const char s[]){
    int x, y, z, t;
    x = 0;
    y = 0;
    z = 0;
    t = 0;
    int len = strlen(s);
    if (len > 7) {
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9')
                x++;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                y++;
            else if (s[i] >= 'a' && s[i] <= 'z')
                t++;
            else if (s[i] >= '!' && s[i] <= '/')
                z++;
            else if (s[i] >= '{' && s[i] <= '~')
                z++;
            else if (s[i] >= '[' && s[i] <= '`')
                z++;
            else if (s[i] >= ':' && s[i] <= '@')
                z++;
        }
    }
    if (x != 0 && y != 0 && z != 0 && t != 0)
        return 1;
    else
        return 0;
}

void DataBase::database_username_insert(QWidget* qw, const char* tabal_name, const char* username,
                                          const char* password, const char* mail, const char* nickname){
    QSqlQuery query;
    QString sql = QString ("insert into user(username, password, mail, nickname) \
                            values('%1', '%2', '%3', '%4')")
                .arg(username).arg(password).arg(mail).arg(nickname);
    qDebug()<<sql;
    query.exec(sql);

};

void DataBase::database_password_equal_login(QWidget* qw, const char* username, const char* password){
    QString qstr1 = QString("select password from user where uername = '%1'").arg(username);
    QSqlQuery query;
    query.exec(qstr1);
    if(query.next()){
        if (query.value(0).toString() == password){
            //登陆成功
        }
        else{
            QMessageBox::critical(qw,"失败","用户名或密码不正确！",QMessageBox::Ok);
            return;
        }
    }
    else{
        QMessageBox::critical(qw,"失败","用户名或密码不正确！",QMessageBox::Ok);
        return;
    }
}

bool DataBase::login(const char* username, const char* password){
    QSqlQuery query;
    query.exec("select username, password from user");
    bool isFound = false;
    while(query.next()){
        qDebug()<<query.value(0).toString()
               <<query.value(1).toString();
        if(query.value(0).toString() == username &&
                query.value(1).toString() == password){
            isFound = true;
        }
    }
    return isFound;
}
