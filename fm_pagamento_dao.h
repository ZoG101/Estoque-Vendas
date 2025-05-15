#ifndef FM_PAGAMENTO_DAO_H
#define FM_PAGAMENTO_DAO_H

#include "connectionfactory.h"

class Fm_Pagamento_DAO
{
public:
    Fm_Pagamento_DAO();

    QStringList* getMet();

private:
    ConnectionFactory* con;
};

#endif // FM_PAGAMENTO_DAO_H
