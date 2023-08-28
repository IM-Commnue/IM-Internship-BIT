#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "reg_and_log.h"
#include "QMap"
#include "QMapIterator"
#include "cstring"
#include "QJsonArray"

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

        QTcpSocket* m_tcp = m_s->nextPendingConnection();
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
                    clients_online.insert(m_tcp, name);
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
                ui->record->append(name_talk_to);
                ui->record->append(who_says);
                ui->record->append(msg);
                for(QTcpSocket* tcp : clients_online.keys())
                {
                    if(clients_online.value(tcp) == name_talk_to)
                    {
                        ui->record->append("find the person wanna talk to");
                        ui->record->append(name_talk_to);
                        std::string name = who_says.toStdString();
                        std::string text = msg.toStdString();
                        std::string send = name + ":\n" + text;
                        tcp->write(send.c_str());
                        ui->record->append(QString(send.c_str()));
                    }
                }
            }
            else if(jso["class"].toString() == QString("addfriend"))
            {
                QString user_qstr = jso["myname"].toString();
                const char* user = user_qstr.toStdString().c_str();
                QString user_friend_qstr = jso["friendname"].toString();
                const char* user_friend = user_friend_qstr.toStdString().c_str();
                DataBase db;
                db.database_friend_insert(user, user_friend);
                ui->record->append("new friends relationship has been stored");
                m_tcp->write("1");
            }
            else if(jso["class"].toString() == QString("friendlist"))
            {
                QString user = jso["myname"].toString();
                ui->record->append("a requirement for friendlist");
                DataBase db;
                QList<QString> friends = db.get_friendlist(user.toStdString().c_str());
                QJsonArray friend_list_json;
                for(QString one_friend : friends)
                {
                    friend_list_json.append(one_friend);
                    ui->record->append(one_friend);
                }
                QJsonDocument fri_json_doc(friend_list_json);
                QByteArray friend_list_send = fri_json_doc.toJson();
                m_tcp->write(friend_list_send);
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
        //DataBase db;

        /* 打开数据库
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
        */


}

void MainWindow::on_sendMsg_clicked()
{

}
