#ifndef MY_HTTP_CLIENT_H
#define MY_HTTP_CLIENT_H


/*create by victory, time: 2020/05/16
This file define a simple httpclient class,support basic http request
*/

#include <QObject>
#include <QNetworkAccessManager>

class my_http_client : public QObject
{
    Q_OBJECT
public:
    explicit my_http_client(QObject *parent = Q_NULLPTR);

    ~my_http_client();      //destructor

public:
    void get(const QUrl &url);

private:
    QNetworkAccessManager *manager;

signals:

public slots:
    void replyFinished(QNetworkReply* response);
};

#endif // MY_HTTP_CLIENT_H
