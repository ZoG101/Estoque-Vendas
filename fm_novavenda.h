#ifndef FM_NOVAVENDA_H
#define FM_NOVAVENDA_H

#include <QDialog>

#include "fm_novavenda_dao.h"
#include "user.h"

namespace Ui {
class Fm_NovaVenda;
}

class Fm_NovaVenda : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_NovaVenda(QWidget *parent = nullptr, User* user = nullptr);
    ~Fm_NovaVenda();

private slots:
    void on_btt_pesquisar_clicked();

    void on_le_qtde_textChanged(const QString &arg1);

    void on_le_codProd_textChanged(const QString &arg1);

    void on_btt_confirmAdding_clicked();

    void on_btt_delete_clicked();

    void on_btt_edit_clicked();

    void on_btt_sell_clicked();

private:
    Ui::Fm_NovaVenda *ui;

    Fm_NovaVenda_DAO* DAO;

    std::array<QString*, 7>* data;

    User *user;

    int *qtde;

    double *total;

    bool verifyBlank();

    bool verifyQtde(const QString& arg1);

    void setTable();

    void clearData();

    void clearLbl();

    void clearTable();

    void setRow();

    void updateTotal();

    void updateTotal(const double& ant);
};

#endif // FM_NOVAVENDA_H
