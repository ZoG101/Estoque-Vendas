#ifndef FM_ESTOQUE_EDITING_PAGE_H
#define FM_ESTOQUE_EDITING_PAGE_H

#include <unordered_map>
#include <QDialog>

#include "fm_estoque_dao.h"
#include "fm_estoque.h"

namespace Ui {
class Fm_estoque_editing_page;
}

class Fm_estoque_editing_page : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_estoque_editing_page(QWidget *parent = nullptr,
                                     QStringList* item = nullptr,
                                     std::unordered_map<QString, int>* fornecedores = nullptr,
                                     Fm_Estoque *fm_estoque = nullptr,
                                     Fm_estoque_DAO *estoqueDAO = nullptr);
    ~Fm_estoque_editing_page();

private slots:
    void on_btt_att_clicked();

    void on_btt_cancelar_clicked();

    void on_dsb_bValue_textChanged(const QString &arg1);

    void on_dsb_sValue_textChanged(const QString &arg1);

    bool verifyBlank();

private:
    Ui::Fm_estoque_editing_page *ui;

    Fm_Estoque* estoquePage;

    Fm_estoque_DAO *estoqueDAO;

    QStringList* item;

    std::unordered_map<QString, int>* fornecedores;

    void montarInputs();

    void setFornecedorCB();
};

#endif // FM_ESTOQUE_EDITING_PAGE_H
