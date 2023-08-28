#include "addfriend.h"
#include "ui_addfriend.h"

addfriend::addfriend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addfriend)
{
    ui->setupUi(this);
}

addfriend::~addfriend()
{
    delete ui;
}
