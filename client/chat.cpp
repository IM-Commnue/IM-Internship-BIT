#include "chat.h"
#include "ui_chat.h"
#include "homepage.h"
#include <QTextCharFormat>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QMainWindow>

chat::chat(QWidget *parent ,QString name) :
    QDialog(parent),
    ui(new Ui::chat)
{
    setupUi();
    connectToApi();
    ui->setupUi(this);
    //    // 假设 onlineUsers 是一个 QVector 或 QList 存储在线用户信息的数据结构
    //        onlineUsers << "User1" << "User2" << "User3";
    myname=name;

    //绑定发送
    connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(sendData()));
}

chat::~chat()
{
    delete ui;
}

void chat::onSendButtonClicked() {
            QString message = ui->textEdit->toPlainText();
            // Send the message to the chat server or API

            // Append the user's message to the chat display
            ui->textBrowser->append("You: " + message);
            ui->textEdit->clear();
    }

void chat::handleAPIResponse(QNetworkReply *reply) {
            if (reply->error() == QNetworkReply::NoError)
            {
                 QString response = reply->readAll();
                 // Parse the response to extract the chat content

                 // Append the chat content to the chat display
                 ui->textBrowser->append(response);
             } else {
                 qDebug() << "API request error: " << reply->errorString();
             }
                 reply->deleteLater();
             }

void chat::setupUi(){
    ui->textBrowser=new QTextBrowser(this);
    ui->textBrowser->setReadOnly(true);

    ui->textEdit=new QTextEdit(this);
    ui->textEdit->setPlaceholderText("Type your message...");

    ui->sendButton=new QPushButton(this);
    //cnonect(ui->sendButton, &QPushButton::clicked, this,&chat::onSendButtonClicked);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(ui->textBrowser);
    layout->addWidget(ui->textEdit);
    layout->addWidget(ui->sendButton);

}
void chat::connectToApi()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("YOUR_API_URL_HERE"));

    QNetworkReply* reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this,[=]() { handleAPIResponse(reply); });
}

void chat::on_pushButton_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor(); // 获取当前文本编辑器的光标

    if (!cursor.hasSelection()) {
        return; // 如果没有选中文本，直接返回
    }

    QTextCharFormat format; // 创建字符格式对象
    format.setFontWeight(QFont::Bold); // 设置字体加粗

    cursor.mergeCharFormat(format); // 应用格式到选中的文本
    ui->textEdit->mergeCurrentCharFormat(format); // 保持后续文本的格式一致
}

void chat::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{
//    // 获取当前在线用户信息（假设已经从数据源获取）
//    QVector<QString> onlineUsers = getOnlineUsers(); // 从某个数据源获取在线用户信息

//    // 清空表格内容
//    ui->tableWidget->clearContents();

//    // 设置表格的行数
//    ui->tableWidget->setRowCount(onlineUsers.size());

//    // 填充表格
//    for (int i = 0; i < onlineUsers.size(); ++i) {
//        QTableWidgetItem *item = new QTableWidgetItem(onlineUsers[i]);
//        ui->tableWidget->setItem(i, 0, item);
//    }

//    // 在指定位置显示上下文菜单
//    QMenu contextMenu(this);
//    contextMenu.addAction("Some Action");
//    contextMenu.exec(ui->tableWidget->mapToGlobal(pos));
}

void chat::on_exitpushButton_clicked()
{
    this->close();
}

void chat::sendData()
{
    QString sendStr=ui->textEdit->toPlainText();
    ui->textBrowser->insertPlainText("自己："+sendStr+"\n");
    qDebug()<<"sendData str"<<sendStr;
    if(sendStr.isEmpty())
    {
        QMessageBox::warning(this,tr("Waring"),tr("Text is empty!"),QMessageBox::Yes);
        return;
    }
}
