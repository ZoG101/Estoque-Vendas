#ifndef FM_VENDAS_DAO_H
#define FM_VENDAS_DAO_H

#include "connectionfactory.h"


class Fm_Vendas_DAO
{
public:
    Fm_Vendas_DAO();

    QVector<QStringList*>* getData(const char& type, int* id);

private:
    ConnectionFactory* con;

    QVector<QStringList*>* getYearTime(int* id);

    QVector<QStringList*>* getWeekTime(int* id);

    QVector<QStringList*>* getMonthTime(int* id);
};

#endif // FM_VENDAS_DAO_H
