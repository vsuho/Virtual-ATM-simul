#include "tilinvalinta.h"
#include "ui_tilinvalinta.h"
#include "otto.h"

tilinvalinta::tilinvalinta(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tilinvalinta)
{
    ui->setupUi(this);
}

tilinvalinta::~tilinvalinta()
{
    delete ui;
}

void tilinvalinta::on_debit_clicked()
{
    this->close();
    otto * ottoObject= new otto(this);
    ottoObject->setAccountIds(accountId);
    ottoObject->setWebToken(webToken);
    ottoObject->setCredOrDeb(credOrDeb);
    ottoObject->show();

}


void tilinvalinta::on_credit_clicked()
{
    this->close();
    otto* ottoObject= new otto(this);
    ottoObject->setAccountIds(scndAccountId);
    ottoObject->setWebToken(webToken);
    ottoObject->setCredOrDeb(credOrDeb);
    ottoObject->show();


}


void tilinvalinta::on_takaisin_clicked()
{
    this->close();
}

void tilinvalinta::setAccountIds(const int &newAccountId, const int &scndNewAccountId)
{
    accountId=newAccountId;
    scndAccountId=scndNewAccountId;

}

void tilinvalinta::setWebToken(const QByteArray &newWebToken)
{
    webToken=newWebToken;
}

void tilinvalinta::setCredOrDeb(const int &newCredOrDeb)
{
    credOrDeb=newCredOrDeb;
}
