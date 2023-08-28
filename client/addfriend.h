#ifndef ADDFRIEND_H
#define ADDFRIEND_H
#include "dialog.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class addfriend;
}

class addfriend : public QDialog
{
    Q_OBJECT

public:
    explicit addfriend(QWidget *parent = nullptr);
    ~addfriend();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addfriend *ui;
    QTcpSocket* m_tcp;
    std::string recvStr;//接受数据信息->qstring类型
    QByteArray recvMsg;//接受数据信息
};

#endif // ADDFRIEND_H
