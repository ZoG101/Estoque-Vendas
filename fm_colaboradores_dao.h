#ifndef FM_COLABORADORES_DAO_H
#define FM_COLABORADORES_DAO_H

#include "connectionfactory.h"

class Fm_Colaboradores_DAO
{
public:
    Fm_Colaboradores_DAO();

    int createUser(std::array<QString, 5>* data);

private:
    ConnectionFactory* con;
};

#endif // FM_COLABORADORES_DAO_H
