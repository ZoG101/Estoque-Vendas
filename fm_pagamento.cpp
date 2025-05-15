#include "fm_pagamento.h"
#include "ui_fm_pagamento.h"

#include <QMessageBox>

Fm_Pagamento::Fm_Pagamento(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Fm_Pagamento)
{
    ui->setupUi(this);

    this->index = new int(0);
    this->DAO = new Fm_Pagamento_DAO();

    this->setCB();
}

Fm_Pagamento::~Fm_Pagamento()
{
    delete ui;
    delete DAO;
    delete index;
}

int Fm_Pagamento::exec()
{
    QDialog::exec();
    return *this->index;
}

void Fm_Pagamento::setCB()
{
    QStringList* pagMet = this->DAO->getMet();

    if (pagMet == nullptr) {
        QMessageBox::critical(this, "ERRO", "Erro ao recuperar métodos de pagamento<br/>Erro: -2");
        return;
    }

    this->ui->cb_pagamento->addItem("selecione");

    foreach (const auto& i, *pagMet)
        this->ui->cb_pagamento->addItem(i);

    delete pagMet;
}

void Fm_Pagamento::on_btt_confirm_clicked()
{
    *this->index = this->ui->cb_pagamento->currentIndex();
    this->close();
}


void Fm_Pagamento::on_btt_cancel_clicked()
{
    *this->index = 0;
    this->close();
}

