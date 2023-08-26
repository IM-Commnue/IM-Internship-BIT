#ifndef BAIDUVOICE_H
#define BAIDUVOICE_H
//语音识别 语音合成两大功能
//先语音识别，再语音合成
#include<QString>
#include <QJsonDocument>
#include <QJsonParseError>
#include<QUrl>
#include <QtNetwork>
class baiduVoice
{
public:
    baiduVoice();
    //这里要填入你的百度语音apikey secretkey
    const QString API_KEY="";
    const QString Secret_Key="";
    QString Access_Token="";
    //vedio to text
    const QString VOP_URL="http://vop.baidu.com/server_api";
    //Text to vedio
    const QString TSN_URL="http://tsn.baidu.com/text2audio";
    QString Get_Token_URL="https://aip.baidubce.com/oauth/2.0/token";
    QString MAC_cuid="";
//    QJsonObject VOP_append;
private slots:
};

#endif // BAIDUVOICE_H
