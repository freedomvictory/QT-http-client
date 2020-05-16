#include "my_http_client.h"
#include <iostream>


my_http_client::my_http_client(QObject *parent) : QObject(parent)
{
    this->manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
}

//client send get request
void my_http_client::get(const QUrl &url)
{
    this->manager->get(QNetworkRequest(url));
}

//client receive reply
void my_http_client::replyFinished(QNetworkReply *response)
{

    std::cout << "replyFinished: resp = " << response << std::endl;

    deleteLater();  // later relate response
}


my_http_client::~my_http_client()
{
    delete this->manager;
}
