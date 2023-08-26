#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    p_TulingRobot=new TulingRobot();
    //    p_TulingRobot->Tuling_API_URL=p_TulingRobot->URL+"?key="+p_TulingRobot->API_KEY+"&info=";
    p_TulingRobot->Tuling_API_URL=p_TulingRobot->URL;
    p_BaiduVoice=new baiduVoice();
    connect(this,&chat::changeV2T,this,&chat::voice_post_Tuling_slot);
    connect(this,&chat::changeUIANS,this,&chat::Baidu_TextToVoice_replyFinish);
    AudioInit();
    media_player =new QMediaPlayer(this);
    getMacAddress();
    TokenInit();
    //    audio_input=new QAudioInput(JsonBuffer);
}
void chat::AudioInit()
{
    const auto &&availableDevices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    if(!availableDevices.isEmpty())
    {
        SpeechCurrentDevice = availableDevices.first();
        QAudioFormat format;
        format.setSampleRate(8000);
        format.setChannelCount(1);
        format.setSampleSize(16);
        format.setSampleType(QAudioFormat::SignedInt);
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setCodec("audio/pcm");
        audio_input = new QAudioInput(SpeechCurrentDevice, format, this);
    }
}
void chat::TokenInit()
{
    if(JudgeTokenTime()) return;
    QUrl url=QUrl(p_BaiduVoice->Get_Token_URL+
                  "?grant_type=client_credentials"+
                  "&client_id="+p_BaiduVoice->API_KEY+
                  "&client_secret="+p_BaiduVoice->Secret_Key);
    QNetworkAccessManager *manager=new QNetworkAccessManager(this);
    QNetworkRequest request(url);
    //    QJsonObject append;
    connect(manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(get_Token_slot(QNetworkReply *)));
    manager->get(request);
}

void chat::get_Token_slot(QNetworkReply *reply)
{
    QByteArray JsonStr=reply->readAll();
    QJsonObject acceptedData(QJsonDocument::fromJson(JsonStr).object());
    if(acceptedData.contains("access_token"))
    {
        QJsonValue json_value = acceptedData.take("access_token");
        p_BaiduVoice->Access_Token=json_value.toString();
        qDebug()<<"success get token:"<<p_BaiduVoice->Access_Token;
    }
}
chat::~chat()
{
    delete ui;
}

//更改voice_get_ans函数，用于发射信号
void chat::changeBaiduAudioAns(QString str)
{
    this->voice_get_ans=str;
    qDebug()<<"识别声音结果 "<<this->voice_get_ans;
    emit changeV2T();
}

bool chat::JudgeTokenTime()
{
    //https://blog.csdn.net/qq_18286031/article/details/78538769 时间互转连接
    QSettings *setting=new QSettings("GetTokenTime.ini",QSettings::IniFormat);
    //当前时间
    QDateTime current_date_time=QDateTime::currentDateTime();
    QDateTime file_date_time;
    //读取的文件时间
    QString file_date_str=setting->value("/TIME/last_time").toString();
    file_date_time=QDateTime::fromString(file_date_str,"yyyy-MM-dd");
    //    qDebug()<<"file_date_time"<<file_date_time;
    uint stime = file_date_time.toTime_t();
    uint etime = current_date_time.toTime_t();
    int ndaysec = 24*60*60;
    int Day= (etime - stime)/(ndaysec) + ((etime - stime)%(ndaysec)+(ndaysec-1))/(ndaysec) - 1;
    //Token 有效期内
    if(Day<30)    return true;
    else
    {
        //写时间
        setting->beginGroup("TIME");
        setting->setValue("last_time",current_date_time.toString("yyyy-MM-dd"));
        setting->endGroup();
        return false;
    }
}
//更改UI_ANS_String函数，用于发射信号
void chat::setUIString(QString str)
{
    this->UI_ANS_String=str;
    this->ui->OutputTextEdit->setText(str);
    emit changeUIANS();
}

//获取本机MAC地址
void chat::getMacAddress()
{

    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
    int nCnt = nets.count();
    for(int i = 0; i < nCnt; i ++)
    {
        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            p_BaiduVoice->MAC_cuid = nets[i].hardwareAddress();
            break;
        }
    }
    p_BaiduVoice->MAC_cuid.replace(":","-");
    qDebug()<<"自动获取的MAC地址 "<<p_BaiduVoice->MAC_cuid;
}

//获得图灵机器人的回答后再播放这个回答
void chat::Baidu_TextToVoice_replyFinish()
{
    //最后一步 播放文本音频
    //设置url以及必要的请求格式
    QByteArray url="http://tsn.baidu.com/text2audio?";
    url.append(QString("&lan=zh"));
    //本机MAC地址
    //    url.append(QString("&cuid=A0-8C-FD-1D-CF-0E"));
    url.append(QString("&cuid="+p_BaiduVoice->MAC_cuid));
    url.append("&ctp=1");
    url.append(QString("&tok="+p_BaiduVoice->Access_Token));
    url.append(QString("&pit=5"));
    url.append(QString("&per=4"));
    url.append(QString("&tex="));
    url.append(QUrl::toPercentEncoding(this->UI_ANS_String));
    qDebug()<<url;
    //播放url里面的音频
    media_player->setMedia(QUrl::fromLocalFile(url));
    media_player->play();
}

//当声音识别成文本后，发射信号到此函数，然后将文本发送给青云客
void chat::voice_post_Tuling_slot()
{
    qDebug()<<"successes get voice_post_Tuling_slot";
    QString Url="http://api.qingyunke.com/api.php?key=free&appid=0&msg="+this->voice_get_ans;
    QUrl url;
    url.setUrl(Url);
    QNetworkRequest request(url);
    QNetworkAccessManager *manager=new QNetworkAccessManager(this);
    //处理获得文本，连接到voice_Tuling_replyFinish函数
    connect(manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(voice_Tuling_replyFinish(QNetworkReply *)));
    manager->get(request);
}

//直接聊天
void chat::on_SendBtn_clicked()
{

    QString Url="http://api.qingyunke.com/api.php?key=free&appid=0&msg="+ui->InputTextEdit->toPlainText();
    QUrl url;
    url.setUrl(Url);
    QNetworkRequest request(url);
    QNetworkAccessManager *manager=new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(Tuling_replyFinish(QNetworkReply*)));
    manager->get(request);
}

//解析图灵API返回的json数据
void chat::Tuling_replyFinish(QNetworkReply *reply)
{

    QString data=reply->readAll();//读取回话信息
    qDebug()<<"这是返回的结果 "+data;
    QJsonParseError json_error;
    //一定要toUtf8 否则会出错！
    QJsonDocument json=QJsonDocument::fromJson(data.toUtf8(),&json_error);
    //判断有没有错
    if(json_error.error==QJsonParseError::NoError)
    {
        if(json.isObject())
        {
            QJsonObject jsonObj=json.object();
            //取到text内容
            if(jsonObj.contains("content"))
            {
                qDebug()<<"成功获取text";
                QJsonValue text_value=jsonObj.take("content");
                if(text_value.isString())
                {
                    tuling_get_ans=text_value.toVariant().toString();
                    tuling_get_ans.replace("br","\n");
                    qDebug()<<"!!!返回的ans:"<<tuling_get_ans;
                }
            }
        }
    }
    reply->deleteLater();
    ui->OutputTextEdit->setText(tuling_get_ans);

}

//走语音识别的流程 这是将语音识别文本发送给图灵机器人，然后解析json
void chat::voice_Tuling_replyFinish(QNetworkReply *reply)
{

    qDebug()<<"测试走到voice_Tuling_replyFinish...";
    QString data=reply->readAll();//读取回话信息
    qDebug()<<"这是返回的结果 "+data;
    QString tstr;
    QJsonParseError json_error;
    //一定要toUtf8 否则会出错！
    QJsonDocument json=QJsonDocument::fromJson(data.toUtf8(),&json_error);
    //判断有没有错
    if(json_error.error==QJsonParseError::NoError)
    {
        if(json.isObject())
        {
            QJsonObject jsonObj=json.object();
            //取到text内容
            if(jsonObj.contains("content"))
            {
                qDebug()<<"成功获取text";
                QJsonValue text_value=jsonObj.take("content");
                if(text_value.isString())
                {
                    tstr=text_value.toVariant().toString();
                    qDebug()<<"!!!返回的ans:"<<tuling_get_ans;
                }
            }
        }
    }
    reply->deleteLater();
    //    获得返回文本后
    this->setUIString(tstr);
}


//当按下录音按钮后 开始录音
void chat::on_VoiceBtn_pressed()
{
    JsonBuffer=new QBuffer;
    JsonBuffer->open(QIODevice::ReadWrite);
    qDebug()<<"录音设备访问成功...";
    audio_input->start(JsonBuffer);
    qDebug()<<"录音设备运行成功...";
}

//松开按钮后，结束录音，发送请求
void chat::on_VoiceBtn_released()
{
    qDebug()<<"结束录音哦~~~";
    audio_input->stop();
    const auto &sendData=JsonBuffer->data();
    JsonBuffer->deleteLater();
    QNetworkRequest request(QUrl(p_BaiduVoice->VOP_URL));
    request.setRawHeader("Content-Type", "application/json");
    qDebug()<<"jason_speech:request设置头成功 ...";
    QNetworkAccessManager *manager=new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(Baidu_VoiceToText_replyFinish(QNetworkReply *)));
    //这里应该放在百度类里面
    QJsonObject append;
    //设置json请求格式
    append["format"] = "pcm";
    append["rate"] = 8000;
    append["channel"] = 1;
    append["token"] = p_BaiduVoice->Access_Token;
    append["lan"] = "zh";
    //    append["cuid"] = "A0-8C-FD-1D-CF-0E";
    append["cuid"] = p_BaiduVoice->MAC_cuid;
    append["speech"] = QString(sendData.toBase64());
    append["len"] = sendData.size();
    //发送HTTP post请求
    manager->post(request,QJsonDocument(append).toJson());
}

//声音转成文本
void chat::Baidu_VoiceToText_replyFinish(QNetworkReply *reply)
{
    qDebug()<<"进到槽函数了哦~~";
    QByteArray JsonStr=reply->readAll();
    qDebug()<<"返回信息 "<<JsonStr;
    QJsonObject acceptedData(QJsonDocument::fromJson(JsonStr).object());

    if(acceptedData.contains("err_no"))
    {
        QJsonValue version_value = acceptedData.take("err_no");
        if(version_value.isDouble())
        {
            int version = version_value.toVariant().toInt();
            if(version == 3300){
                //                textEdit -> append("错误代码:3300-输入参数不正确,请仔细核对文档及参照demo，核对输入参数");//重新写入文本
            }else if(version == 3301){
                //                textEdit -> append("错误代码:3301-音频质量过差,请上传清晰的音频");//重新写入文本
                QMessageBox::information(NULL,tr("识别失败"),tr("请等待一秒后开始录音，确认录音质量良好"));
            }else if(version == 3302){
                //                textEdit -> append("错误代码:3302-鉴权失败,token字段校验失败。请用appkey 和 app secret生成");//重新写入文本
            }else if(version == 3303){
                //                textEdit -> append("错误代码:3303-转pcm失败,如下2个原因 1. wav amr音频转码失败，即音频有问题。2. 服务端问题，请将api返回结果反馈至论坛或者QQ群");//重新写入文本
            }else if(version == 3304){
                //                textEdit -> append("错误代码:3304-用户的请求QPS超限,请降低识别api请求频率 （qps以appId计算，移动端如果共用则累计）");//重新写入文本
            }else if(version == 3305){
                //                textEdit -> append("错误代码:3305-用户的日pv（日请求量）超限,请“申请提高配额”，如果暂未通过，请降低日请求量");//重新写入文本
            }else if(version == 3307){
                //                textEdit -> append("错误代码:3307-语音服务器后端识别出错问题,请将api返回结果反馈至论坛或者QQ群");//重新写入文本
            }else if(version == 3308){
                //                textEdit -> append("错误代码:3308-音频过长,音频时长不超过60s，请将音频时长截取为60s以下");//重新写入文本
            }else if(version == 3309){
                //                textEdit -> append("错误代码:3309-音频数据问题,服务端无法将音频转为pcm格式，可能是长度问题，音频格式问题等。 请将输入的音频时长截取为60s以下，并核对下音频的编码，是否是8K或者16K， 16bits，单声道。");//重新写入文本
            }else if(version == 3310){
                //                textEdit -> append("错误代码:3310-输入的音频文件过大,语音文件共有3种输入方式： json 里的speech 参数（base64后）； 直接post 二进制数据，及callback参数里url。 分别对应三种情况：json超过10M；直接post的语音文件超过10M；callback里回调url的音频文件超过10M");//重新写入文本
            }else if(version == 3311){
                //                textEdit -> append("错误代码:3311-采样率rate参数不在选项里,目前rate参数仅提供8000,16000两种，填写4000即会有此错误");//重新写入文本
            }else if(version == 3312){
                //                textEdit -> append("错误代码:3312-音频格式format参数不在选项里,目前格式仅仅支持pcm，wav或amr，如填写mp3即会有此错误");//重新写入文本
            }
            //            return;
        }
    }
    if(!acceptedData["result"].isNull())
    {
        QString message=acceptedData["result"].toArray()[0].toString();
        ui->InputTextEdit->setText(message);
        changeBaiduAudioAns(message);
    }
}



