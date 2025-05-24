#include "fm_vendasgerais_dao.h"

#include <QSqlError>
#include <QSqlQuery>
#include <QDate>

Fm_VendasGerais_DAO::Fm_VendasGerais_DAO()
{
    this->con = ConnectionFactory::getInstance();
}

QList<QStringList>* Fm_VendasGerais_DAO::getAllVendas()
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT "
                   "tb_vendas.id, "
                   "tb_vendas.data_venda, "
                   "tb_vendas.hora_venda, "
                   "tb_vendas.valor_total, "
                   "tb_tipo_pagamento.tipo, "
                   "tb_colaborador.nome "
                   "FROM tb_vendas, tb_tipo_pagamento, tb_colaborador "
                   "WHERE tb_tipo_pagamento.id = tb_vendas.id_tipo_pagamento AND tb_colaborador.id = tb_vendas.id_colaborador;");

    QList<QStringList>* sellings = nullptr;

    if (query->exec()) {
        sellings = new QList<QStringList>();

        while (query->next()) sellings->emplace_back(QStringList({query->value(0).toString(),
                                                query->value(1).toDate().toString("dd/MM/yyyy"),
                                                query->value(2).toString(),
                                                query->value(3).toString(),
                                                query->value(4).toString(),
                                                query->value(5).toString()}));
    } else {
        this->con->closeDB();

        delete query;

        return sellings;
    }

    this->con->closeDB();

    delete query;

    return sellings;
}

QList<QStringList*>* Fm_VendasGerais_DAO::getSellingProds(int* id)
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT "
                   "tb_produtos.produto, "
                   "tb_item_venda.qtde, "
                   "tb_produtos.valor_venda "
                   "FROM tb_produtos, tb_item_venda WHERE tb_item_venda.id_venda = :id AND tb_produtos.id_produto = tb_item_venda.id_produto;");
    query->bindValue(":id", *id);

    QList<QStringList*>* data = nullptr;

    if (query->exec()) {
        data = new QList<QStringList*>();
        while(query->next()) data->emplace_back(new QStringList({query->value(0).toString(),
                                            query->value(1).toString(),
                                            query->value(2).toString()}));
    } else {
        this->con->closeDB();

        delete query;
        delete id;

        return data;
    }

    this->con->closeDB();

    delete query;
    delete id;

    return data;
}

QList<QStringList>* Fm_VendasGerais_DAO::getSellingPeriod(QString dateFrom, QString dateTo)
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT "
                   "tb_vendas.id, "
                   "tb_vendas.data_venda, "
                   "tb_vendas.hora_venda, "
                   "tb_vendas.valor_total, "
                   "tb_tipo_pagamento.tipo, "
                   "tb_colaborador.nome "
                   "FROM tb_vendas, tb_tipo_pagamento, tb_colaborador "
                   "WHERE tb_tipo_pagamento.id = tb_vendas.id_tipo_pagamento "
                   "AND tb_colaborador.id = tb_vendas.id_colaborador "
                   "AND ((DATE(tb_vendas.data_venda) >= DATE(:dateFrom)) AND (DATE(tb_vendas.data_venda) <= DATE(:dateTo)));");
    query->bindValue(":dateFrom", dateFrom);
    query->bindValue(":dateTo", dateTo);

    QList<QStringList>* data = nullptr;

    if (query->exec()) {
        data = new QList<QStringList>();
        while (query->next()) data->emplace_back(QStringList({query->value(0).toString(),
                                                query->value(1).toDate().toString("dd/MM/yyyy"),
                                                query->value(2).toString(),
                                                query->value(3).toString(),
                                                query->value(4).toString(),
                                                query->value(5).toString()}));
    } else {
        this->con->closeDB();

        delete query;

        return data;
    }

    this->con->closeDB();

    delete query;

    return data;
}
