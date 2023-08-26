#ifndef TULINGROBOT_H
#define TULINGROBOT_H

#include<QString>

class TulingRobot
{
public:
    TulingRobot();
    //!!!不需要填入apikey，原因本来使用图灵机器人api
    //! 后面改为了使用青云客api，直接写入在mainwindow的函数中
    //! http://api.qingyunke.com/api.php?key=free&appid=0&msg=" api地址

    const QString API_KEY="";
    const QString URL="";
    QString Tuling_API_URL;


};

#endif // TULINGROBOT_H
