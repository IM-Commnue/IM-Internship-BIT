#ifndef FEIL_H
#define FEIL_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class file;
}

class file : public QDialog
{
    Q_OBJECT

public:
    explicit file(QWidget *parent = nullptr);
    ~file();

private slots:
    void on_pushButton_clicked();

private:
    Ui::file *ui;
    QTcpSocket* m_tcp;
    QString filePath;
};

#endif // FEIL_H
