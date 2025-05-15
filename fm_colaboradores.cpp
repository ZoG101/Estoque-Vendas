#include "fm_colaboradores.h"
#include "ui_fm_colaboradores.h"

Fm_Colaboradores::Fm_Colaboradores(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Fm_Colaboradores)
{
    ui->setupUi(this);
}

Fm_Colaboradores::~Fm_Colaboradores()
{
    delete ui;
}
