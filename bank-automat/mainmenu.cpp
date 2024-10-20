#include "ui_mainmenu.h"
#include "mainmenu.h"
#include "transactions.h"
#include "ui_transactions.h"
#include "otto.h"
#include "saldo.h"
#include "environment.h"
#include "QDebug"
#include "tilinvalinta.h"
#include "mainwindow.h"
#include "QMessageBox"


mainmenu::mainmenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;


}




void mainmenu::on_tilinvalinta_clicked()
{
    if(credOrDeb==2)
    {
        if(tili==true)
        {
            tili=false;
            ui->tililabel->setText(firstAccountNumber);
        }
       else
        {
            tili=true;
            ui->tililabel->setText(scndAccountNumber);
        }

    }
    else{
        ui->label_3->setText("Sinulla on vain yksi tili");
    }


}



void mainmenu::on_tapahtumat_clicked()
{




    if(tili==true)
    {


        transactions *objectTransactions= new transactions(this);
        objectTransactions->setAccountId(scndAccountId);
        objectTransactions->setWebToken(webToken);
        objectTransactions->getTransactions();
        objectTransactions->show();

    }
    if(tili==false)
    {
        transactions *objectTransactions= new transactions(this);
        objectTransactions->setAccountId(accountId);
        objectTransactions->setWebToken(webToken);
        objectTransactions->getTransactions();
        objectTransactions->show();
    }



    qDebug()<<tili;

    ui->label_3->clear();


}


void mainmenu::on_otto_clicked()
{

    if(credOrDeb==2)
    {

        tilinvalinta *tiliObject= new tilinvalinta(this);
        tiliObject->setAccountIds(accountId,scndAccountId);
        tiliObject->setWebToken(webToken);
        tiliObject->show();

    }
    else{

    otto *ottoObject =new otto(this);
    ottoObject->setWebToken(webToken);
    ottoObject->setAccountIds(accountId);
    ottoObject->setCredOrDeb(credOrDeb);
    ottoObject->show();
    }
     ui->label_3->clear();
}


void mainmenu::on_saldo_clicked()
{
    if(tili==false)
    {
    saldo *saldoDialog = new saldo(this);
    saldoDialog->setWebToken(webToken);
    saldoDialog->setIdAccount(accountId);
    saldoDialog->getSaldo();
    saldoDialog->exec();
    }
    if(tili==true)
    {
        saldo *saldoDialog = new saldo(this);
        saldoDialog->setWebToken(webToken);
        saldoDialog->setIdAccount(scndAccountId);
        saldoDialog->getSaldo();
        saldoDialog->exec();
    }
     ui->label_3->clear();

}


void mainmenu::on_stopmenu_clicked()
{

    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

}
void mainmenu:: idAccount()
{
    QString site_url="http://localhost:3000/card/getId/"+cardNum;
    QNetworkRequest request((site_url));
    qDebug()<<cardNum;
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    mainManager = new QNetworkAccessManager(this);

    connect(mainManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(idAccountSlot(QNetworkReply*)));

    mainReply = mainManager->get(request);

}

void mainmenu::idAccountSlot(QNetworkReply *mainReply)
{
    main_data=mainReply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(main_data);
    QJsonArray json_array = json_doc.array();
    qDebug()<<json_array;
     credOrDeb=json_array.size();
     accountId=json_array.at(0)["id_account"].toInt();
     scndAccountId=json_array.at(1)["id_account"].toInt();


    qDebug()<<accountId;
    qDebug()<<credOrDeb;
    qDebug()<<scndAccountId;
    userId();

    mainReply->deleteLater();
    mainManager->deleteLater();




}

void mainmenu::setCardNum(const QString &newCardNum)
{
    cardNum= newCardNum;
}


void mainmenu::setWebToken(const QByteArray &newWebToken)
{
    webToken=newWebToken;
}

void mainmenu::userId()
{
    QString acc= QString::number(accountId);
    QString site_url="http://localhost:3000/account/"+acc;
    QNetworkRequest request((site_url));
    qDebug()<<accountId;
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    userManager = new QNetworkAccessManager(this);

    connect(userManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(userSlot(QNetworkReply*)));

    userReply = userManager->get(request);


}
void mainmenu::userSlot(QNetworkReply* userReply)
{
    user_data=userReply->readAll().toInt();


    user_Id=user_data;
    tili=false;
    qDebug()<<"userId slotissa:"<<user_Id;


    setName();
    userReply->deleteLater();
    userManager->deleteLater();




}
void mainmenu::setName()
{
    QString user=QString::number(user_Id);
    QString site_url="http://localhost:3000/user/"+user;
    QNetworkRequest request((site_url));
    qDebug()<<user_Id;
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    nameManager = new QNetworkAccessManager(this);

    connect(nameManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nameSlot(QNetworkReply*)));

    nameReply = nameManager->get(request);



}
void mainmenu:: nameSlot(QNetworkReply*)
{
    name_data=nameReply->readAll();
    qDebug()<<name_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(name_data);
    QJsonArray json_array = json_doc.array();
    QString name=json_array.at(0)["fname"].toString();
    ui->NameLabel->setText("Hei "+name);

    getTili();


}
void mainmenu::getTili()
{
    QString user=QString::number(user_Id);
    QString site_url="http://localhost:3000/account/user/"+user;
    QNetworkRequest request((site_url));
    qDebug()<<user_Id;
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    tiliManager = new QNetworkAccessManager(this);

    connect(tiliManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(tiliSlot(QNetworkReply*)));

    tiliReply = tiliManager->get(request);
}

void mainmenu::tiliSlot(QNetworkReply *tiliReply)
{
    tiliData=tiliReply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(tiliData);
    QJsonArray json_array = json_doc.array();
    firstAccountNumber=json_array.at(0)["accountNumber"].toString();
    scndAccountNumber=json_array.at(1)["accountNumber"].toString();

    ui->tililabel->setText(firstAccountNumber);




}


