#ifndef FM_PAGAMENTO_H
#define FM_PAGAMENTO_H

#include <QDialog>

#include "fm_pagamento_dao.h"

namespace Ui {
class Fm_Pagamento;
}

class Fm_Pagamento : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_Pagamento(QWidget *parent = nullptr);

    ~Fm_Pagamento();

    int exec() override;

private slots:
    void on_btt_confirm_clicked();

    void on_btt_cancel_clicked();

private:
    Ui::Fm_Pagamento *ui;

    Fm_Pagamento_DAO *DAO;

    int* index;

    void setCB();
};

#endif // FM_PAGAMENTO_H
