#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    reader(new RFIDReader(this)),
    //  networkManager(new QNetworkAccessManager(this)),
    pinDialog(nullptr)
{
    ui->setupUi(this);
    connect(reader, &RFIDReader::newTagRead, this, &MainWindow::displayTagId);

    if(!reader->connectToReader("COM3"))
    {

    }


}

MainWindow::~MainWindow()
{
    delete ui;
    delete reader;

    delete pinDialog;
}

void MainWindow::displayTagId(const QString &tagId)
{

    QString cleanedTagId = tagId;
    cleanedTagId.remove('-');
    cleanedTagId.remove(("\\s"));
    cleanedTagId.remove('>');
    cleanedTagId = cleanedTagId.trimmed();
    qDebug() << "cleaned" << cleanedTagId;
    openPin(cleanedTagId);

}

void MainWindow::openPin(QString cardN)
{


        this->close();
        pinDialog = new pin(this);
        pinDialog->setCardNum(cardN);
        pinDialog->setModal(true);
        pinDialog->show();


}

