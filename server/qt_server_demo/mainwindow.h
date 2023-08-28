#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLabel>
#include <cstring>
#include <QJsonDocument>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTcpSocket *m_tcp;

private slots:
    void on_setListen_clicked();

    void on_sendMsg_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *m_s;
    QLabel *m_status;
};
#endif // MAINWINDOW_H
