#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QDialog>
#include <QTcpSocket>
#include<QToolButton>

namespace Ui {
class Homepage;
}

class Homepage : public QDialog
{
    Q_OBJECT

public:
    explicit Homepage(QWidget *parent = nullptr);
    ~Homepage();



private slots:
    void on_chatpushButton_clicked();
    void on_revise_clicked();

    void on_addButton_clicked();

private:
    Ui::Homepage *ui;
    QVector<bool> isShow;//判断聊天窗口是否打开
    QTcpSocket* m_tcp;
    std::string recvStr;//接受数据信息->qstring类型
    QByteArray recvMsg;//接受数据信息
    QList<QString> namelist;//好友姓名列表
    QVector<QToolButton*> vector;//好友按钮容器
};

#endif // HOMEPAGE_H
