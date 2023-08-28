#include "widget.h"
#include "dialog.h"
#include "homepage.h"
#include "dialog.h"
#include <QApplication>

QString myName;
QString serverip="192.168.37.134";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Homepage h;
    Dialog dlg;
    if (dlg.exec()==QDialog::Accepted)
        {

           h.show();

           return a.exec();
        }
        else return 0;
    //服务器IP地址 120.0.0.1
    //服务器端口号 8899
    //QString ip = "120.0.0.1";
    //int port = 8899;
    //m_socket->connectToHost(ip, port)

}
