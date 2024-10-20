#include "cardid.h"
#include "environment.h"

CardId::CardId(QString Card,QByteArray webToken) {
    QString site_url=environment::getBaseUrl()+"/card/getId/"+Card;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    cardManager = new QNetworkAccessManager(this);

    connect(cardManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(cardSlot(QNetworkReply*)));

    cardReply = cardManager->get(request);

}
void CardId::cardSlot(QNetworkReply *cardReply)
{

}
