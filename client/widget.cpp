#include "widget.h"
#include "dialog.h"
#include "ui_widget.h"
#include "homepage.h"
#include "file.h"
#include <QTimer>





Widget::Widget(QWidget *parent ,QString name)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建通信的套接字对象
    m_tcp = new QTcpSocket(this);
    //断开潜在的额外连接
    disconnect(m_tcp, &QTcpSocket::readyRead,this,nullptr);
    //建立连接
    QString ip = serverip;
    int port = 9989;
    if(m_tcp->state()!=QAbstractSocket::ConnectedState)
    {
        m_tcp->connectToHost(QHostAddress(ip), port);
    }

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

//    this->udpSocket=new QUdpSocket(this);//套接字

//    connect(m_tcp, &QTcpSocket::connected, [=]() {
//        qDebug() << "Connected to server";
//    });
// 接收服务器发送的数据
    connect(m_tcp, &QTcpSocket::readyRead, [=]()
        {
            recvMsg = m_tcp->readAll();
            document=QJsonDocument::fromJson(recvMsg);
            object=document.object();
            file_message_class=object["class"].toString();
            if(file_message_class.compare("pmsg")==0)
            {
//                recvStr = recvMsg.toStdString();
                qStr=object["says_what"].toString();//QString::fromStdString(recvStr);
                qDebug()<<"qStr："<<qStr;
                QString whosays=object["who_says"].toString();
                ui->textBrowser->insertPlainText(whosays+":"+ qStr + "\n");
            }else if(file_message_class.compare("file")==0)
            {
                //接受文件
//                QJsonDocument recvfileDocument=QJsonDocument::fromJson(recvMsg);
                if (!document.isNull())
                {
//                    QJsonObject test2=test1.object();
                    QString dataBase64 = object["data"].toString();
                    QByteArray fileData = QByteArray::fromBase64(dataBase64.toUtf8());
                    QString savePath = QFileDialog::getSaveFileName(this, tr("Save File"), "");
                    QFile File(savePath);
                    if (File.open(QIODevice::WriteOnly))
                    {
                    File.write(fileData);
                    File.close();
                    qDebug() << "Photo saved to" << savePath;
                    } else {
                    qDebug() << "Error saving photo";
                    }} else {
                    qDebug() << "Invalid JSON data received";
                    }
            }else
            {
                qDebug()<<"file_message_class.compare(pmsg)"<<file_message_class.compare("pmsg");
                qDebug()<<"file_message_class.compare(file)"<<file_message_class.compare("file");
                qDebug()<<"error";
            }

        });
    //绑定发送
//    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(sendData()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::setfriendname(QString n)
{
    friendname=n;
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

void Widget::on_tableWidget_customContextMenuRequested(const QPoint &pos)//暂时无用代码
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
    if(sendStr.isEmpty())
    {
        QMessageBox::warning(this,tr("Waring"),tr("Text is empty!"),QMessageBox::Yes);
        return;
    }
    ui->textBrowser->insertPlainText("自己："+sendStr+"\n");
    //检查发送消息内容
    qDebug()<<"sendData str"<<sendStr;
    //建立连接
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
        //friendname = "123456";//text!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //填写 JSON 文档
        jsonObject["class"] = "pmsg"; // json类型为聊天
        jsonObject["username"] = friendname; // friendname
        jsonObject["myname"] = myName; //myname
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
//        if(m_tcp->waitForReadyRead())
//        {
//            qDebug()<<"m_tcp->waitForReadyRead()被触发";
//            recvMsg = m_tcp->readAll();
//            recvStr = recvMsg.toStdString().c_str();
//            qStr=QString::fromStdString(recvStr);
//            ui->textBrowser->insertPlainText("friend：" + qStr + "\n");
//            qDebug()<<"recvStr："<<qStr;
//        }

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

void Widget::on_sendToolBtn_clicked()//文件发送按钮
{
    //发送文件
    if(m_tcp->waitForConnected())
    {
    qDebug() << "Connected to send the file.";
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Select a file to send");
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
          qDebug() << "Failed to open the file.";
          return;
    }
    //读取文件姓名和大小
    QString file_name = file.fileName();
    qint64 file_size = file.size();
    const qint64 BlockSize = 512;

//            QByteArray fileData = file.readAll();
//            file.close();
            //friendname="123465";//！！！！！！！！！！！！！！！！！
            //填写 JSON 对象
            QJsonObject jsonObject;
            jsonObject["class"] = "file";
            jsonObject["who_sent"]=myName;
            jsonObject["to_whom"]=friendname;
            //jsonObject["filename"] = file.fileName();
            //！！！！！
            //jsonObject["data"] = QString(fileData.toBase64());
            //分块新加
            jsonObject["file_size"] = static_cast<double>(file_size);
            // 创建 JSON 文档
            QJsonDocument jsonDocument(jsonObject);
            QByteArray jsonData = jsonDocument.toJson();
//            //发送文件
//            m_tcp->write(jsonData);
            //发送文件信息
            qDebug()<<jsonDocument.toJson();
            // 将 JSON 文档转换为字符串
            QString jsonString = QString::fromUtf8(jsonDocument.toJson());
            m_tcp->write(jsonString.toUtf8());
            //发送文件数据块
            QByteArray buffer;
            qint64 bytesRemaining = file_size;

            //声明计时器变量
            QTimer timer;
            while (bytesRemaining > 0)
            {
                timer.start(20);
                buffer = file.read(qMin(static_cast<qint64>(BlockSize), bytesRemaining));
                m_tcp->write(buffer);
                bytesRemaining -= buffer.size();

            }
            //文件发送判断
            qDebug() << "File sent.";
            file.close();
    }else {
    qDebug()<<"sent fail";
}
//    file *f=new file();
//    f->show();
}

void Widget::on_pushButton_8_clicked()
{
    QString sendStr=ui->textEdit->toPlainText();


        if(m_tcp->waitForConnected())
        {
        // 创建 JSON 对象并设置用户名和密码字段
        QJsonObject jsonObject;
        //friendname = "123456";//test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //填写 JSON 文档
        jsonObject["class"] = "pmsg"; // json类型为聊天
        jsonObject["username"] = friendname; // friendname
        jsonObject["myname"] = myName; //myname
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
//        if(m_tcp->waitForReadyRead())
//        {
//            qDebug()<<"m_tcp->waitForReadyRead()被触发";
//            recvMsg = m_tcp->readAll();
//            recvStr = recvMsg.toStdString().c_str();
//            qStr=QString::fromStdString(recvStr);
//            ui->textBrowser->insertPlainText("friend：" + qStr + "\n");
//            qDebug()<<"recvStr："<<qStr;
//        }
        }

}
