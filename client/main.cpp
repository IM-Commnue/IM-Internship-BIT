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

}
