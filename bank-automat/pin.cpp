#include "pin.h"
#include "ui_pin.h"
#include <QDebug>
#include <QLineEdit>
#include <QApplication>
#include "environment.h"
#include <QMessageBox>
#include "mainwindow.cpp"
#include "mainmenu.h"




pin::pin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pin)
{
    ui->setupUi(this);

    connect(ui->numero1, &QPushButton::clicked, this, &pin::button_clicked);
    connect(ui->numero2, &QPushButton::clicked, this, &pin::button_clicked);
    connect(ui->numero3, &QPushButton::clicked, this, &pin::button_clicked);
    connect(ui->numero4, &QPushButton::clicked, this, &pin::button_clicked);
    connect(ui->numero5, &QPushButton::clicked, this, &pin::button_clicked);
    connect(ui->numero6, &QPushButton::clicked, this, &pin::button_clicked);
    connect(ui->numero7, &QPushButton::clicked, this, &pin::button_clicked);
    connect(ui->numero8, &QPushButton::clicked, this, &pin::button_clicked);
    connect(ui->numero9, &QPushButton::clicked, this, &pin::button_clicked);
    connect(ui->numero0, &QPushButton::clicked, this, &pin::button_clicked);




    connect(ui->clear, &QPushButton::clicked, this, &pin::clear_clicked);

    connect(ui->enter, &QPushButton::clicked, this, &pin::enter_clicked);

}

pin::~pin()
{
    delete ui;

}


void pin::button_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if (button) {
        QString buttonText = button->text();
        ui->lineEdit->setText(ui->lineEdit->text() + buttonText);
    }
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}



void pin::clear_clicked()
{
    ui->lineEdit->clear(); // Tyhjentää lineeditin
}

void pin::enter_clicked()
{


    qDebug() << "cardNumber" << cardNum;
    QString pin=ui->lineEdit->text();
    qDebug() << pin;
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber",cardNum);
    jsonObj.insert("pin",pin);

    QString site_url= environment::getBaseUrl()+"/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

}
void pin::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();

    //qDebug()<<response_data;
    if(response_data=="-4078" || response_data.length()==0){

        ui->messageLabel->setText("Virhe tietoyhteydessä");
        ui->lineEdit->clear();

    }
    else{
        if(response_data!="false"){
            //kirjautuminen onnistui
            this->close();

            mainmenu *objectMainMenu= new mainmenu(this);
            objectMainMenu->setWebToken(response_data);
            objectMainMenu->setCardNum(cardNum);
            objectMainMenu->idAccount();
            objectMainMenu->show();


        }
        else{

            ui->messageLabel->setText("Kortin numero ja salasana eivät täsmää");
            ui->lineEdit->clear();
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();
}








void pin::setCardNum(const QString &newCardNum)
{
    cardNum = newCardNum;
}
