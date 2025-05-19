#include "fm_estoque.h"
#include "ui_fm_estoque.h"

#include "fm_estoque_editing_page.h"

Fm_Estoque::Fm_Estoque(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Fm_Estoque)
{
    ui->setupUi(this);

    this->estoqueDAO = new Fm_estoque_DAO();

    this->fornecedores = nullptr;
    this->setFornecedorCB();

    this->ui->dsb_bValue->setMaximum(999999.00);
    this->ui->dsb_sValue->setMaximum(999999.00);

    this->ui->rb_nome->setChecked(true);

    this->setTable();

    this->filterProdutos = nullptr;
}

Fm_Estoque::~Fm_Estoque()
{
    delete ui;
    delete estoqueDAO;

    for (const auto& i : *this->produtos)
        delete i.second;
    delete produtos;

    if (this->filterProdutos != nullptr) {
        for (const auto& i : *this->filterProdutos)
            delete i.second;

        delete filterProdutos;
    }

    if (this->fornecedores != nullptr) {
        this->fornecedores->clear();
        delete fornecedores;
    }
}

void Fm_Estoque::setFornecedorCB()
{
    this->fornecedores = this->estoqueDAO->getFornecedores();

    if (fornecedores == nullptr) {
        QMessageBox::critical(this, "Erro", "Erro ao excutar busca<br/>Não foi possível montar lista de fornecedores<br/>ERRO: -3");
        return;
    } else if (fornecedores->empty()){
        QMessageBox::critical(this, "Erro", "Não foi encontrado nenhum resultado<br/>Não foi possível montar lista de fornecedores<br/>ERRO: -4");
        return;
    }

    this->ui->cb_supplier->addItem("Selecione");

    for (const auto& i : *this->fornecedores)
        this->ui->cb_supplier->addItem(i.first);
}

void Fm_Estoque::setRows(std::map<int, QStringList*>* prods)
{
    if (this->ui->tw_produtos->rowCount() > 0) {
        for (int i = 0; i < this->ui->tw_produtos->rowCount(); i++)
            this->ui->tw_produtos->removeRow(i);

        this->ui->tw_produtos->setRowCount(-1);
    }

    int *i = new int(0);
    for (const auto& produto : *prods) {
        this->ui->tw_produtos->setRowCount(*i);
        this->ui->tw_produtos->insertRow(*i);
        this->ui->tw_produtos->setItem(*i, 0, new QTableWidgetItem(produto.second->at(0)));
        this->ui->tw_produtos->setItem(*i, 1, new QTableWidgetItem(produto.second->at(1)));
        this->ui->tw_produtos->setItem(*i, 2, new QTableWidgetItem(produto.second->at(3)));
        this->ui->tw_produtos->setItem(*i, 3, new QTableWidgetItem(produto.second->at(4)));
        this->ui->tw_produtos->setItem(*i, 4, new QTableWidgetItem(produto.second->at(2)));
        this->ui->tw_produtos->setItem(*i, 5, new QTableWidgetItem(produto.second->at(6)));
        *i += 1;
    }

    delete i;
}

void Fm_Estoque::setRow(QStringList* prod)
{
    int* count = new int(this->ui->tw_produtos->rowCount());

    this->ui->tw_produtos->setRowCount(*count);
    this->ui->tw_produtos->insertRow(*count);
    this->ui->tw_produtos->setItem(*count, 0, new QTableWidgetItem(prod->at(0)));
    this->ui->tw_produtos->setItem(*count, 1, new QTableWidgetItem(prod->at(1)));
    this->ui->tw_produtos->setItem(*count, 2, new QTableWidgetItem(prod->at(3)));
    this->ui->tw_produtos->setItem(*count, 3, new QTableWidgetItem(prod->at(4)));
    this->ui->tw_produtos->setItem(*count, 4, new QTableWidgetItem(prod->at(2)));
    this->ui->tw_produtos->setItem(*count, 5, new QTableWidgetItem(prod->at(6)));

    delete count;
}

void Fm_Estoque::setTable()
{
    this->produtos = this->estoqueDAO->getProdutos();

    if (this->produtos == nullptr) {
        QMessageBox::critical(this, "Erro", "Erro ao excutar busca de produtos<br/>Não foi possível montar tabla de produtos<br/>ERRO: -3");
        return;
    } else if (this->produtos->empty()) {
        QMessageBox::critical(this, "Erro", "Não foi encontrado nenhum resultado de produtos<br/>Não foi possível montar tabla de produtos<br/>ERRO: -4");
        return;
    }

    this->setRows(this->produtos);

    this->ui->tw_produtos->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    this->ui->tw_produtos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->tw_produtos->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tw_produtos->verticalHeader()->setVisible(false);
}

void Fm_Estoque::on_btt_clear_clicked()
{
    this->ui->dsb_bValue->setValue(0);
    this->ui->dsb_sValue->setValue(0);
    this->ui->le_prodCod->clear();
    this->ui->le_prodName->clear();
    this->ui->le_prodDesc->clear();
    this->ui->le_prodQtt->clear();
    this->ui->cb_supplier->setCurrentIndex(0);
}

bool Fm_Estoque::verifyBlank()
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

void Fm_Estoque::on_btt_add_clicked()
{
    if (this->verifyBlank()) return;

    const std::array<QString, 7>* data = new std::array<QString, 7>({this->ui->le_prodCod->text(),
                                                               this->ui->le_prodName->text(),
                                                               this->ui->le_prodDesc->text(),
                                                               this->ui->le_prodQtt->text(),
                                                               this->ui->dsb_bValue->text().replace(",", "."),
                                                               this->ui->dsb_sValue->text().replace(",", "."),
                                                               QString::number(this->fornecedores->at(this->ui->cb_supplier->currentText()))});

    switch (this->estoqueDAO->setProduto(data)) {
        case -2:
            QMessageBox::critical(this, "Erro", "Erro ao adicionar produto ao DB.<br/>Pode ser que o produto já exista<br/>Erro: -2");
            break;
        case -1:
            QMessageBox::critical(this, "Erro", "Erro ao acessar DB<br/>Erro: -1");
            break;
        case 0:
            QMessageBox::information(this, "Sucesso", "Produto adicionado com sucesso");
            this->produtos->emplace(this->ui->le_prodCod->text().toInt() ,new QStringList({this->ui->le_prodCod->text(),
                                                          this->ui->le_prodName->text(),
                                                          this->ui->le_prodQtt->text(),
                                                          this->ui->dsb_bValue->text(),
                                                          this->ui->dsb_sValue->text(),
                                                          this->ui->le_prodDesc->text(),
                                                          this->ui->cb_supplier->currentText()}));
            this->setRow(this->produtos->at(this->ui->le_prodCod->text().toInt()));
            this->on_btt_clear_clicked();
            break;
        default:
            QMessageBox::critical(this, "Erro", "Erro desconhecido<br/>Erro: N/D");
            break;
    }

    delete data;
}


void Fm_Estoque::on_dsb_bValue_textChanged(const QString &arg1)
{
    if (arg1.contains("."))
        this->ui->dsb_bValue->setValue(arg1.toDouble());
}


void Fm_Estoque::on_dsb_sValue_textChanged(const QString &arg1)
{
    if (arg1.contains("."))
        this->ui->dsb_sValue->setValue(arg1.toDouble());
}

void Fm_Estoque::clearFilterProd()
{
    if (this->filterProdutos != nullptr) {
        for (const auto& i : *this->filterProdutos)
            delete i.second;

        delete this->filterProdutos;
        this->filterProdutos = nullptr;
    }
}

void Fm_Estoque::on_le_pesquisa_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()){
        this->setRows(this->produtos);

        this->clearFilterProd();

        return;
    }

    if (this->ui->rb_nome->isChecked()) {
        this->clearFilterProd();

        this->filterProdutos = this->estoqueDAO->getProdutosFilterNome(arg1);

        if (this->filterProdutos == nullptr) {
            QMessageBox::critical(this, "Erro", "Erro ao excutar busca de produtos<br/>Não foi possível montar tabla de produtos<br/>ERRO: -3");
            this->setRows(this->produtos);
            return;
        }

        this->setRows(this->filterProdutos);
    } else if (this->ui->rb_descricao->isChecked()) {
        this->clearFilterProd();

        this->filterProdutos = this->estoqueDAO->getProdutosFilterDesc(arg1);

        if (this->filterProdutos == nullptr) {
            QMessageBox::critical(this, "Erro", "Erro ao excutar busca de produtos<br/>Não foi possível montar tabla de produtos<br/>ERRO: -3");
            this->setRows(this->produtos);
            return;
        }

        this->setRows(this->filterProdutos);
    }
}


void Fm_Estoque::on_btt_excluir_clicked()
{
    if (this->ui->tw_produtos->selectedItems().empty()) {
        QMessageBox::warning(this, "Sem Seleção", "Não há nenhuma linha selecionada!");
        return;
    } else if (QMessageBox::question(this, "Exclusão", "Deseja mesmo excluir o produto selecionado?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::StandardButton::No) return;

    int *id = new int(this->ui->tw_produtos->selectedItems().at(0)->text().toInt());
    int *res = new int(this->estoqueDAO->deleteProd(id));

    if (*res < 0) {
        QMessageBox::critical(this, "ERRO", "Não foi possível excluir o produto<br/> ERRO: " + QString::number(*res));
        delete id;
        delete res;
        return;
    }

    delete this->produtos->at(*id);
    this->produtos->erase(*id);

    if ((!this->ui->le_pesquisa->text().isEmpty()) and (this->filterProdutos != nullptr)) {
        delete this->filterProdutos->at(*id);
        this->filterProdutos->erase(*id);
        this->setRows(this->filterProdutos);
    } else {
        this->setRows(this->produtos);
    }

    delete id;
    delete res;
}

void Fm_Estoque::fecharAba(QWidget* page, QStringList* item, int* id)
{
    if ((!this->ui->le_pesquisa->text().isEmpty()) and (this->filterProdutos != nullptr)) {
        delete this->filterProdutos->at(*id);
        this->filterProdutos->erase(*id);
        this->filterProdutos->emplace(item->at(0).toInt(), new QStringList(*item));
    }

    this->produtos->erase(*id);
    this->produtos->emplace(item->at(0).toInt(), item);

    delete id;

    this->ui->tw_main->removeTab(this->ui->tw_main->indexOf(page));

    this->on_btt_reload_clicked();
}

void Fm_Estoque::fecharAba(QWidget* page)
{
    this->ui->tw_main->removeTab(this->ui->tw_main->indexOf(page));
}

void Fm_Estoque::on_btt_editar_clicked()
{
    if (this->ui->tw_produtos->selectedItems().empty()) {
        QMessageBox::warning(this, "Sem Seleção", "Não há nenhuma linha selecionada!");
        return;
    }

    this->ui->tw_main->addTab(new Fm_estoque_editing_page(this,
                                                          this->produtos->at(this->ui->tw_produtos->selectedItems().at(0)->text().toInt()),
                                                          this->fornecedores,
                                                          this,
                                                          this->estoqueDAO),
                              this->ui->tw_produtos->selectedItems().at(1)->text());
}

void Fm_Estoque::on_btt_reload_clicked()
{
    if ((!this->ui->le_pesquisa->text().isEmpty()) and (this->filterProdutos != nullptr)) this->setRows(this->filterProdutos);
    else this->setRows(this->produtos);
}
