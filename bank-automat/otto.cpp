#include "otto.h"
#include "ui_otto.h"
#include "environment.h"
#include "QMessageBox"

otto::otto(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::otto)
{
    ui->setupUi(this);
}

otto::~otto()
{
    delete ui;
}

void otto::on_otto20_clicked()
{
    maara=20;
    otto_clickHandler();
}


void otto::on_otto40_clicked()
{
    maara=40;
    otto_clickHandler();
}



void otto::on_otto60_clicked()
{
    maara=60;
    otto_clickHandler();
}




void otto::on_otto90_clicked()
{
    maara=90;
    otto_clickHandler();
}




void otto::on_otto140_clicked()
{
    maara=140;
    otto_clickHandler();
}



void otto::on_otto240_clicked()
{
    maara=240;
    otto_clickHandler();
}



void otto::on_alkuun_clicked()
{
    this->close();

}

void otto::ottoSlot(QNetworkReply *ottoReply)
{
    response_data=ottoReply->readAll().toInt();
    qDebug()<<response_data;
    int affectedRows = response_data;
    qDebug()<<affectedRows;
    QMessageBox msgBox;
    if(affectedRows==0)
    {
        this->close();
        msgBox.setText("Olet köyhä");
        msgBox.exec();


    }
    else{
        QString num= QString::number(maara);
        this->close();
        msgBox.setText("Nostit: "+num+" euroa");
        msgBox.exec();

    }
    ottoReply->deleteLater();
    ottoManager->deleteLater();

}

void otto::setAccountIds(const int &newAccountId)
{
    accountId = newAccountId;

}

void otto::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void otto::otto_clickHandler()
{
    double amount= maara;
    QString transType="nosto";

    if(credOrDeb==1)
    {

    QJsonObject jsonObj;

    jsonObj.insert("id_account", accountId);
    jsonObj.insert("amount", amount);
    jsonObj.insert("transactionType", transType);
    qDebug()<<jsonObj;
    QString site_url=environment::getBaseUrl()+"/debit";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));



    ottoManager = new QNetworkAccessManager(this);
    connect(ottoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(ottoSlot(QNetworkReply*)));

    ottoReply = ottoManager->post(request, QJsonDocument(jsonObj).toJson());


    }
    else{


    QJsonObject jsonObj;
        jsonObj.insert("id_account", accountId);
        jsonObj.insert("credit_limit",3000);
        jsonObj.insert("amount", amount);
        jsonObj.insert("transactionType", transType);
        QString site_url=environment::getBaseUrl()+"/credit";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray myToken="Bearer "+webToken;
        request.setRawHeader(QByteArray("Authorization"),(myToken));



        ottoManager = new QNetworkAccessManager(this);
        connect(ottoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(ottoSlot(QNetworkReply*)));

        ottoReply = ottoManager->post(request, QJsonDocument(jsonObj).toJson());
    }







}

void otto::setCredOrDeb(const int &newCredOrDeb)
{
    credOrDeb=newCredOrDeb;

}


