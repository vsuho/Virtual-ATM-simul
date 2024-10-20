#ifndef OTTO_H
#define OTTO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class otto;
}

class otto :public QDialog
{
    Q_OBJECT

public:
    explicit otto(QWidget *parent = nullptr);
    ~otto();

    void setWebToken(const QByteArray &newWebToken);

    void setAccountIds(const int &newAccountId);
    void otto_clickHandler();
    void setCredOrDeb(const int &newCredOrDeb );

private slots:

    void on_otto20_clicked();
    void on_otto40_clicked();
    void on_otto60_clicked();
    void on_otto90_clicked();
    void on_otto140_clicked();
    void on_otto240_clicked();
    void on_alkuun_clicked();
    void ottoSlot(QNetworkReply *reply);

private:
    Ui::otto *ui;
    QNetworkAccessManager *ottoManager;
    QNetworkReply *ottoReply;
    int response_data;
    QByteArray webToken;
    int accountId;
    int scndAccountId;
    int maara;
    int credOrDeb;

};

#endif // OTTO_H
