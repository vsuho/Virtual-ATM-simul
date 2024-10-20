#include "mainwindow.h"
#include "transactions.h"
#include "pin.h"
#include "mainmenu.h"
#include <QApplication>
#include <QTableView>
#include "tilinvalinta.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainWindow w;
    w.show();



    // w.show();



    return a.exec();
}
