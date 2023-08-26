#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialog>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent ,QString name);
    ~Widget();

    enum Msgtype{Msg,UserEnter,UserLeft};
    void sndMsg(Msgtype type);//广播udp信息
    QString getName();//获取昵称
    QString getMsg();//获取聊天信息
    void userEnter(QString username);//处理用户输入
    void userLeft(QString username,QString time);//处理用户离开
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

private:
    Ui::Widget *ui;

    QString myname;
    quint16 port;//端口
    QUdpSocket *udpSocket;//udp 套接字

protected:

};
#endif // WIDGET_H
