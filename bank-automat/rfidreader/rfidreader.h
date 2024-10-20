#ifndef RFIDREADER_H
#define RFIDREADER_H

#include "rfidreader_global.h"
#include <QObject>
#include <QSerialPort>

class RFIDREADER_EXPORT RFIDReader : public QObject
{
    Q_OBJECT
public:
    explicit RFIDReader(QObject *parent = nullptr);
    ~RFIDReader();

    bool connectToReader(const QString &portName);
    void disconnectReader();

signals:
    void newTagRead(const QString &tagId);
    void errorOccurred(const QString &error);

private:
    QSerialPort *serial;
    void setupSerialPort();

private slots:
    void readData();
    void handleError(QSerialPort::SerialPortError error);
};

#endif
