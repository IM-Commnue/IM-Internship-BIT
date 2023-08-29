#ifndef WIDGET_H
#define WIDGET_H



#include<string>
#include<QString>
#include <QWidget>
#include <QDialog>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QFileDialog>
#include <QTextCharFormat>
#include <QMessageBox>
#include <QDateTime>
#include <QMovie>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent ,QString name);
    ~Widget();
    void setfriendname(QString n);
    enum Msgtype{Msg,UserEnter,UserLeft};
    void sndMsg(Msgtype type);//广播udp信息
    QString getName();//获取昵称
    QString getMsg();//获取聊天信息
    void userEnter();//处理用户输入
    void userLeft();//处理用户离开
    void ReceiveMessage();//接受udp信息

    //重写关闭事件
    void closeEvent(QCloseEvent *);
signals:
    void closeWidget();

private slots:
    void on_pushButton_clicked();
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);
    void on_exitpushButton_clicked();
    void sendData();

    void on_underlineToolBtn_clicked();

    void on_sendToolBtn_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *m_socket;//TCP客户端对象
    QUdpSocket *udpSocket;//udp 套接字
    QTcpSocket* m_tcp;
    std::string recvStr;
    QString qStr;
    QByteArray recvMsg;
    QString m_host = "120.0.0.1"; //服务器IP地址
    int m_port = 8899; //服务器端口号
    QString friendname;
    QJsonDocument document;
    QJsonObject object;
    QString file_message_class;
protected:

};
#endif // WIDGET_H
