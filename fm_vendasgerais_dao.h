#ifndef FM_VENDASGERAIS_DAO_H
#define FM_VENDASGERAIS_DAO_H

#include "connectionfactory.h"

class Fm_VendasGerais_DAO
{
public:
    Fm_VendasGerais_DAO();

    QList<QStringList>* getAllVendas();

    QList<QStringList*>* getSellingProds(int* id);

    QList<QStringList>* getSellingPeriod(QString dateFrom, QString dateTo);

private:
    ConnectionFactory* con;
};

#endif // FM_VENDASGERAIS_DAO_H
