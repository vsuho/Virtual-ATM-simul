#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

    void setWebToken(const QByteArray &newWebToken);
    void setCardNum(const QString &newCardNum);
    void userId();



    void idAccount();
    void setName();
    void setTilinVaihto(const int &newTilinVaihto);
    void setAccountIds(const int &newAccountId,const int &newScndAccountId);


    void getTili();

private slots:
    void on_tilinvalinta_clicked();
    void on_tapahtumat_clicked();
    void on_otto_clicked();
    void on_saldo_clicked();
    void on_stopmenu_clicked();
    void idAccountSlot(QNetworkReply*);
    void userSlot(QNetworkReply*);
    void nameSlot(QNetworkReply*);
    void tiliSlot(QNetworkReply *);



private:
    Ui::mainmenu *ui;
    QNetworkAccessManager *mainManager;
    QNetworkReply *mainReply;
    QNetworkAccessManager *userManager;
    QNetworkReply *userReply;
    QNetworkAccessManager *tiliManager;
    QNetworkReply *tiliReply;
    QNetworkAccessManager *nameManager;
    QNetworkReply *nameReply;
    QByteArray webToken;
    QByteArray main_data;
    int user_data;
    QString cardNum;
    QByteArray tiliData;
    QByteArray userData;
    QString firstAccountNumber;
    QString scndAccountNumber;
    QByteArray name_data;
      int credOrDeb;
      int accountId;
      int scndAccountId;
      int user_Id;
      int chosenAccountId;
      bool tili;


};

#endif // MAINMENU_H
