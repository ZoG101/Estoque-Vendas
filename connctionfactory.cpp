#include "connctionfactory.h"

ConnctionFactory::ConnctionFactory(const QString& local)
{
    ConnctionFactory::db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(local);
}

ConnctionFactory::~ConnctionFactory()
{
}

QSqlDatabase* ConnctionFactory::getCon(const QString& local)
{
    if (ConnctionFactory::con == nullptr) {
        ConnctionFactory::con = new ConnctionFactory(local);
        return &ConnctionFactory::db;
    } else return &ConnctionFactory::db;
}
