#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QMessageBox>

class DataBase{
public:
    QSqlDatabase db;
    QSqlQuery query;

    DataBase();
    ~DataBase();

    void database_tabal_creat(QString sql_statement);
    void connect_database(const char* database_name);
    void disconnect_database();
    bool database_tabal_exist(const char* tabal_name);
    //登录注册
    void insert_user_group();
    bool database_username_repetition(const char* username);
    bool password_correct(const char s[]);
    bool mail_correct(const char s[]);
    void database_username_insert(const char* username,const char* password, const char* mail);
    void database_password_insert(const char* password);
    int database_password_equal_login(const char* username, const char* password);
    bool login(const char* username, const char* password);
    QString database_all_print();
    QString give_key_back(const char* username);
    int database_find_key_by_email(const char* username, const char* email);
    //好友数据库
    /*QString sql = ("create table %1 (friendname varchar(50) primary key)").arg(username);*/
    int get_friends_num(const char* username);
    void database_friend_insert(const char* username, const char* friendname);
    QString* get_friendlist(const char* username, int friendnum);

    //群聊数据库


};

#endif // DATABASE_H
