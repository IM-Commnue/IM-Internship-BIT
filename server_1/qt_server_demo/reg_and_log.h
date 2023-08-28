#ifndef REG_AND_LOG_H
#define REG_AND_LOG_H

#include "QJsonObject"
#include "database.h"
#include "QFile"

class reg_and_log
{
public:
    DataBase db;

    int register_(QJsonObject jso) const
    {   // check whether the info are ok
        // if correct, insert into database and return 1
        QString acc_qstr = jso["username"].toString();
        const char* acc = acc_qstr.toStdString().c_str();
        QString key_qstr = jso["password"].toString();
        const char* key = key_qstr.toStdString().c_str();
        QString eml_qstr = jso["mail"].toString();
        const char* eml = eml_qstr.toStdString().c_str();
        bool acc_ok, key_ok, eml_ok;
        DataBase db;
        acc_ok = db.database_username_repetition(acc);
        key_ok = db.password_correct(key);
        eml_ok = db.mail_correct(eml);
        qDebug()<<acc_ok<<key_ok<<eml_ok;
        if(acc_ok == 1 && key_ok == 1)
        {
            db.database_username_insert(acc, key, eml);
            return 1;
        }
        else return 0;
    }

    int login_check(QJsonObject jso) const
    {   // check if account and key are both right
        // if so, return 1
        QString acc_qstr = jso["username"].toString();
        const char* acc = acc_qstr.toStdString().c_str();
        qDebug()<<acc;
        QString key_qstr = jso["password"].toString();
        const char* key = key_qstr.toStdString().c_str();
        int res;
        qDebug()<<acc<<key;
        DataBase db;
        res = db.database_password_equal_login(acc, key);
        return res;
    }

    QString find_your_key(QJsonObject jso) const
    {   // check if account and email are both right
        // if so, return 1
        QString acc_qstr = jso["username"].toString();
        const char* acc = acc_qstr.toStdString().c_str();
        QString eml_qstr = jso["mail"].toString();
        const char* eml = eml_qstr.toStdString().c_str();
        int res;
        DataBase db;
        res = db.database_find_key_by_email(acc, eml);
        QString key_real;
        if(res == 1) key_real = db.give_key_back(acc);
        else key_real = QString("username or email is wrong");
        return key_real;
    }


};

#endif // REG_AND_LOG_H
