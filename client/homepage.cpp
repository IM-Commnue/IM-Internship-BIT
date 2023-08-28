#include "homepage.h"
#include "ui_homepage.h"
#include "widget.h"
#include "chat.h"
#include<QToolButton>
#include<QPixmap>
#include<QtWidgets>

Homepage::Homepage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Homepage)
{
    QVector<QToolButton*> vector;
    ui->setupUi(this);
    //好友列表
    QList<QString> namelist;
    namelist<<"mycc"<<"wty"<<"fy"<<"eet"<<"xhr";
    //好友头像列表
    QStringList imagelist;
    imagelist<<"1"<<"2"<<"3"<<"4"<<"5"<<"6";
    //好友按钮实现
    for (int i=0;i<namelist.size();i++) {
        QToolButton *btn=new QToolButton(this);
        //头像设置
        btn->setIcon(QPixmap(QString(":/op/%1.png").arg(imagelist[i])));
        btn->setIconSize(QPixmap(QString(":/op/%1.png").arg(imagelist[0])).size());
        //透明
         btn->setAutoRaise(true);
          //设置网名
         btn->setText(QString("%1").arg(namelist[i]));
         //设置显示格式
         btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
         ui->vlayout->addWidget(btn);
         vector.push_back(btn);
         isShow.push_back(false);
    }
    //判断聊天窗口是否已被打开
    for (int i=0;i<namelist.size();i++)
    {
        connect(vector[i],&QToolButton::clicked,[=](){
            if(isShow[i])
            {
                QMessageBox::warning(this,"警告","该聊天窗口已被打开！");
                return ;
            }
            //friendName = namelist[i];
            isShow[i]=true;
            Widget *w=new Widget(nullptr,vector[i]->text());
            w->setWindowIcon(vector[i]->icon());
            w->setWindowTitle(vector[i]->text());
            w->show();
            //关闭时修改对应的isshow
            connect(w,&Widget::closeWidget,this,[=]()
            {
                isShow[i]=false;
            });
        });

    }


}

Homepage::~Homepage()
{
    delete ui;
}



void Homepage::on_chatpushButton_clicked()
{
    chat *c=new chat();
    c->show();
}
