#include "dialog.h"
#include "sign.h"
#include "ui_dialog.h"
#include "qtmaterialautocomplete.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QDir>
#include <QAction>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //背景图片设置
    ui->Qlabel->setPixmap(QPixmap(":red/02.png"));
    ui->Qlabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->Qlabel->setScaledContents(true);
    //密码眼睛操作实现
    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/eye/closecat.png"));
    int stat = 0;
    connect(ui->pwdLineEdit, &QtMaterialAutoComplete::textEdited, [=]() {
            static bool first = true;
                if (first) {
                            ui->pwdLineEdit->addAction(action, QLineEdit::TrailingPosition);
                            first = false;
                           }
            });

    connect(action, &QAction::triggered, [=, &stat]() {
            if (stat == 0) {
                        action->setIcon(QIcon(":/eye/cat.png"));
                        ui->pwdLineEdit->addAction(action, QLineEdit::TrailingPosition);
                        stat = 1;
                        ui->pwdLineEdit->setEchoMode(QLineEdit::Normal);
                        }
            else
            {
                action->setIcon(QIcon(":/eye/closecat.png"));
                ui->pwdLineEdit->addAction(action, QLineEdit::TrailingPosition);
                stat = 0;
                ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
            }
    });
    //新功能实现区：

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_loginBtn_clicked()
{
    //添加数据库
    QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("im.db");
    //报错信息
    if(!db.open())
    {
        qDebug()<<"open DB error";
        return;
    }
    //创建数据表
    QSqlQuery query;
        query.exec("create table login (id integer primary key autoincrement,\
                    username vchar(32),\
                    password vchar(32))");

        QString username= ui->usrLineEdit->text();
        QString password= ui->pwdLineEdit->text();
        QString qStr=QString("insert into %1 (username,password) values('%2','%3')").arg("login",username,password);
        qDebug()<<qStr;
        query.exec(qStr);

        query.exec("select username, password from login");
        bool isFound=false;
        while(query.next())
        {
            qDebug()<<query.value(0).toString()
                   <<query.value(1).toString();
            qDebug()<<QDir::currentPath();
            if(query.value(0).toString()==username&&query.value(1).toString()==password)
            {
                isFound=true;
            }
        }

        if(isFound)
        {
            QMessageBox::information(NULL, tr("Note"), tr("Login success!"));
               accept();
        }else {
            QMessageBox::warning(this, tr("Waring"),
                                  tr("user name or password error!"),
                                  QMessageBox::Yes);
            // 清空内容并定位光标
            ui->usrLineEdit->clear();
            ui->pwdLineEdit->clear();
            ui->usrLineEdit->setFocus();
         }

    // 判断用户名和密码是否正确，如果错误则弹出警告对话框
//        if(ui->usrLineEdit->text().trimmed() == tr("user")
//               && ui->pwdLineEdit->text() == tr("123"))
//    {
//        QMessageBox::information(NULL, tr("Note"), tr("Login success!"));
//           accept();
//        } else {
//           QMessageBox::warning(this, tr("Waring"),
//                                 tr("user name or password error!"),
//                                 QMessageBox::Yes);
//           // 清空内容并定位光标
//           ui->usrLineEdit->clear();
//           ui->pwdLineEdit->clear();
//           ui->usrLineEdit->setFocus();
//        }
}



void Dialog::on_signBtn_clicked()
{
    sign *s=new sign();
    s->exec();
}
