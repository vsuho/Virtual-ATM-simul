#include "saldo.h"
#include "ui_saldo.h"
#include "QMessageBox"

saldo::saldo(QWidget *parent)
    : QDialog(parent), ui(new Ui::saldo), TManager(new QNetworkAccessManager(this)) {
    ui->setupUi(this);
    connect(ui->lopeta, &QPushButton::clicked, this, &saldo::on_lopeta_clicked);
}

saldo::~saldo() {
    delete ui;
}



void saldo::setWebToken(const QByteArray &newWebToken) {
    webToken = newWebToken;
}

void saldo::setIdAccount(const int &newIdAccount)
{
    idAccount=newIdAccount;
}

void saldo::getSaldo() {

    QString acc=QString::number(idAccount);
    QString site_url ="http://localhost:3000/account/balance/"+acc;
    QNetworkRequest request(site_url);

    QByteArray myToken ="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    TManager = new QNetworkAccessManager(this);
    connect(TManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(SaldoSlot(QNetworkReply*)));

    reply=TManager->get(request);

}


void saldo::on_lopeta_clicked() {

    this->close();

}

void saldo::SaldoSlot(QNetworkReply *reply) {
    QByteArray response_data = reply->readAll();

    QJsonDocument jsonDoc=QJsonDocument::fromJson(response_data);
    QJsonArray json_array=jsonDoc.array();

    QString balance= json_array.at(0)["balance"].toString();
    qDebug()<<balance;


    ui->tilinsaldo->setText(balance);
    reply->deleteLater();
    qDebug()<<response_data;


}
