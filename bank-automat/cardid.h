#ifndef CARDID_H
#define CARDID_H
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


class CardId
{
    Q_OBJECT
public:
    CardId(QString Card, QByteArray webToken);
private slots:
    void cardSlot(QNetworkReply *cardReply);
private:
    QNetworkAccessManager *cardManager;
    QNetworkReply *cardReply;
    QString Card;
    QByteArray webtoken;

};

#endif // CARDID_H
