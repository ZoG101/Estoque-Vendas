#include "fm_colaboradores_dao.h"

#include <QSqlQuery>
#include <QSqlError>

Fm_Colaboradores_DAO::Fm_Colaboradores_DAO()
{
    this->con = ConnectionFactory::getInstance();
}

QVector<QStringList*>* Fm_Colaboradores_DAO::getAllFunc()
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT * FROM tb_colaborador;");

    QVector<QStringList*>* data = nullptr;

    if (query->exec()) {
        data = new QVector<QStringList*>();
        while (query->next()) data->emplace_back(new QStringList({query->value(0).toString(),
                                            query->value(1).toString(),
                                            query->value(2).toString(),
                                            query->value(3).toString(),
                                            query->value(4).toString(),
                                            query->value(5).toString()}));

        this->con->closeDB();

        delete query;
    } else {
        this->con->closeDB();

        delete query;

        return data;
    }

    return data;
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
        int id = query->lastInsertId().toInt();

        this->con->closeDB();

        delete query;

        return id;
    } else {
        this->con->closeDB();

        delete query;

        return -2;
    }
}

QStringList* Fm_Colaboradores_DAO::getFunc(int *id)
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT * FROM tb_colaborador WHERE id = :uId;");
    query->bindValue(":uId", *id);

    QStringList* data = nullptr;

    if ((query->exec()) and (query->first())) {
        data = new QStringList();
        data->emplace_back(query->value(0).toString());
        data->emplace_back(query->value(1).toString());
        data->emplace_back(query->value(2).toString());
        data->emplace_back(query->value(3).toString());
        data->emplace_back(query->value(4).toString());
        data->emplace_back(query->value(5).toString());

        this->con->closeDB();

        delete query;
    } else {
        this->con->closeDB();

        delete query;

        return data;
    }

    return data;
}

QVector<QStringList*>* Fm_Colaboradores_DAO::searchFunc(const QString& arg1)
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT * FROM tb_colaborador WHERE nome LIKE :nme;");
    query->bindValue(":nme", "%" + arg1 + "%");

    QVector<QStringList*>* data = nullptr;

    if (query->exec()) {
        data = new QVector<QStringList*>();
        while (query->next()) data->emplace_back(new QStringList({query->value(0).toString(),
                                                query->value(1).toString(),
                                                query->value(2).toString(),
                                                query->value(3).toString(),
                                                query->value(4).toString(),
                                                query->value(5).toString()}));

        this->con->closeDB();

        delete query;
    } else {
        this->con->closeDB();

        delete query;

        return data;
    }

    return data;
}

int Fm_Colaboradores_DAO::deleteFunc(const QString& id)
{
    if (!this->con->openDB()) return -1;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("DELETE FROM tb_colaborador WHERE id = :id;");
    query->bindValue(":id", id);

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
