#include "fm_vendasgerais.h"
#include "ui_fm_vendasgerais.h"

Fm_VendasGerais::Fm_VendasGerais(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Fm_VendasGerais)
{
    ui->setupUi(this);
}

Fm_VendasGerais::~Fm_VendasGerais()
{
    delete ui;
}
