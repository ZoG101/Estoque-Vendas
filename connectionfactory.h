#ifndef CONNECTIONFACTORY_H
#define CONNECTIONFACTORY_H

#include <QApplication>
#include <QSqlError>
#include <QSqlQuery>
#include <mutex>
#include <QSql>

class ConnectionFactory
{
private:
    ConnectionFactory();

    static ConnectionFactory* ist;
    static std::once_flag flag;

    QSqlDatabase db;

    ConnectionFactory ( const ConnectionFactory&) = delete ;
    ConnectionFactory& operator=( const ConnectionFactory&) = delete ;

public:
    static ConnectionFactory* getInstance();

    bool openDB();

    bool startTransaction();

    bool commit();

    bool rollback();

    void closeDB();
};

#endif // CONNECTIONFACTORY_H
