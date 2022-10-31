#include "connection.h"

Connection::Connection()
{

}
bool Connection::connect()
{
    bool c=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("amin");
    db.setPassword("waymin");
    if (db.open())
        c=true;
    return c;
}
