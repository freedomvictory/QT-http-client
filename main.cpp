#include <QCoreApplication>
#include "my_http_client.h"


/*this is a sample http client, create it by victory*/
/*time is 2020:05:16*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    my_http_client pClient;
    pClient.sendGetReqest(QUrl("http://127.0.1.1:8888/index.html"));


    return a.exec();
}
