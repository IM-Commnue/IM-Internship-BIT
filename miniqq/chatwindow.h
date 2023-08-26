#ifndef CHATWINDOW_H
#define CHATWINDOW_H
#include <QtWidgets>
#include <QtNetwork>

class ChatWindow:public QMainWindow
{
public:
    ChatWindow(QWidget *parent=nullptr):QMainWindow(parent){
        setupUi();
        connectToApi();
    }
private slots:
    void onSendButtonClicked() {
                QString message = inputTextEdit->toPlainText();
                // Send the message to the chat server or API

                // Append the user's message to the chat display
                chatDisplayTextEdit->append("You: " + message);
                inputTextEdit->clear();
        }
    void handleAPIResponse(QNetworkReply *reply) {
                if (reply->error() == QNetworkReply::NoError)
                {
                     QString response = reply->readAll();
                     // Parse the response to extract the chat content

                     // Append the chat content to the chat display
                     chatDisplayTextEdit->append(response);
                 } else {
                     qDebug() << "API request error: " << reply->errorString();
                 }
                     reply->deleteLater();
                 }
private:
    void setupUi(){
        chatDisplayTextEdit=new QTextEdit(this);
        chatDisplayTextEdit->setreadOnly(ture);

        inputTextEdit=new QTexxtEdit(this);
        inputTextEdit->setPlaceholderText("Type your message...");

        sendButton=new QPushButton(this);
        cnonect(sendButton, &QPushButton::clicked, this,&ChatWindow::onSendButtonClicked);

        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(chatDisplayTextEdit);
        layout->addWidget(inputTextEdit);
        layout->addWidget(sendButton);

        QWidget* cenralidget = new QWidget(thtWis);
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);
    }
    void connectToApi()
    {
        QNetessManagerworkAcc* manager = new QNetworkAccessManager(this);
        QNetworkRequest request(QUrl("YOUR_API_URL_HERE"));

        QNetworkReply* reply = manager->get(request);
        connect(reply, &QNetworkReply::finished, this,[=]() { handleAPIResponse(reply); });
    }
   Et* QTextEdit* chatDisplayTextdi;
   QTextEdit inputTextEdit;
   QPushButton* sendButton;
};

#endif // CHATWINDOW_H
