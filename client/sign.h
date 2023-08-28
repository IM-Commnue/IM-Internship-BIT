#ifndef SIGN_H
#define SIGN_H
#include <QMessageBox>
#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class sign;
}

class sign : public QDialog
{
    Q_OBJECT

public:
    explicit sign(QWidget *parent = nullptr);
    ~sign();

private slots:
    void on_cancelbutton_clicked();

    void on_confirmbutton_clicked();

private:
    Ui::sign *ui;
    QTcpSocket* m_tcp;
    std::string recvStr;
    QByteArray recvMsg;
};

#endif // SIGN_H
