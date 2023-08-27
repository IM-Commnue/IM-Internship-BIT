#ifndef SIGN_H
#define SIGN_H
#include <QMessageBox>
#include <QDialog>
#include <QDebug>
#include <QMovie>

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
};

#endif // SIGN_H
