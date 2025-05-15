#ifndef CONNCTIONFACTORY_H
#define CONNCTIONFACTORY_H

#include <QSqlQuery>
#include <QObject>

class ConnctionFactory : public QObject
{
    Q_OBJECT
public:
    static QSqlDatabase* getCon(const QString& local);

private:
    static QSqlDatabase db;
    static ConnctionFactory *con;

    ConnctionFactory(const QString& local);
    ~ConnctionFactory();
};

#endif // CONNCTIONFACTORY_H
