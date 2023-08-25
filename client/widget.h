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

private slots:
    void on_pushButton_clicked();
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);
    void on_exitpushButton_clicked();
    void sendData();

private:
    Ui::Widget *ui;

    QString myname;

protected:

};
#endif // WIDGET_H
