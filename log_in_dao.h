#ifndef LOG_IN_DAO_H
#define LOG_IN_DAO_H

#include <QSqlError>
#include <QSqlQuery>

#include "connectionfactory.h"
#include "user.h"

class Log_in_DAO
{
public:
    Log_in_DAO();
    ~Log_in_DAO();

    int valid(const QString& user, const QString& password);
    User* getUser();

private:
    ConnectionFactory* con;
    User *user;
};

#endif // LOG_IN_DAO_H
