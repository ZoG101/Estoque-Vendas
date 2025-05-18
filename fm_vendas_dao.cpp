#include "fm_vendas_dao.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>

Fm_Vendas_DAO::Fm_Vendas_DAO()
{
    this->con = ConnectionFactory::getInstance();
}

QVector<QStringList*>* Fm_Vendas_DAO::getData(const char& type, int* id)
{
    switch (type) {
        case 'Y':
            return this->getYearTime(id);
            break;
        case 'W':
            return this->getWeekTime(id);
            break;
        case 'M':
            return this->getMonthTime(id);
            break;
        default:
            return nullptr;
            break;
    }
}

QVector<QStringList*>* Fm_Vendas_DAO::getYearTime(int* id)
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT DATE(data_venda) AS dia, "
                   "SUM(valor_total) AS total_vendas "
                   "FROM tb_vendas "
                   "WHERE id_colaborador = :id AND dia >= DATE('now', '-1 year') "
                   "GROUP BY dia "
                   "ORDER BY dia;");
    query->bindValue(":id", *id);

    QVector<QStringList*>* data = nullptr;

    if (query->exec()) {
        data = new QVector<QStringList*>();

        while (query->next()) data->emplace_back(new QStringList({{query->value(0).toDateTime().toString(), query->value(1).toString()}}));

        this->con->closeDB();

        delete query;

        return data;
    } else {
        this->con->closeDB();

        delete query;

        return data;
    }
}

QVector<QStringList*>* Fm_Vendas_DAO::getWeekTime(int* id)
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT DATE(data_venda) AS dia, "
                   "SUM(valor_total) AS total_vendas "
                   "FROM tb_vendas "
                   "WHERE id_colaborador = :id AND dia >= DATE('now', '-7 days') "
                   "GROUP BY dia "
                   "ORDER BY dia;");
    query->bindValue(":id", *id);

    QVector<QStringList*>* data = nullptr;

    if (query->exec()) {
        data = new QVector<QStringList*>();

        while (query->next()) data->emplace_back(new QStringList({{query->value(0).toDateTime().toString(), query->value(1).toString()}}));

        this->con->closeDB();

        delete query;

        return data;
    } else {
        this->con->closeDB();

        delete query;

        return data;
    }
}

QVector<QStringList*>* Fm_Vendas_DAO::getMonthTime(int* id)
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT DATE(data_venda) AS dia, "
                   "SUM(valor_total) AS total_vendas "
                   "FROM tb_vendas "
                   "WHERE id_colaborador = :id AND dia >= DATE('now', '-1 month') "
                   "GROUP BY dia "
                   "ORDER BY dia;");
    query->bindValue(":id", *id);

    QVector<QStringList*>* data = nullptr;

    if (query->exec()) {
        data = new QVector<QStringList*>();

        while (query->next()) data->emplace_back(new QStringList({{query->value(0).toDateTime().toString(), query->value(1).toString()}}));

        this->con->closeDB();

        delete query;

        return data;
    } else {
        this->con->closeDB();

        delete query;

        return data;
    }
}
