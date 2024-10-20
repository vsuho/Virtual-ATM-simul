#ifndef PIN_H
#define PIN_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class pin;
}

class pin : public QDialog
{
    Q_OBJECT

public:



    explicit pin(QWidget *parent = nullptr);
    ~pin();

    void setCardNum(const QString &newCardNum);

    void getAccountId();
    void getCardid();
private slots:

    void button_clicked();
    void clear_clicked();
    void enter_clicked();
    void loginSlot(QNetworkReply *reply);




private:
    Ui::pin *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QNetworkAccessManager *accManager;
    QNetworkReply *accreply;
    QNetworkAccessManager *cardManager;
    QNetworkReply *cardreply;
    QByteArray response_data;
    QString accountId;
    QString cardNum;


};

#endif // PIN_H
