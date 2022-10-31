#include "mainwindow.h"

#include <QApplication>
#include "connection.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Connection c;
    bool connect;
    connect=c.connect();

    if(connect)
    {
    w.show();
    QMessageBox::information(nullptr,QObject::tr("Data base is open"),
                             QObject::tr("Connexion successful\nClick cancel to exit")
                             ,QMessageBox::Cancel);
     }
    else
    {
    QMessageBox::critical(nullptr,QObject::tr("Data base is not open "),
                             QObject::tr("Connexion failed\nClick cancel to exit")
                             ,QMessageBox::Cancel);
    }
    return a.exec();
}
