#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>

extern QString myName;
extern QString serverip;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    static QString myusername;

private slots:
    void on_loginBtn_clicked();
    void on_signBtn_clicked();
    void on_resignButton_clicked();

private:
    Ui::Dialog *ui;
    QTcpSocket* m_tcp;
    std::string recvStr;
    QByteArray recvMsg;

};

#endif // DIALOG_H
