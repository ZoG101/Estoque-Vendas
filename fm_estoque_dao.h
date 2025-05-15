#ifndef FM_ESTOQUE_DAO_H
#define FM_ESTOQUE_DAO_H

#include <QSqlError>
#include <QSqlQuery>

#include "ConnectionFactory.h"

class Fm_estoque_DAO
{
public:
    Fm_estoque_DAO();

    ~Fm_estoque_DAO();

    std::unordered_map<QString, int>* getFornecedores();

    std::map<int, QStringList*>* getProdutos();

    std::map<int, QStringList*>* getProdutosFilterNome(const QString& nome);

    std::map<int, QStringList*>* getProdutosFilterDesc(const QString& desc);

    int setProduto(const std::array<QString, 7>* data);

    int alterProduto(const std::array<QString, 7>* data, const int* id);

    int deleteProd(int* id);

private:
    ConnectionFactory *con;
};

#endif // FM_ESTOQUE_DAO_H
