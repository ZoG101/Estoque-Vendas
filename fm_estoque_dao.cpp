#include "fm_estoque_dao.h"

#include <unordered_map>
#include <map>

Fm_estoque_DAO::Fm_estoque_DAO()
{
    this->con = ConnectionFactory::getInstance();
}

Fm_estoque_DAO::~Fm_estoque_DAO()
{}

std::unordered_map<QString, int>* Fm_estoque_DAO::getFornecedores()
{
    std::unordered_map<QString, int>* fornecedores = nullptr;

    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT * FROM tb_fornecedor "
                   "ORDER BY tb_fornecedor.nome DESC;");

    if (query->exec()) {
        fornecedores = new std::unordered_map<QString, int>();

        while (query->next())
            fornecedores->emplace(query->value(1).toString(), query->value(0).toInt());
    }

    this->con->closeDB();

    delete query;

    return fornecedores;
}

std::map<int, QStringList*>* Fm_estoque_DAO::getProdutos()
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT "
                    "tb_produtos.id_produto, "
                    "tb_produtos.produto, "
                    "tb_produtos.qtde_estoque, "
                    "tb_produtos.valor_compra, "
                    "tb_produtos.valor_venda, "
                    "tb_produtos.descricao, "
                    "tb_fornecedor.nome "
                   "FROM tb_produtos INNER JOIN tb_fornecedor ON tb_produtos.id_fornecedor = tb_fornecedor.id "
                   "ORDER BY tb_produtos.id_produto;");

    std::map<int, QStringList*>* produtos = nullptr;

    if (query->exec()) {
        produtos = new std::map<int, QStringList*>();

        while (query->next())
            produtos->emplace(query->value(0).toInt(), new QStringList({
                                                                        query->value(0).toString(),
                                                                        query->value(1).toString(),
                                                                        query->value(2).toString(),
                                                                        query->value(3).toString().replace(".", ","),
                                                                        query->value(4).toString().replace(".", ","),
                                                                        query->value(5).toString(),
                                                                        query->value(6).toString()}));
    } else {
        this->con->closeDB();

        delete query;

        return nullptr;
    }

    delete query;

    this->con->closeDB();

    return produtos;
}

std::map<int, QStringList*>* Fm_estoque_DAO::getProdutosFilterNome(const QString &nome)
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT "
                   "tb_produtos.id_produto, "
                   "tb_produtos.produto, "
                   "tb_produtos.qtde_estoque, "
                   "tb_produtos.valor_compra, "
                   "tb_produtos.valor_venda, "
                   "tb_produtos.descricao, "
                   "tb_fornecedor.nome "
                   "FROM tb_produtos INNER JOIN tb_fornecedor ON tb_produtos.id_fornecedor = tb_fornecedor.id "
                   "WHERE tb_produtos.produto LIKE :nme;");
    query->bindValue(":nme", "%" + nome + "%");

    std::map<int, QStringList*>* produtos = nullptr;

    if (query->exec()) {
        produtos = new std::map<int, QStringList*>();

        while (query->next())
            produtos->emplace(query->value(0).toInt(), new QStringList({
                                                                        query->value(0).toString(),
                                                                        query->value(1).toString(),
                                                                        query->value(2).toString(),
                                                                        query->value(3).toString().replace(".", ","),
                                                                        query->value(4).toString().replace(".", ","),
                                                                        query->value(5).toString(),
                                                                        query->value(6).toString()}));
    } else {
        this->con->closeDB();

        delete query;

        return nullptr;
    }

    delete query;

    this->con->closeDB();

    return produtos;
}

std::map<int, QStringList*>* Fm_estoque_DAO::getProdutosFilterDesc(const QString& desc)
{
    if (!this->con->openDB()) return nullptr;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT "
                   "tb_produtos.id_produto, "
                   "tb_produtos.produto, "
                   "tb_produtos.qtde_estoque, "
                   "tb_produtos.valor_compra, "
                   "tb_produtos.valor_venda, "
                   "tb_produtos.descricao, "
                   "tb_fornecedor.nome "
                   "FROM tb_produtos INNER JOIN tb_fornecedor ON tb_produtos.id_fornecedor = tb_fornecedor.id "
                   "WHERE tb_produtos.descricao LIKE :desc;");
    query->bindValue(":desc", "%" + desc + "%");

    std::map<int, QStringList*>* produtos = nullptr;

    if (query->exec()) {
        produtos = new std::map<int, QStringList*>();

        while (query->next())
            produtos->emplace(query->value(0).toInt(), new QStringList({
                                                                        query->value(0).toString(),
                                                                        query->value(1).toString(),
                                                                        query->value(2).toString(),
                                                                        query->value(3).toString().replace(".", ","),
                                                                        query->value(4).toString().replace(".", ","),
                                                                        query->value(5).toString(),
                                                                        query->value(6).toString()}));
    } else {
        this->con->closeDB();

        delete query;

        return nullptr;
    }

    delete query;

    this->con->closeDB();

    return produtos;
}

int Fm_estoque_DAO::setProduto(const std::array<QString, 7>* data)
{
    if (!this->con->openDB()) return -1;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("INSERT INTO tb_produtos "
                   "(id_produto, produto, descricao, qtde_estoque, valor_compra, valor_venda, id_fornecedor) "
                   "VALUES "
                   "(:prodCod, :prodName, :prodDesc, :prodQtt, :bValue, :sValue, :supplier);");

    query->bindValue(":prodCod", data->at(0));
    query->bindValue(":prodName", data->at(1));
    query->bindValue(":prodDesc", data->at(2));
    query->bindValue(":prodQtt", data->at(3));
    query->bindValue(":bValue", data->at(4));
    query->bindValue(":sValue", data->at(5));
    query->bindValue(":supplier", data->at(6));

    if (query->exec()) {
        this->con->closeDB();

        delete query;

        return 0;
    } else {
        this->con->closeDB();

        delete query;

        return -2;
    }

    if (query) delete query;
}

int Fm_estoque_DAO::alterProduto(const std::array<QString, 7>* data, const int* id)
{
    if (!this->con->openDB()) return -1;

    QSqlQuery* query = new QSqlQuery();
    query->prepare("UPDATE tb_produtos "
                   "SET "
                   "id_produto = :prodCod, "
                   "produto = :prodName, "
                   "descricao = :prodDesc, "
                   "qtde_estoque = :prodQtt, "
                   "valor_compra = :bValue, "
                   "valor_venda = :sValue, "
                   "id_fornecedor = :supplier "
                   "WHERE id_produto = :id;");

    query->bindValue(":prodCod", data->at(0));
    query->bindValue(":prodName", data->at(1));
    query->bindValue(":prodDesc", data->at(2));
    query->bindValue(":prodQtt", data->at(3));
    query->bindValue(":bValue", data->at(4));
    query->bindValue(":sValue", data->at(5));
    query->bindValue(":supplier", data->at(6));
    query->bindValue(":id", *id);

    if (query->exec()) {
        this->con->closeDB();

        delete query;

        return 0;
    } else {
        this->con->closeDB();

        delete query;

        return -2;
    }

    if (query) delete query;
}

int Fm_estoque_DAO::deleteProd(int* id)
{
    if (!this->con->openDB()) return -1;
    if (!this->con->startTransaction()) {
        this->con->closeDB();
        return -6;
    }

    QSqlQuery* query = new QSqlQuery();
    query->prepare("DELETE FROM tb_produtos WHERE id_produto = :id;");
    query->bindValue(":id", *id);

    if (query->exec()) {
        if (this->con->commit()) {
            this->con->closeDB();

            delete query;

            return 0;
        } else {
            if (this->con->rollback()) {
                this->con->closeDB();

                delete query;

                return -7;
            }
            this->con->closeDB();

            delete query;

            return -8;
        }
    } else {
        if (this->con->rollback()) {
            this->con->closeDB();

            delete query;

            return -7;
        }
        this->con->closeDB();

        delete query;

        return -8;
    }

    this->con->closeDB();
    if (query) delete query;
}
