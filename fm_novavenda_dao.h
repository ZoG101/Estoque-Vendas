#ifndef FM_NOVAVENDA_DAO_H
#define FM_NOVAVENDA_DAO_H

#include "connectionfactory.h"
#include "qtablewidget.h"

class Fm_NovaVenda_DAO
{
public:
    Fm_NovaVenda_DAO();

    std::array<QString*, 7>* searchProd(const QString& id);

    bool newPurchase(QList<QTableWidgetItem*>* items, double* total, int* id, int* idPag);

private:
    ConnectionFactory *con;
};

#endif // FM_NOVAVENDA_DAO_H
