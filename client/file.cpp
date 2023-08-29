#include "file.h"
#include "ui_file.h"
#include "dialog.h"
#include <QFileDialog>

file::file(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::file)
{
    ui->setupUi(this);
    //连接服务器
    QString ip = serverip;
    int port = 9989;
    m_tcp->connectToHost(QHostAddress(ip), port);
        if (!m_tcp->waitForConnected())
        {
           qDebug() << "Failed to connect to the server.";
        }
}

file::~file()
{
    delete ui;
}

void file::on_pushButton_clicked()
{
//    filePath=ui->lineEdit->text();
    filePath = QFileDialog::getOpenFileName(nullptr, "Select a file to send");
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
          qDebug() << "Failed to open the file.";
    }
        QByteArray fileData = file.readAll();
            file.close();
            QJsonObject jsonObject;
            jsonObject["filename"] = file.fileName();
            jsonObject["data"] = QString(fileData.toBase64());
            QJsonDocument jsonDocument(jsonObject);
            QByteArray jsonData = jsonDocument.toJson();
            m_tcp->write(jsonData);
            m_tcp->disconnectFromHost();
            qDebug() << "File sent.";
    this->close();
}
