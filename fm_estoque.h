#ifndef FM_ESTOQUE_H
#define FM_ESTOQUE_H

#include <unordered_map>
#include <QMessageBox>
#include <QDialog>
#include <QVector>
#include <map>

#include "fm_estoque_dao.h"
#include "qlineedit.h"

namespace Ui {
class Fm_Estoque;
}

class Fm_Estoque : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_Estoque(QWidget *parent = nullptr);
    ~Fm_Estoque();

    void fecharAba(QWidget* page, QStringList* item, int* id);

    void fecharAba(QWidget* page);

private slots:
    void on_btt_clear_clicked();

    void on_btt_add_clicked();

    void on_dsb_bValue_textChanged(const QString &arg1);

    void on_dsb_sValue_textChanged(const QString &arg1);

    void on_le_pesquisa_textChanged(const QString &arg1);

    void on_btt_excluir_clicked();

    void on_btt_editar_clicked();

    void on_btt_reload_clicked();

private:
    void setFornecedorCB();

    void setTable();

    void setRows(std::map<int, QStringList*>* prods);

    void setRow(QStringList* prod);

    void clearFilterProd();

    bool verifyBlank();

    Ui::Fm_Estoque *ui;

    Fm_estoque_DAO *estoqueDAO;

    std::unordered_map<QString, int>* fornecedores;

    std::map<int, QStringList*>* produtos;

    std::map<int, QStringList*>* filterProdutos;
};

#endif // FM_ESTOQUE_H
