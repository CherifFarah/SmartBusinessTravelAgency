#include "connection.h"

connection::connection()
{

}

bool connection::testConnect()
{
    bool test=false;
QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("amin");
db.setPassword("waymin");
if(db.open())
    test=true;

return test;
}

