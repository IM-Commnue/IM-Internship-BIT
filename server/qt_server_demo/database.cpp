#include "database.h"
#include <iostream>

DataBase::DataBase(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("nimiqq.db");
    db.open();
    query = QSqlQuery(db);
    QString qstr;
    if(!database_tabal_exist("user")){
        qstr = QString("create table user(\
                       username varchar(50) primary key,\
                       password varchar(50),\
                       nickname varchar(50),\
                       mail varchar(50),\
                       headimg text)");
        database_tabal_creat(qstr);
    }
    if(!database_tabal_exist("friends")){
        qstr = QString("create table friends (username varchar(50), friendname varchar(50))");
        database_tabal_creat(qstr);
    }
    if(!database_tabal_exist("groups")){
        qstr = QString("create table groups (groupname varchar(50), username varchar(50))");
        database_tabal_creat(qstr);
    }
}

DataBase::~DataBase(){
     db.close();
}

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

void DataBase::insert_user_group(){
    QString qstr = "insert into user(username) values ('user')";
    query.exec(qstr);
    qstr = "insert into user(username) values ('group')";
    query.exec(qstr);
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

void DataBase::database_username_insert(const char* username, const char* password, const char* mail){
    QSqlQuery query;
    QString sql = QString ("insert into user(username, password, mail) \
                            values('%1', '%2', '%3')")
                .arg(username).arg(password).arg(mail);
    qDebug()<<sql;
    query.exec(sql);

};

int DataBase::database_password_equal_login(const char* username, const char* password){
    QString qstr1 = QString("select password from user where username = '%1'").arg(username);
    QSqlQuery query;
    query.exec(qstr1);
    while(query.next()){
        if (query.value(0).toString() == password){
            //登陆成功
            return 1;
        }

    }
    return 0;
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

QString DataBase::database_all_print()
{
    QSqlQuery q;
    q.exec("select username from user");
    QString name = q.value(0).toString();
    return name;
}

QString DataBase::give_key_back(const char* username)
{
    QString qstr2 = QString("select password from user where username = '%1'").arg(username);
    QSqlQuery query2;
    query2.exec(qstr2);
    QString key = query2.value(0).toString();
    return key;
}

int DataBase::database_find_key_by_email(const char* username, const char* email)
{
    QString qstr1 = QString("select email from user where username = '%1'").arg(username);
    QSqlQuery query;
    query.exec(qstr1);
    while(query.next())
    {
        if (query.value(0).toString() == email)
        {

            return 1;
        }

    }
    return 0;
}

void DataBase::database_friend_insert(const char* username, const char* friendname){
    QString qstr = QString("insert into friends(username, friendname) values ('%1', '%2')").arg(username).arg(friendname);
    query.exec(qstr);
    QString qstr2 = QString("insert into friends(username, friendname) values ('%1', '%2')").arg(friendname).arg(username);
    query.exec(qstr2);
}

int DataBase::get_friends_num(const char* username){
    QString qstr1 = QString("select count(*) from friends where username = '%1'").arg(username);
    query.exec(qstr1);
    query.next();
    int n = query.value(0).toInt();
    return n;
}


QList<QString> DataBase::get_friendlist(const char* username)
{   // recieve user's name and return his/her all friends as a QList
    QList<QString> friendlist;
    QString qstr2 = QString("select friendname from friends where username = '%1'").arg(username);
    query.exec(qstr2);
    while(query.next())
    {
        friendlist.append(query.value(0).toString());
        //qDebug()<<query.value(0).toString();
    }
    return friendlist;
}
