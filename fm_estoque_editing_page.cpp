#include "fm_estoque_editing_page.h"
#include "ui_fm_estoque_editing_page.h"

Fm_estoque_editing_page::Fm_estoque_editing_page(QWidget *parent,
                                                 QStringList* item,
                                                 std::unordered_map<QString, int>* fornecedores,
                                                 Fm_Estoque *fm_estoque,
                                                 Fm_estoque_DAO *estoqueDAO)
    : QDialog(parent)
    , ui(new Ui::Fm_estoque_editing_page)
{
    ui->setupUi(this);

    this->item = item;
    this->fornecedores = fornecedores;
    this->estoqueDAO = estoqueDAO;
    this->estoquePage = fm_estoque;

    this->setFornecedorCB();
    this->montarInputs();
}

Fm_estoque_editing_page::~Fm_estoque_editing_page()
{
    delete ui;
}

void Fm_estoque_editing_page::montarInputs()
{
    this->ui->le_prodCod->setText(this->item->at(0));
    this->ui->le_prodName->setText(this->item->at(1));
    this->ui->le_prodQtt->setText(this->item->at(2));
    this->ui->le_prodDesc->setText(this->item->at(5));

    QString *dValue = new QString(this->item->at(3));
    dValue->replace(",", ".");

    this->ui->dsb_bValue->setValue(dValue->toDouble());

    delete dValue;
    dValue = nullptr;
    dValue = new QString(this->item->at(4));
    dValue->replace(",", ".");

    this->ui->dsb_sValue->setValue(dValue->toDouble());

    delete dValue;
}

void Fm_estoque_editing_page::setFornecedorCB()
{
    this->ui->cb_supplier->addItem("Selecione");

    int *count = new int(0);
    for (const auto& i : *this->fornecedores) {
        this->ui->cb_supplier->addItem(i.first);
        *count += 1;
        if (i.first.compare(this->item->at(6)) == 0)
            this->ui->cb_supplier->setCurrentIndex(*count);
    }

    delete count;
}

bool Fm_estoque_editing_page::verifyBlank()
{
    if ((this->ui->dsb_bValue->value() == 0.00) or (this->ui->dsb_bValue->text().isEmpty())) {
        this->ui->dsb_bValue->setFocus();
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'Valor de Compra' está vazio!");
        return true;
    } else if ((this->ui->dsb_sValue->value() == 0.0) or (this->ui->dsb_sValue->text().isEmpty())) {
        this->ui->dsb_sValue->setFocus();
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'Valor de Venda' está vazio!");
        return true;
    } else if (this->ui->le_prodCod->text().isEmpty()) {
        this->ui->le_prodCod->setFocus();
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'Código do Produto' está vazio!");
        return true;
    } else if ((this->ui->le_prodCod->text().size() > 6) or (this->ui->le_prodCod->text().size() < 4)) {
        this->ui->le_prodCod->setFocus();
        QMessageBox::warning(this, "Campo Irregular", "O campo de 'Código do Produto' está com uma quantidade de dígitos errada!");
        return true;
    } else if (this->ui->le_prodName->text().isEmpty()) {
        this->ui->le_prodName->setFocus();
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'Nome do Produto' está vazio!");
        return true;
    } else if (this->ui->le_prodDesc->text().isEmpty()) {
        this->ui->le_prodDesc->setFocus();
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'Descrição do Produto' está vazio!");
        return true;
    } else if (this->ui->cb_supplier->currentIndex() == 0) {
        this->ui->cb_supplier->setFocus();
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'Fornecedor' não foi selecionado!");
        return true;
    } else if (this->ui->le_prodQtt->text().isEmpty()) {
        this->ui->le_prodQtt->setText("1");
    }

    return false;
}

void Fm_estoque_editing_page::on_btt_att_clicked()
{
    if (this->verifyBlank()) return;

    int *id = new int(this->item->at(0).toInt());

    const std::array<QString, 7>* data = new std::array<QString, 7>({this->ui->le_prodCod->text(),
                                                                     this->ui->le_prodName->text(),
                                                                     this->ui->le_prodDesc->text(),
                                                                     this->ui->le_prodQtt->text(),
                                                                     this->ui->dsb_bValue->text().replace(",", "."),
                                                                     this->ui->dsb_sValue->text().replace(",", "."),
                                                                     QString::number(this->fornecedores->at(this->ui->cb_supplier->currentText()))});

    switch (this->estoqueDAO->alterProduto(data, id)) {
        case -2:
            QMessageBox::critical(this, "Erro", "Erro ao alterar.<br/>Erro: -2");
            delete data;
            delete id;
            return;
            break;
        case -1:
            QMessageBox::critical(this, "Erro", "Erro ao acessar DB<br/>Erro: -1");
            delete data;
            delete id;
            return;
            break;
        case 0:
            QMessageBox::information(this, "Sucesso", "Produto alterado com sucesso");
            break;
        default:
            QMessageBox::critical(this, "Erro", "Erro desconhecido<br/>Erro: N/D");
            delete data;
            delete id;
            return;
            break;
    }

    delete data;

    this->item->clear();
    this->item->emplace_back(this->ui->le_prodCod->text());
    this->item->emplace_back(this->ui->le_prodName->text());
    this->item->emplace_back(this->ui->le_prodQtt->text());
    this->item->emplace_back(this->ui->dsb_bValue->text());
    this->item->emplace_back(this->ui->dsb_sValue->text());
    this->item->emplace_back(this->ui->le_prodDesc->text());
    this->item->emplace_back(this->ui->cb_supplier->currentText());

    this->estoquePage->fecharAba(this, this->item, id);
    this->close();
}

void Fm_estoque_editing_page::on_btt_cancelar_clicked()
{
    this->estoquePage->fecharAba(this, new int(this->item->at(0).toInt()));
    this->close();
}

void Fm_estoque_editing_page::on_dsb_bValue_textChanged(const QString &arg1)
{
    if (arg1.contains("."))
        this->ui->dsb_bValue->setValue(arg1.toDouble());
}

void Fm_estoque_editing_page::on_dsb_sValue_textChanged(const QString &arg1)
{
    if (arg1.contains("."))
        this->ui->dsb_sValue->setValue(arg1.toDouble());
}
