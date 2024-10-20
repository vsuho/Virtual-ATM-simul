#ifndef TILINVALINTA_H
#define TILINVALINTA_H

#include <QDialog>

namespace Ui {
class tilinvalinta;
}

class tilinvalinta : public QDialog
{
    Q_OBJECT

public:
    explicit tilinvalinta(QWidget *parent = nullptr);
    ~tilinvalinta();

    void setAccountIds(const int &newAccountId, const int &scndNewAccountId);
    void setWebToken(const QByteArray &newWebToken);
    void setCredOrDeb(const int &newCredOrDeb);
private slots:
    void on_debit_clicked();

    void on_credit_clicked();

    void on_takaisin_clicked();

private:
    Ui::tilinvalinta *ui;
    int accountId;
    int scndAccountId;
    int credOrDeb;
    QByteArray webToken;
};

#endif // TILINVALINTA_H
