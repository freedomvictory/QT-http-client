#ifndef MY_HTTP_CLIENT_H
#define MY_HTTP_CLIENT_H


/*create by victory, time: 2020/05/16
This file define a simple httpclient class,support basic http request
*/

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
class QNetworkAccessManager;
class QNetworkReply;
QT_END_NAMESPACE

class my_http_client : public QObject
{
    Q_OBJECT

public:
    explicit my_http_client(QObject *parent = Q_NULLPTR);

    ~my_http_client();      //destructor

public:
    void sendGetReqest(const QUrl &url);


private:
    QNetworkAccessManager *manager;


private slots:
    void replyFinshed(QNetworkReply* );

};

#endif // MY_HTTP_CLIENT_H

