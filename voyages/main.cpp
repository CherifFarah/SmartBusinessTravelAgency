#include "mainwindow.h"
#include <QFontDatabase>
#include <QApplication>
#include <QDebug>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection db;
if(db.testConnect()==false)
    qDebug() <<"connexion n'a pas ete effectue";
else
    qDebug()<<"connexion a ete effectuer avec success";
    MainWindow w;
    w.show();
    return a.exec();
}
