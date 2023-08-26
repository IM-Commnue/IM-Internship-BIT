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

    enum Msgtype{Msg,UserRnter,UserLeft};
    void sndMsg(Msgtype type);
    QString getName();
    QString getMsg();
    void userEnter();
    void userLeft();
    void ReceiveMessage();

    //重写关闭事件
    void closeEvent(QCloseEvent *);
signals:
    void closeWidget();

private slots:
    void on_pushButton_clicked();
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);
    void on_exitpushButton_clicked();
    void sendData();

private:
    Ui::Widget *ui;

    QString myname;
    quint16 port;//端口
    QUdpSocket *udpSocket;//udp 套接字

protected:

};
#endif // WIDGET_H
