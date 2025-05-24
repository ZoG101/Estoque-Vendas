#include "connectionfactory.h"

ConnectionFactory::ConnectionFactory()
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(qApp->applicationDirPath() + "/db/db.db");

    this->db.close();
}

ConnectionFactory* ConnectionFactory::getInstance()
{
    call_once (flag, []() {
        ist = new  ConnectionFactory();
    });
    return ist;
}

bool ConnectionFactory::openDB()
{
    return this->db.open();
}

bool ConnectionFactory::startTransaction()
{
    return this->db.transaction();
}

bool ConnectionFactory::commit()
{
    return this->db.commit();
}

bool ConnectionFactory::rollback()
{
    return this->db.rollback();
}

void ConnectionFactory::closeDB()
{
    this->db.close();
}

ConnectionFactory* ConnectionFactory::ist = nullptr;
std::once_flag ConnectionFactory::flag;
