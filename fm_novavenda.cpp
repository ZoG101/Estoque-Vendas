#include "fm_novavenda.h"
#include "ui_fm_novavenda.h"
#include "fm_pagamento.h"

#include <QMessageBox>

Fm_NovaVenda::Fm_NovaVenda(QWidget *parent, User *user)
    : QDialog(parent)
    , ui(new Ui::Fm_NovaVenda)
{
    ui->setupUi(this);

    this->data = nullptr;
    this->user = user;

    this->DAO = new Fm_NovaVenda_DAO();
    this->qtde = new int(0);
    this->total = new double(0);

    this->clearLbl();
    this->setTable();
}

Fm_NovaVenda::~Fm_NovaVenda()
{
    delete ui;

    if (this->data != nullptr) {
        for (const auto i : *this->data)
            delete i;
        delete data;
    }

    delete DAO;
    delete qtde;
    delete total;
}

void Fm_NovaVenda::setTable()
{
    this->ui->tw_produtos->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    this->ui->tw_produtos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->tw_produtos->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tw_produtos->verticalHeader()->setVisible(false);
}

void Fm_NovaVenda::clearData()
{
    if (this->data != nullptr) {
        for (const auto i : *this->data)
            delete i;
        delete data;
        this->data = nullptr;
    }
}

void Fm_NovaVenda::setRow()
{
    for (int i = 0; i < this->ui->tw_produtos->rowCount(); i++) {
        this->ui->tw_produtos->selectRow(i);
        if (this->ui->tw_produtos->selectedItems().at(0)->text() == *this->data->at(0)) {
            this->ui->tw_produtos->selectedItems().at(0)->setText(*this->data->at(0));
            this->ui->tw_produtos->selectedItems().at(1)->setText(*this->data->at(1));
            this->ui->tw_produtos->selectedItems().at(2)->setText(QString::number(*this->qtde));
            this->ui->tw_produtos->selectedItems().at(3)->setText(*this->data->at(5));
            this->updateTotal(this->ui->tw_produtos->selectedItems().at(4)->text().toDouble());
            this->updateTotal();
            this->ui->tw_produtos->selectedItems().at(4)->setText(QString::number(*this->qtde * this->data->at(5)->toDouble()));

            return;
        }
    }

    int *count = new int(this->ui->tw_produtos->rowCount());

    this->ui->tw_produtos->setRowCount(*count);
    this->ui->tw_produtos->insertRow(*count);
    this->ui->tw_produtos->setItem(*count, 0, new QTableWidgetItem(*this->data->at(0)));
    this->ui->tw_produtos->setItem(*count, 1, new QTableWidgetItem(*this->data->at(1)));
    this->ui->tw_produtos->setItem(*count, 2, new QTableWidgetItem(QString::number(*this->qtde)));
    this->ui->tw_produtos->setItem(*count, 3, new QTableWidgetItem(*this->data->at(5)));
    this->ui->tw_produtos->setItem(*count, 4, new QTableWidgetItem(QString::number(*this->qtde * this->data->at(5)->toDouble())));

    this->ui->tw_produtos->sortItems(1);

    delete count;

    this->updateTotal();
}

bool Fm_NovaVenda::verifyBlank()
{
    if (this->ui->le_qtde->text().isEmpty()) {
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'quantidade' está vazio!");
        return true;
    } else if (this->ui->le_codProd->text().isEmpty()) {
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'Código do produto' está vazio!");
        return true;
    }

    return false;
}

void Fm_NovaVenda::clearLbl()
{
    this->ui->lbl_name->setText("Nome: N/D");
    this->ui->lbl_desc->setText("Descrição: N/D");
    this->ui->lbl_prodQtde->setText("Quantidade disponível: N/D");
    this->ui->lbl_sellingValue->setText("Valor de venda: N/D");
}

void Fm_NovaVenda::on_btt_pesquisar_clicked()
{
    if (this->verifyBlank()) return;

    this->clearData();
    this->clearLbl();

    this->data = this->DAO->searchProd(this->ui->le_codProd->text());

    if (this->data != nullptr){
        if (this->data->at(3)->toInt() < *this->qtde)
            QMessageBox::warning(this, "Campo Inadequado", "O campo de 'Quantidade' está com um número acima da quantidade em estoque!<br/>Só possuimos " + *this->data->at(3) + " unidades");

        this->ui->lbl_name->setText(this->ui->lbl_name->text().replace("N/D", *this->data->at(1)));
        this->ui->lbl_desc->setText(this->ui->lbl_desc->text().replace("N/D", *this->data->at(6)));
        this->ui->lbl_prodQtde->setText(this->ui->lbl_prodQtde->text().replace("N/D", *this->data->at(3)));
        this->ui->lbl_sellingValue->setText(this->ui->lbl_sellingValue->text().replace("N/D", *this->data->at(5)));
    } else {
        QMessageBox::critical(this, "ERRO", "Não foi possível encontrar o produto buscado<br/>Erro: -2");
    }
}

bool Fm_NovaVenda::verifyQtde(const QString& arg1)
{
    if (arg1.toInt() <= 0) {
        QMessageBox::warning(this, "Campo Inadequando", "O campo de 'Quantidade' deve conter apenas números!");
        this->ui->le_qtde->clear();
        return true;
    } else {
        *this->qtde = arg1.toInt();
        return false;
    }
}

void Fm_NovaVenda::on_le_qtde_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        *this->qtde = 0;
        return;
    } else if (arg1.toInt() == 0) {
        QMessageBox::warning(this, "Campo Inadequando", "O campo de 'Quantidade' deve conter apenas números!");
        this->ui->le_qtde->clear();
        return;
    } else {
        *this->qtde = arg1.toInt();
        return;
    }
}

void Fm_NovaVenda::on_le_codProd_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        return;
    } else if (arg1.toInt() <= 0) {
        QMessageBox::warning(this, "Campo Inadequando", "O campo de 'Quantidade' deve conter apenas números!");
        this->ui->le_qtde->clear();
        return;
    }
}

void Fm_NovaVenda::updateTotal()
{
    *this->total += this->data->at(5)->toDouble() * *this->qtde;

    this->ui->lbl_total->setText("Valor Total R$" + QString::number(*total).replace(".", ","));
}

void Fm_NovaVenda::updateTotal(const double& ant)
{
    *this->total -= ant;

    this->ui->lbl_total->setText("Valor Total R$" + QString::number(*total).replace(".", ","));
}

void Fm_NovaVenda::on_btt_confirmAdding_clicked()
{
    if (this->data->empty() or this->data == nullptr) {
        QMessageBox::warning(this, "Campo Inadequando", "Você deve pesquisar um produto primeiro!");
        return;
    } else if (this->verifyQtde(this->ui->le_qtde->text())) {
        return;
    } else if (*this->qtde > this->data->at(3)->toInt()) {
        QMessageBox::warning(this, "Campo Inadequado", "O campo de 'Quantidade' está com um número acima da quantidade em estoque!<br/>Só possuimos " + *this->data->at(3) + " unidades");
        return;
    }

    this->setRow();
    this->clearData();
    this->clearLbl();

    this->ui->le_qtde->clear();
    this->ui->le_codProd->clear();
}


void Fm_NovaVenda::on_btt_delete_clicked()
{
    if (this->ui->tw_produtos->selectedItems().empty()) {
        QMessageBox::warning(this, "Sem Seleção", "Não há nenhuma linha selecionada!");
        return;
    }

    this->updateTotal(this->ui->tw_produtos->selectedItems().at(4)->text().toDouble());

    this->ui->tw_produtos->removeRow(this->ui->tw_produtos->currentRow());
}

void Fm_NovaVenda::clearTable()
{
    if (this->ui->tw_produtos->rowCount() > 0) {
        while (this->ui->tw_produtos->rowCount() > 0)
            this->ui->tw_produtos->removeRow(0);

        this->ui->tw_produtos->setRowCount(-1);
    }
}

void Fm_NovaVenda::on_btt_edit_clicked()
{
    if (this->ui->tw_produtos->selectedItems().empty()) {
        QMessageBox::warning(this, "Sem Seleção", "Não há nenhuma linha selecionada!");
        return;
    }

    this->ui->le_codProd->setText(this->ui->tw_produtos->selectedItems().at(0)->text());
    this->ui->le_qtde->setText(this->ui->tw_produtos->selectedItems().at(2)->text());

    this->on_btt_pesquisar_clicked();
}


void Fm_NovaVenda::on_btt_sell_clicked()
{
    if (this->ui->tw_produtos->rowCount() == 0) {
        QMessageBox::warning(this, "Sem Item", "Adicione um produto primeiro!");
        return;
    }

    Fm_Pagamento* pagamento = new Fm_Pagamento(this);
    pagamento->setModal(true);

    int *idPag = new int(pagamento->exec());

    if (*idPag == 0) {
        QMessageBox::information(this, "Compra cancelada", "Pagamento não selecionado!");
        delete pagamento;
        delete idPag;
        return;
    }

    this->ui->tw_produtos->selectAll();

    QList<QTableWidgetItem*> *items = new QList<QTableWidgetItem*>(this->ui->tw_produtos->selectedItems());
    int *id = new int(this->user->getId());

    if (this->DAO->newPurchase(items, this->total, id, idPag)) {
        QMessageBox::information(this, "Sucesso!", "Compra finalizada!");
    } else {
        QMessageBox::critical(this, "Falha!", "Não foi possível realizar a compra!");
    }

    delete pagamento;
    delete idPag;
    delete items;
    delete id;

    this->updateTotal(*this->total);
    this->clearTable();
}

