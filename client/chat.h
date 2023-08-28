#ifndef chat_H
#define chat_H
#include <QDialog>
#include <QMainWindow>
#include <tulingrobot.h>
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>
#include<QAudioInput>
#include<QMediaPlayer>
#include<baiduvoice.h>
#include<QMessageBox>
#include<QTime>
#include<QSettings>
#include<QTcpSocket>

namespace Ui {
class chat;
}

class chat : public QDialog
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = 0);
    TulingRobot *p_TulingRobot;
    baiduVoice *p_BaiduVoice;
    QString TulingURL;
    QMediaPlayer* media_player;
    QAudioDeviceInfo SpeechCurrentDevice;
    QAudioInput* audio_input=NULL;
    QBuffer* JsonBuffer=NULL;
    void setUIString(QString str);
    void AudioInit();
    void TokenInit();
    void getMacAddress();
    void changeBaiduAudioAns(QString str);
    bool JudgeTokenTime();
    ~chat();
signals:
    void changeV2T();
    void changeUIANS();
public slots:
    //直接文字识别
    void Tuling_replyFinish(QNetworkReply* reply);
    //语音识别过程获得回答
    void voice_Tuling_replyFinish(QNetworkReply* reply);
    //识别声音获得文字
    void Baidu_VoiceToText_replyFinish(QNetworkReply* reply);
    void get_Token_slot(QNetworkReply* reply);
    //文本转语音槽函数
    void Baidu_TextToVoice_replyFinish();
    //获得声音后
    void voice_post_Tuling_slot();
//    void get_Answer_Set_UI();
private slots:
    void on_SendBtn_clicked();

    void on_VoiceBtn_pressed();

    void on_VoiceBtn_released();

private:
    //显示文本
    QString tuling_get_ans;
    QString voice_get_ans;
    QString UI_ANS_String;
    Ui::chat *ui;
    QTcpSocket* m_tcp;
};

#endif // chat_H
