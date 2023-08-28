#include "dialog.h"
#include "sign.h"
#include "ui_dialog.h"
#include "widget.h"
#include "qtmaterialautocomplete.h"
#include "database.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QDir>
#include <QAction>
#include <QMovie>
#include <QString>

QString myusername;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // 创建通信的套接字对象
    m_tcp = new QTcpSocket(this);
//    //gif图片qmovie加载
//    static QMovie *gifMovie=new  QMovie(":/op/001.webp");
//    ui->Qlabel->setMovie(gifMovie);
//    gifMovie->setScaledSize(QSize(ui->Qlabel->width(),ui->Qlabel->height()));
//    gifMovie->start();
//    ui->Qlabel->show();
//    if(gifMovie->isValid())
//    {
//        qDebug()<<"movie is valid.";
//    }else
//    {
//        qDebug()<<"movie is not valid.";
//    }
    //背景图片设置
    ui->Qlabel->setPixmap(QPixmap(":red/02.png"));
    ui->Qlabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->Qlabel->setScaledContents(true);
    //密码眼睛操作实现
    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/eye/closecat.png"));
    int stat = 0;
    //密码输入时尾部加入一个眼睛操作按钮
    connect(ui->pwdLineEdit, &QtMaterialAutoComplete::textEdited, [=]() {
            static bool first = true;
                if (first) {
                            ui->pwdLineEdit->addAction(action, QLineEdit::TrailingPosition);
                            first = false;
                           }
            });
    // 接收服务器发送的数据
//    connect(m_tcp, &QTcpSocket::readyRead, [=]()
//        {
//            recvMsg = m_tcp->readAll();
//            recvStr = recvMsg.toStdString();
//        });

    //密码眼睛图片
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
    QString username = ui->usrLineEdit->text();
    QString password = ui->pwdLineEdit->text();
    myName=username;
    //连接服务器
    QString ip = "172.20.10.8";
    int port = 9989;
    m_tcp->connectToHost(QHostAddress(ip), port);

    // 创建 JSON 对象并设置用户名和密码字段
    QJsonObject jsonObject;
    jsonObject["class"] = "log"; // json类型为登录
    jsonObject["username"] = username;
    jsonObject["password"] = password;

    // 创建 JSON 文档
    QJsonDocument jsonDoc(jsonObject);

    // 将 JSON 文档转换为字符串
    QString jsonString = QString::fromUtf8(jsonDoc.toJson());

    // 发送 JSON 字符串
    m_tcp->write(jsonString.toUtf8());
    // 接收服务器发送的数据
    connect(m_tcp, &QTcpSocket::readyRead, [=]()
        {
            recvMsg = m_tcp->readAll();
            recvStr = recvMsg.toStdString();
        });
    //中间信息检测
    QString qstr = QString::fromStdString(recvStr);
    qDebug() << qstr;
    if(recvStr.compare("1") == 0)
    {
        QMessageBox::information(NULL, tr("Note"), tr("Login success!"));
           accept();
    }else if(recvStr.compare("0") == 0) {
        QMessageBox::warning(this, tr("Waring"),
                              tr("user name or password error!"),
                              QMessageBox::Yes);        // 清空内容并定位光标
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
     }
}



void Dialog::on_signBtn_clicked()
{
    sign *s=new sign();
    s->exec();
}

void Dialog::on_resignButton_clicked()
{

}
