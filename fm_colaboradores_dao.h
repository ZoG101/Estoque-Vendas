#ifndef FM_COLABORADORES_DAO_H
#define FM_COLABORADORES_DAO_H

#include "connectionfactory.h"

class Fm_Colaboradores_DAO
{
public:
    Fm_Colaboradores_DAO();

    int createUser(std::array<QString, 5>* data);

    int updateUser(std::array<QString, 5>* data, QString* id);

    int deleteFunc(const QString& id);

    QVector<QStringList*>* getAllFunc();

    QVector<QStringList*>* searchFunc(const QString& arg1);

    QStringList* getFunc(int *id);

private:
    ConnectionFactory* con;
};

#endif // FM_COLABORADORES_DAO_H
