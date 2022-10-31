#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connection
{
public:
    connection();
    bool testConnect();
};

#endif // CONNECTION_H
