#include "sign.h"
#include "ui_sign.h"
#include "dialog.h"

sign::sign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign)
{
    ui->setupUi(this);
//.cpp
    //gif图片qmovie加载
    static QMovie *gifMovie=new  QMovie(":/op/she.webp");
    ui->Qlabel->setMovie(gifMovie);
    gifMovie->setScaledSize(QSize(ui->Qlabel->width(),ui->Qlabel->height()));
    gifMovie->start();
    ui->Qlabel->show();
    if(gifMovie->isValid())
    {
        qDebug()<<"movie is valid.";
    }else
    {
        qDebug()<<"movie is not valid.";
    }
//    //图片背景设置
//        QPalette pa(this->palette());
//        QImage img = QImage(":/red/02.png");
//        img = img.scaled(this->size());
//        QBrush *pic = new QBrush(img);
//        pa.setBrush(QPalette::Window,*pic);
//        //this->setAutoFillBackground(true);
//        this->setPalette(pa);
}

sign::~sign()
{
    delete ui;
}

void sign::on_cancelbutton_clicked()
{
    this->close();
}

void sign::on_confirmbutton_clicked()
{
    //两次密码是否相同的判断
    if(ui->codelineEditit->text()!=ui->codelineEdit_2->text())
    {
        QMessageBox::warning(this,tr("Waring"),tr("Twont passwords entered are different!"),QMessageBox::Yes);
        return;
    }
    //数据库连接:(暂时为空)

}
