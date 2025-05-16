#include "fm_colaboradores_dao.h"

#include <QSqlQuery>
#include <QSqlError>

Fm_Colaboradores_DAO::Fm_Colaboradores_DAO()
{
    this->con = ConnectionFactory::getInstance();
}

int Fm_Colaboradores_DAO::createUser(std::array<QString, 5>* data)
{
    if (!this->con->openDB()) return -1;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("INSERT INTO tb_colaborador "
                   "(nome, fone, username, senha, acesso) "
                   "VALUES (:nome, :fone, :user, :senha, :acesso);");
    query->bindValue(":nome", data->at(0));
    query->bindValue(":fone", data->at(1));
    query->bindValue(":user", data->at(2));
    query->bindValue(":senha", data->at(3));
    query->bindValue(":acesso", data->at(4));

    if (query->exec()) {
        this->con->closeDB();

        delete query;

        return 0;
    } else {
        this->con->closeDB();

        delete query;

        return -2;
    }
}
