#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->port->setText("6666");
    setWindowTitle("Server");

    //
    m_s = new QTcpServer(this);

    //
    connect(m_s, &QTcpServer::newConnection, this, [=]()
    {
        QTcpSocket* tcp = m_s->nextPendingConnection();
        m_status->setText("OK");

        //
        connect(m_tcp, &QTcpSocket::readyRead, this, [=]()
        {
            QByteArray data = tcp->readAll();
            ui->record->append("Client says:\n" + data);
        });

        connect(m_tcp, &QTcpSocket::disconnected, this, [=]()
        {
            m_tcp->close();
            m_tcp->deleteLater();
            m_status->setText("NO");
        });
    });

    //
    m_status = new QLabel;
    m_status->setText("NO");
    ui->statusbar->addWidget(new QLabel("Connection:"));
    ui->statusbar->addWidget(m_status);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_setListen_clicked()
{
    unsigned short p = ui->port->text().toUShort();
    m_s->listen(QHostAddress::Any, p);
    ui->setListen->setDisabled(true);
}

void MainWindow::on_sendMsg_clicked()
{
    QString m = ui->msg->text();
    m_tcp->write(m.toUtf8());
    ui->record->append("Server says:\n" + m);
}
