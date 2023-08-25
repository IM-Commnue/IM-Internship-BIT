#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QDialog>
#include <QUdpSocket>
#include <QtWidgets>
#include <QtNetwork>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class chat;
}
QT_END_NAMESPACE
class chat : public QDialog
{
    Q_OBJECT

public:
    chat(QWidget *parent ,QString name);
    ~chat();

private slots:
    void on_pushButton_clicked();
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);
    void on_exitpushButton_clicked();
    void sendData();
    void onSendButtonClicked();
    void handleAPIResponse(QNetworkReply *reply);
private:
    Ui::chat *ui;

    QString myname;
    void setupUi();
    void connectToApi();
};

#endif // CHAT_H
