#include "sign.h"
#include "ui_sign.h"
#include "dialog.h"
#include "database.h"
#include <QDebug>
#include <QString>
#include <QMovie>

sign::sign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign)
{
    ui->setupUi(this);
    m_tcp = new QTcpSocket(this);
    //gif图片qmovie加载
    static QMovie *gifMovie=new  QMovie(":/op/she.webp");
    ui->Qlabel->setMovie(gifMovie);
    gifMovie->setScaledSize(QSize(ui->Qlabel->width(),ui->Qlabel->height()));
    gifMovie->start();
    ui->Qlabel->show();
    if(gifMovie->isValid())
    {
        qDebug()<<"movie is valid.";
    }else
    {
        qDebug()<<"movie is not valid.";
    }
//    //图片背景设置
        QPalette pa(this->palette());
        QImage img = QImage(":/red/02.png");
        img = img.scaled(this->size());
        QBrush *pic = new QBrush(img);
        pa.setBrush(QPalette::Window,*pic);
        //this->setAutoFillBackground(true);
        this->setPalette(pa);

        // 接收服务器发送的数据
    connect(m_tcp, &QTcpSocket::readyRead, [=]()
            {
                recvMsg = m_tcp->readAll();
                recvStr = recvMsg.toStdString();
            });

}

sign::~sign()
{
    delete ui;
}

void sign::on_cancelbutton_clicked()
{
    this->close();
}

void sign::on_confirmbutton_clicked()
{
    QString username = ui->usernamelineEdit->text();
    QString mail = ui->lineEdit->text();
    QString password = ui->codelineEditit->text();
    QString password_confirm = ui->codelineEdit_2->text();
    //连接服务器
    QString ip = serverip;
    int port = 9989;
    m_tcp->connectToHost(QHostAddress(ip), port);

    // 创建 JSON 对象并设置用户名和密码字段
    QJsonObject jsonObject;
    jsonObject["class"] = "sign"; // json类型为注册
    jsonObject["username"] = username;
    jsonObject["mail"] = mail;
    jsonObject["password"] = password;

    // 创建 JSON 文档
    QJsonDocument jsonDoc(jsonObject);

    // 将 JSON 文档转换为字符串
    QString jsonString = QString::fromUtf8(jsonDoc.toJson());

    // 发送 JSON 字符串
    m_tcp->write(jsonString.toUtf8());
    QString qstr = QString::fromStdString(recvStr);
    //中间信息检测
    qDebug() << qstr;
    qDebug()<<username<<mail<< password<< password_confirm;
    if(recvStr.compare("1") == 0)
    {
        QMessageBox::warning(this,tr("错误"),tr(
                                 "该用户名已被注册"),
                                 QMessageBox::Yes);
        return;
     }
    DataBase database;
    database.connect_database("test.db");
    if(!database.database_tabal_exist("user")){
            database.database_tabal_creat("create table user(\
                                              username varchar(50) primary key,\
                                              password varchar(50),\
                                              mail varchar(50),\
                                              nickname varchar(50))");
    }



    if (!database.mail_correct(mail.toStdString().c_str())){
        QMessageBox::warning(this,tr("错误"),tr("邮箱格式有误"), QMessageBox::Yes);
        return;
    }
    if(password!=password_confirm)
    {
        QMessageBox::warning(this,tr("错误"),tr("两次输入密码不一致！"),QMessageBox::Yes);
        return;
    }
    QString nickname = NULL;
    database.database_username_insert(this,"user",username.toStdString().c_str(),
                                      password.toStdString().c_str(),mail.toStdString().c_str(),
                                      nickname.toStdString().c_str());
    QMessageBox::warning(this,tr("正确"),tr("注册成功"),QMessageBox::Yes);

    database.disconnect_database();

    this->close();

}
