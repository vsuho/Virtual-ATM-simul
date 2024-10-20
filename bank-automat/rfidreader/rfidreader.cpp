
#include "rfidreader.h"
#include <QDebug>

RFIDReader::RFIDReader(QObject *parent) : QObject(parent), serial(new QSerialPort(this))
{
    setupSerialPort();
}

RFIDReader::~RFIDReader()
{
    if (serial->isOpen()) {
        serial->close();
    }
    delete serial;
}

bool RFIDReader::connectToReader(const QString &portName)
{
    if (serial->isOpen()) {
        serial->close();
    }

    serial->setPortName("COM6");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open port" << portName << serial->errorString();
        emit errorOccurred(serial->errorString());
        return false;
    }
    return true;
}

void RFIDReader::disconnectReader()
{
    if (serial->isOpen()) {
        serial->close();
    }
    emit errorOccurred("Disconnected");
}

void RFIDReader::setupSerialPort()
{
    connect(serial, &QSerialPort::readyRead, this, &RFIDReader::readData);
    connect(serial, &QSerialPort::errorOccurred, this, &RFIDReader::handleError);
}

void RFIDReader::readData()
{
    QByteArray data = serial->readAll();
    qDebug() << "Data received:" << data;
    emit newTagRead(data);
}

void RFIDReader::handleError(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError) {
        qDebug() << "Serial port error:" << serial->errorString();
        emit errorOccurred(serial->errorString());
    }
}
