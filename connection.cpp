#include "connection.h"

connection::connection()
{

}


bool connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("farah");
    db.setPassword("esprit18");

    if (db.open())

        test=true;
        return test;

}

void connection::closeconnect()
{
    db.close();
}

