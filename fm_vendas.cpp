#include "fm_vendas.h"
#include "ui_fm_vendas.h"

Fm_Vendas::Fm_Vendas(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Fm_Vendas)
{
    ui->setupUi(this);
}

Fm_Vendas::~Fm_Vendas()
{
    delete ui;
}
