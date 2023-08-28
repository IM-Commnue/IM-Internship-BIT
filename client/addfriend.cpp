#include "addfriend.h"
#include "ui_addfriend.h"

addfriend::addfriend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addfriend)
{
    ui->setupUi(this);
    // 创建通信的套接字对象
    m_tcp = new QTcpSocket(this);
    //断开潜在的额外连接
    disconnect(m_tcp, &QTcpSocket::readyRead,this,nullptr);
    // 接收服务器发送的数据
    connect(m_tcp, &QTcpSocket::readyRead, [=]()
        {
            recvMsg = m_tcp->readAll();
            recvStr = recvMsg.toStdString();
            if(recvStr.compare("1")==1)
            {
                QMessageBox::information(NULL, tr("Note"), tr("Add friend success!"));
                this->close();
            }
        });
}

addfriend::~addfriend()
{
    delete ui;
}

void addfriend::on_pushButton_clicked()
{
    //连接服务器
    QString ip = serverip;
    int port = 9989;
    if(m_tcp->state()!=QAbstractSocket::ConnectedState)
    {
        m_tcp->connectToHost(QHostAddress(ip), port);
    }
    if(m_tcp->waitForConnected())
    {
        // 创建 JSON 对象并设置用户名和密码字段
        QJsonObject jsonObject;
        jsonObject["class"] = "addfriend"; // json类型为登录
        jsonObject["myname"] = myName;
        jsonObject["friendname"] = ui->lineEdit->text();
        // 创建 JSON 文档
        QJsonDocument jsonDoc(jsonObject);
        // 将 JSON 文档转换为字符串
        QString jsonString = QString::fromUtf8(jsonDoc.toJson());
        // 发送 JSON 字符串
        m_tcp->write(jsonString.toUtf8());
    }
}
