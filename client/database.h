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
    void connect_database(const char* database_name);
    void disconnect_database();
    bool database_tabal_exist(const char* tabal_name);
    void database_tabal_creat(QString sql_statement);
    bool database_username_repetition(const char* username);
    bool password_correct(const char s[]);
    bool mail_correct(const char s[]);
    void database_username_insert(QWidget* qw, const char* tabal_name, const char* username,
                                  const char* password, const char* mail, const char* nickname);
    void database_password_insert(const char* password);
    void database_password_equal_login(QWidget* qw, const char* username, const char* password);
    bool login(const char* username, const char* password);
};

#endif // DATABASE_H
