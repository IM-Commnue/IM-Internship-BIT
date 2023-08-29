#include "homepage.h"
#include "dialog.h"
#include "ui_homepage.h"
#include "widget.h"
#include "chat.h"
#include "dialog.h"
#include "addfriend.h"
#include<QPixmap>
#include<QtWidgets>

Homepage::Homepage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Homepage)
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
//            recvStr = recvMsg.toStdString();
            QJsonDocument document=QJsonDocument::fromJson(recvMsg);
            //将接受的数据传给namelist
            QJsonArray array=document.array();
            QList<QVariant>variantList=array.toVariantList();
            namelist.clear();
            for (const QVariant& variant:variantList)
            {
                namelist.append(variant.toString());
            }
        });




}

Homepage::~Homepage()
{
    delete ui;
}



void Homepage::on_chatpushButton_clicked()
{
    chat *c=new chat();
    c->show();
}

void Homepage::on_revise_clicked()
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
        jsonObject["class"] = "friendlist"; // json类型为登录
        jsonObject["myname"] = myName;
        // 创建 JSON 文档
        QJsonDocument jsonDoc(jsonObject);
        // 将 JSON 文档转换为字符串
        QString jsonString = QString::fromUtf8(jsonDoc.toJson());
        // 发送 JSON 字符串
        m_tcp->write(jsonString.toUtf8());
        if(m_tcp->waitForReadyRead())
        {
            qDebug()<<"m_tcp->waitForReadyRead()被触发";
//            recvMsg = m_tcp->readAll();
//            QDataStream stream(&recvMsg,QIODevice::ReadOnly);
//            stream>>Homepage::namelist;
        }
    }

    //好友头像列表
    QStringList imagelist;
    imagelist<<"1"<<"2"<<"3"<<"4"<<"5"<<"6";
//    //好友按钮容器制作
//    QVector<QToolButton*> vector;
    //好友按钮实现
    for(QToolButton *button:vector)
    {
        delete button;
    }
    vector.clear();
    for (int i=0;i<namelist.size();i++) {
        QToolButton *btn=new QToolButton(this);
        //头像设置
        btn->setIcon(QPixmap(QString(":/op/%1.png").arg(imagelist[i])));
        btn->setIconSize(QPixmap(QString(":/op/%1.png").arg(imagelist[0])).size());
        //透明
         btn->setAutoRaise(true);
          //设置网名
         btn->setText(QString("%1").arg(namelist[i]));
         //设置显示格式
         btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
         ui->vlayout->addWidget(btn);
         vector.push_back(btn);
    }

    //判断聊天窗口是否已被打开,若打开则拒绝再次打开的请求
    isShow.push_back(false);
    for (int i=0;i<namelist.size();i++)
    {
        connect(vector[i],&QToolButton::clicked,[=](){
            if(isShow[i])
            {
                QMessageBox::warning(this,"警告","该聊天窗口已被打开！");
                return ;
            }
            //friendName = namelist[i];
            isShow[i]=true;
            Widget *w=new Widget(nullptr,vector[i]->text());
            w->setfriendname(namelist[i]);
            w->setWindowIcon(vector[i]->icon());
            w->setWindowTitle(vector[i]->text());
            w->show();
            //关闭时修改对应的isshow
            connect(w,&Widget::closeWidget,this,[=]()
            {
                isShow[i]=false;
            });
        });
    }

}

void Homepage::on_addButton_clicked()
{
    addfriend *af=new addfriend;
    af->show();
}
