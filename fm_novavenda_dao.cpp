#include "fm_novavenda_dao.h"

#include <QSqlError>
#include <QSqlQuery>
#include <QDate>
#include <QTime>

Fm_NovaVenda_DAO::Fm_NovaVenda_DAO() {
    this->con = ConnectionFactory::getInstance();
}

std::array<QString*, 7>* Fm_NovaVenda_DAO::searchProd(const QString& id)
{
    if(!this->con->openDB()) return nullptr;

    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * FROM tb_produtos WHERE id_produto = :id;");
    query->bindValue(":id", id);

    std::array<QString*, 7>* data;

    if (query->exec() and query->first()) {
        data = new std::array<QString*, 7>({new QString(query->value(0).toString()),
                                            new QString(query->value(1).toString()),
                                            new QString(query->value(2).toString()),
                                            new QString(query->value(3).toString()),
                                            new QString(query->value(4).toString()),
                                            new QString(query->value(5).toString()),
                                            new QString(query->value(6).toString())});

        this->con->closeDB();

        delete query;

        return data;
    } else {
        this->con->closeDB();

        delete query;

        return nullptr;
    }
}

bool Fm_NovaVenda_DAO::newPurchase(QList<QTableWidgetItem*>* items, double* total, int* id, int* idPag)
{
    if(!this->con->openDB()) return false;
    else if (!this->con->startTransaction()) return false;

    QSqlQuery *query = new QSqlQuery();
    query->prepare("INSERT INTO tb_vendas (data_venda, hora_venda, id_colaborador, valor_total, id_tipo_pagamento) VALUES (DATE('now'), :hora, :colab, :total, :idPag);");
    //query->bindValue(":data", QDate::currentDate().toString("yyyy-MM-dd"));
    query->bindValue(":hora", QTime::currentTime().toString());
    query->bindValue(":colab", *id);
    query->bindValue(":total", *total);
    query->bindValue(":idPag", *idPag);

    if (!query->exec()) {
        qDebug() << query->lastError().text();

        this->con->rollback();
        this->con->closeDB();

        delete query;

        return false;
    }

    QVariant* idRe = new QVariant(query->lastInsertId());

    query->clear();

    query->prepare("INSERT INTO tb_item_venda "
                   "(id_venda, id_produto, qtde) "
                   "VALUES (:idVenda, :idProd, :qtde);");

    for (int i = 0; i < items->size(); i += 5) {
        query->bindValue(":idVenda", idRe->toString());
        query->bindValue(":idProd", items->at(i)->text());
        query->bindValue(":qtde", items->at(i + 2)->text());

        if(query->exec()) {
            query->clear();
            query->prepare("INSERT INTO tb_item_venda "
                           "(id_venda, id_produto, qtde) "
                           "VALUES (:idVenda, :idProd, :qtde);");
            continue;
        } else {
            this->con->rollback();
            this->con->closeDB();

            delete query;
            delete idRe;

            return false;
        }
    }

    this->con->commit();
    this->con->closeDB();

    delete query;
    delete idRe;

    return true;
}
