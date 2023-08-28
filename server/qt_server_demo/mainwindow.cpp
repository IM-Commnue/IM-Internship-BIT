#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "reg_and_log.h"
#include "QMap"
#include "QMapIterator"
#include "cstring"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->port->setText("9989");
    setWindowTitle("Server");

    m_s = new QTcpServer(this);


    //
    connect(m_s, &QTcpServer::newConnection, this, [=]()
    {

        m_tcp = m_s->nextPendingConnection();
        m_status->setText("OK");
        ui->record->append("Client connect");
        reg_and_log ral;
        //QString ts = QString("nothing");
        //ts = ral.db.database_all_print();
        //ui->record->append(ts);

        //
        connect(m_tcp, &QTcpSocket::readyRead, this, [=]()
        {
            QByteArray data = m_tcp->readAll();
            QMap <QTcpSocket*, QString> clients;
            // change:
            QJsonDocument jsd = QJsonDocument::fromJson(data);
            //QFile file("data.json");
            //    if (file.open(QIODevice::WriteOnly)) {
            //        file.write(jsd.toJson());
            //        file.close();
            //    }
            QJsonObject jso = jsd.object();
            if(jso["class"].toString() == QString("log"))
            {
                int flag = ral.login_check(jso);

                ui->record->append(jso["username"].toString());
                ui->record->append(jso["password"].toString());

                if(flag == 0)
                {
                   m_tcp->write("0");
                    ui->record->append("account and key are wrong");
                }
                else if(flag == 1)
                {
                    m_tcp->write("1");
                    ui->record->append("account and key are right");
                    QString name = jso["username"].toString();
                    clients.insert(m_tcp, name);
                }

            }
            else if(jso["class"].toString() == QString("sign"))
            {
                int flag = ral.register_(jso);
                ui->record->append(jso["username"].toString());
                ui->record->append(jso["password"].toString());
                ui->record->append(jso["mail"].toString());
                if(flag == 1)
                {
                    m_tcp->write("1");
                    ui->record->append("register successfully");
                }
                else if(flag == 0)
                {
                    m_tcp->write("0");
                    ui->record->append("register failed");
                }
            }
            else if(jso["class"].toString() == QString("back"))
            {
                QString key;
                key = ral.find_your_key(jso);
                m_tcp->write(key.toStdString().c_str());
            }
            else if(jso["class"].toString() == QString("pmsg"))
            {
                QString name_talk_to = jso["username"].toString();
                QString who_says = jso["myname"].toString();
                QString msg = jso["message"].toString();
                for(QTcpSocket* tcp : clients.keys())
                {
                    if(clients.value(tcp) == name_talk_to)
                    {
                        std::string name = who_says.toStdString();
                        std::string text = msg.toStdString();
                        std::string send = name + ":\n" + text;
                        tcp->write(send.c_str());
                    }
                }
            }
                // ui->record->append("Client says:\n" + data);
        });

        connect(m_tcp, &QTcpSocket::disconnected, this, [=]()
        {
            m_tcp->close();
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
    DataBase database;
    database.query.exec("SELECT * FROM user");
    while (database.query.next()) {
        QString username = database.query.value(0).toString();
        QString password = database.query.value(1).toString();
        qDebug() << "Username: " << username << ", Password: " << password;
        ui->record->append(username);
        ui->record->append(password);
    }
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("test.db");

        // 打开数据库
        db.open();

        // 执行 SQL 查询
        QSqlQuery query;
        query.exec("SELECT * FROM user");

        // 遍历查询结果
        while (query.next()) {
            QString username = query.value(0).toString();
            QString password = query.value(1).toString();
            qDebug() << "Username: " << username << ", Password: " << password;
            ui->record->append(username);
            ui->record->append(password);
        }

        // 关闭数据库
        db.close();*/



}

void MainWindow::on_sendMsg_clicked()
{
    QString m = ui->msg->text();
    m_tcp->write(m.toUtf8());
    ui->record->append("Server says:\n" + m);
}
