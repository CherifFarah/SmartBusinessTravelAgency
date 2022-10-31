#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class Connection
{
public:
    bool connect();
    Connection();
};

#endif // CONNECTION_H
