#include "fm_pagamento_dao.h"

#include <QSqlError>
#include <QSqlQuery>

Fm_Pagamento_DAO::Fm_Pagamento_DAO()
{
    this->con = ConnectionFactory::getInstance();
}

QStringList* Fm_Pagamento_DAO::getMet()
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT tipo FROM tb_tipo_pagamento;");

    QStringList* pagMet = nullptr;

    if (query->exec()) {
        pagMet = new QStringList();

        while (query->next())
            pagMet->emplace_back(query->value(0).toString());
    } else {
        this->con->closeDB();

        delete query;

        return pagMet;
    }

    this->con->closeDB();

    delete query;

    return pagMet;
}
