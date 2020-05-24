#include "my_http_client.h"
#include <QDebug>
#include <QTextCodec>

my_http_client::my_http_client(QObject *parent)
    :  QObject(parent)
{
    this->manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &my_http_client::replyFinshed);
}

//client send get request
void my_http_client::sendGetReqest(const QUrl &url)
{

   this->manager->get(QNetworkRequest(url));

}

//QNetworkReply send a finished siganl
//function replyFinished recv it and handle it
void my_http_client::replyFinshed(QNetworkReply* reply)
{
    qDebug() << "httpFinished:  " << reply;
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QString all = codec->toUnicode(reply->readAll());
    qDebug() << all;

    reply->deleteLater();
    reply = Q_NULLPTR;


}


my_http_client::~my_http_client()
{
    delete this->manager;
}
