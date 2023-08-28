#include "widget.h"
#include "dialog.h"
#include "ui_widget.h"
#include "homepage.h"
#include <QTextCharFormat>
#include <QMessageBox>
#include <QDateTime>
#include <QMovie>
#include <QJsonDocument>



Widget::Widget(QWidget *parent ,QString name)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建通信的套接字对象
    m_tcp = new QTcpSocket(this);
//    //gif图片qmovie加载
//    static QMovie *gifMovie=new  QMovie(":/op/wenxin.webp");
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
//    // 假设 onlineUsers 是一个 QVector 或 QList 存储在线用户信息的数据结构
//        onlineUsers << "User1" << "User2" << "User3";
    myname=name; //friendname
    this->udpSocket=new QUdpSocket(this);//套接字
    //允许其他服务器连接到相同的地址和端口

    // 接收服务器发送的数据
    connect(m_tcp, &QTcpSocket::connected, [=]() {
        qDebug() << "Connected to server";
    });

    connect(m_tcp, &QTcpSocket::readyRead, [=]()
        {
            recvMsg = m_tcp->readAll();
            QString recvStr = QString::fromUtf8(recvMsg);
            ui->textBrowser->insertPlainText("friend：" + recvStr + "\n");
            qDebug()<<"sendData str"<<recvStr;
        });
    //绑定发送
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(sendData()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()// 设置字体加粗
{
    QTextCursor cursor = ui->textEdit->textCursor(); // 获取当前文本编辑器的光标

    if (!cursor.hasSelection()) {
        return; // 如果没有选中文本，直接返回
    }

    QTextCharFormat format; // 创建字符格式对象
    format.setFontWeight(QFont::Bold); // 设置字体加粗

    cursor.mergeCharFormat(format); // 应用格式到选中的文本
    ui->textEdit->mergeCurrentCharFormat(format); // 保持后续文本的格式一致
}

void Widget::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{
//    // 获取当前在线用户信息（假设已经从数据源获取）
//    QVector<QString> onlineUsers = getOnlineUsers(); // 从某个数据源获取在线用户信息

//    // 清空表格内容
//    ui->tableWidget->clearContents();

//    // 设置表格的行数
//    ui->tableWidget->setRowCount(onlineUsers.size());

//    // 填充表格
//    for (int i = 0; i < onlineUsers.size(); ++i) {
//        QTableWidgetItem *item = new QTableWidgetItem(onlineUsers[i]);
//        ui->tableWidget->setItem(i, 0, item);
//    }

//    // 在指定位置显示上下文菜单
//    QMenu contextMenu(this);
//    contextMenu.addAction("Some Action");
//    contextMenu.exec(ui->tableWidget->mapToGlobal(pos));
}

void Widget::closeEvent(QCloseEvent *)
{
    emit this->closeWidget();
}

void Widget::on_exitpushButton_clicked()
{
    this->close();
}

void Widget::sendData()
{
    QString sendStr=ui->textEdit->toPlainText();
    ui->textBrowser->insertPlainText("自己："+sendStr+"\n");
    qDebug()<<"sendData str"<<sendStr;
        QString ip = "172.20.10.8";
        int port = 9989;
        m_tcp->connectToHost(QHostAddress(ip), port);
        QJsonObject jsonObject;
        myname = "123";
        QString myusername = "123456";
        jsonObject["class"] = "pmsg"; // json类型为聊天
        jsonObject["username"] = myname; // friendname
        jsonObject["myname"] = myusername; //myname
        jsonObject["message"] = sendStr;
        // 创建 JSON 文档
        QJsonDocument jsonDoc(jsonObject);

        // 将 JSON 文档转换为字符串
        QString jsonString = QString::fromUtf8(jsonDoc.toJson());

        // 发送 JSON 字符串
        m_tcp->write(jsonString.toUtf8());
        //中间信息检测
        QString qstr = QString::fromStdString(recvStr);
        qDebug() << qstr;
    if(sendStr.isEmpty())
    {
        QMessageBox::warning(this,tr("Waring"),tr("Text is empty!"),QMessageBox::Yes);
        return;
    }
}

//新一代代码编写区

//void Widget::userEnter(QString username)
//{

//}

//void Widget::userLeft(QString username, QString time)
//{

//}

//void Widget::sndMsg(Widget::Msgtype type)
//{
//    QByteArray array;
//    //创建流
//    QDataStream stream(&array,QIODevice::WriteOnly);
//    stream<<type<<this->getName();
//    switch (type)
//    {
//        case Msg:
//        if(this->ui->textEdit->toPlainText()=="")
//        {
//            QMessageBox::warning(this,"Warrning","发送内容不能为空");
//            return;
//        }
//        stream<<this->getMsg();
//        break;
//    case UserEnter:
//        break;
//    case UserLeft:
//        break;
//    }
//    //书写报文
//    udpSocket->writeDatagram(array.data(), array.size(), QHostAddress::Broadcast, this->port);
//}

//QString Widget::getName()
//{
//    return this->myname;
//}

//QString Widget::getMsg()
//{
//    QString msg=ui->textEdit->toHtml();
//    ui->textEdit->clear();
//    ui->textEdit->setFocus();
//    return msg;
//}

//void Widget::ReceiveMessage()
//{
//    qint64 size=udpSocket->pendingDatagramSize();
//    //qint64变int
//    int mysize=static_cast<int>(size);
//    QByteArray array=QByteArray(mysize,0);
//    udpSocket->readDatagram(array.data(),size);
//    QDataStream stream(&array,QIODevice::ReadOnly);
//    int msgtype;
//    stream>>msgtype;//读取类型
//    QString name,msg;//用户名和聊天信息
//    QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

//    switch (msgtype)
//    {
//        case Msg://普通聊天
//        stream>>name>>msg;//导出姓名和聊天内容
//        //增加聊天记录
//        ui->textBrowser->setTextColor(Qt::blue);
//        ui->textBrowser->setCurrentFont(QFont("Times New Roman",12));
//        ui->textBrowser->append("["+name+"]"+time);
//        ui->textBrowser->append(msg);
//        break;
//    case UserEnter:
//        stream>>name;
////        userEnter(name);
//        break;
//    case UserLeft:
//        stream>>name;
////        userLeft(name,time);
//        break;
//    }
//}
void Widget::on_underlineToolBtn_clicked()
{
    QTextCursor cursor=ui->textEdit->textCursor();
    if (!cursor.hasSelection()) {
        return; // 如果没有选中文本，直接返回
    }
    QTextCharFormat format;
    format.setFontUnderline(true);

    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}
