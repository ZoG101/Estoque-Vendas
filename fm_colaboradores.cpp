#include "fm_colaboradores.h"
#include "ui_fm_colaboradores.h"
#include "fm_vendas.h"
#include "fm_colaboradores_editing.h"

#include <QMessageBox>

Fm_Colaboradores::Fm_Colaboradores(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Fm_Colaboradores)
{
    ui->setupUi(this);

    this->DAO = new Fm_Colaboradores_DAO();

    this->setTable();
}

Fm_Colaboradores::~Fm_Colaboradores()
{
    delete ui;
    delete DAO;
}

void Fm_Colaboradores::setRow(QStringList* data)
{
    int *count = new int(this->ui->tw_colabs->rowCount());

    this->ui->tw_colabs->setRowCount(*count);
    this->ui->tw_colabs->insertRow(*count);
    this->ui->tw_colabs->setItem(*count, 0, new QTableWidgetItem(data->at(0)));
    this->ui->tw_colabs->setItem(*count, 1, new QTableWidgetItem(data->at(1)));
    this->ui->tw_colabs->setItem(*count, 2, new QTableWidgetItem(data->at(4)));
    this->ui->tw_colabs->setItem(*count, 3, new QTableWidgetItem(data->at(5)));

    delete count;
}

void Fm_Colaboradores::clearRows()
{
    if (this->ui->tw_colabs->rowCount() > 0){
        for (int i = 0; i < this->ui->tw_colabs->rowCount(); i++)
            this->ui->tw_colabs->removeRow(i);

        this->ui->tw_colabs->setRowCount(-1);
    }
}

void Fm_Colaboradores::setRows(QVector<QStringList*>* data)
{
    this->clearRows();

    int *i = new int(0);
    foreach (const auto& colab, *data) {
        this->ui->tw_colabs->setRowCount(*i);
        this->ui->tw_colabs->insertRow(*i);
        this->ui->tw_colabs->setItem(*i, 0, new QTableWidgetItem(colab->at(0)));
        this->ui->tw_colabs->setItem(*i, 1, new QTableWidgetItem(colab->at(1)));
        this->ui->tw_colabs->setItem(*i, 2, new QTableWidgetItem(colab->at(4)));
        this->ui->tw_colabs->setItem(*i, 3, new QTableWidgetItem(colab->at(5)));
        *i += 1;
    }

    delete i;
}

void Fm_Colaboradores::setTable()
{
    QVector<QStringList*>* data = this->DAO->getAllFunc();

    if (data == nullptr) {
        QMessageBox::critical(this, "Erro", "Erro ao excutar busca de produtos<br/>Não foi possível montar tabla de produtos<br/>ERRO: -3");
        return;
    } else if (data->empty()) {
        QMessageBox::critical(this, "Erro", "Não foi encontrado nenhum resultado de produtos<br/>Não foi possível montar tabla de produtos<br/>ERRO: -4");
        return;
    }

    this->setRows(data);

    if (data != nullptr) {
        foreach (const auto &i, *data)
            delete i;
        delete data;
    }

    this->ui->tw_colabs->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    this->ui->tw_colabs->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->tw_colabs->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tw_colabs->verticalHeader()->setVisible(false);
    this->ui->tw_colabs->hideColumn(0);
}

void Fm_Colaboradores::on_btt_clearColab_clicked()
{
    this->ui->le_name->clear();
    this->ui->le_username->clear();
    this->ui->le_password->clear();
    this->ui->le_tel->clear();
    this->ui->cb_accessType->setCurrentIndex(0);
}

bool Fm_Colaboradores::verifyBlank()
{
    if (this->ui->le_name->text().isEmpty()) {
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'nome' está vazio!");
        this->ui->le_name->setFocus();
        return true;
    } else if (this->ui->le_tel->text().isEmpty()) {
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'telefone' está vazio!");
        this->ui->le_tel->setFocus();
        return true;
    } else if (this->ui->le_username->text().isEmpty()) {
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'username' está vazio!");
        this->ui->le_username->setFocus();
        return true;
    } else if (this->ui->le_password->text().isEmpty()) {
        QMessageBox::warning(this, "Campo Vazio", "O campo de 'senha' está vazio!");
        this->ui->le_password->setFocus();
        return true;
    } else if (this->ui->cb_accessType->currentIndex() == 0) {
        QMessageBox::warning(this, "Sem Seleção", "O campo de 'tipo de acesso' precisa ser selecionado!");
        this->ui->cb_accessType->setFocus();
        return true;
    }

    return false;
}

void Fm_Colaboradores::on_btt_userRegister_clicked()
{
    if (this->verifyBlank()) return;

    std::array<QString, 5>* data = new std::array<QString, 5>({this->ui->le_name->text(),
                                                               this->ui->le_tel->text(),
                                                               this->ui->le_username->text(),
                                                               this->ui->le_password->text(),
                                                               this->ui->cb_accessType->currentText()});

    int *res = new int(this->DAO->createUser(data));

    if (*res > 0) {
        QMessageBox::information(this, "Sucesso!", "Colaborador cadastrado com sucesso!");

        QStringList* func = this->DAO->getFunc(res);

        if (func == nullptr) {
            QMessageBox::critical(this, "Erro", "Erro ao excutar busca de produtos<br/>Não foi possível montar tabla de produtos<br/>ERRO: -3");
            return;
        } else if (func->empty()) {
            QMessageBox::critical(this, "Erro", "Não foi encontrado nenhum resultado de produtos<br/>Não foi possível montar tabla de produtos<br/>ERRO: -4");
            delete func;
            return;
        }

        this->setRow(func);
    } else {
        switch (*res) {
            case -2:
                QMessageBox::critical(this, "ERRO", "Não foi possível cadastrar o colaborador, erro interno!<br/>ERRO: -2");
                break;
            case -1:
                QMessageBox::critical(this, "ERRO", "Não foi possível cadastrar o colaborador por falta de conexão com o BD!<br/>ERRO: -1");
                break;
            default:
                QMessageBox::critical(this, "ERRO", "Não foi possível cadastrar o colaborador!<br/>ERRO: DESCONHECIDO");
                break;
        }
    }

    this->on_btt_clearColab_clicked();

    delete data;
    delete res;
}


void Fm_Colaboradores::on_le_search_textChanged(const QString &arg1)
{
    QVector<QStringList*>* data = this->DAO->searchFunc(arg1);

    if ((data == nullptr) or (data->empty())) {
        this->clearRows();
        return;
    }

    this->setRows(data);
}


void Fm_Colaboradores::on_btt_refresh_clicked()
{
    this->on_le_search_textChanged(this->ui->le_search->text());
}


void Fm_Colaboradores::on_btt_del_clicked()
{
    if (this->ui->tw_colabs->selectedItems().empty()) {
        QMessageBox::warning(this, "Sem Seleção", "Não há nenhuma linha selecionada!");
        return;
    } else if (QMessageBox::question(this, "Exclusão", "Deseja mesmo deletar o acesso do funcionário selecionado?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::StandardButton::No) return;

    int *res = new int(this->DAO->deleteFunc(this->ui->tw_colabs->item(this->ui->tw_colabs->currentRow(), 0)->text()));

    switch (*res) {
        case -2:
            QMessageBox::critical(this, "ERRO", "Não foi possível cadastrar o colaborador, erro interno!<br/>ERRO: -2");
            break;
        case -1:
            QMessageBox::critical(this, "ERRO", "Não foi possível cadastrar o colaborador por falta de conexão com o BD!<br/>ERRO: -1");
            break;
        case 0:
            QMessageBox::information(this, "Sucesso", "Colaborador não tem mais acesso!");
            break;
        default:
            QMessageBox::critical(this, "ERRO", "Não foi possível cadastrar o colaborador!<br/>ERRO: DESCONHECIDO");
            break;
    }

    this->on_btt_refresh_clicked();

    delete res;
}


void Fm_Colaboradores::on_btt_est_clicked()
{
    if (this->ui->tw_colabs->selectedItems().empty()) {
        QMessageBox::warning(this, "Sem Seleção", "Não há nenhuma linha selecionada!");
        return;
    }

    Fm_Vendas *fmVendas = new Fm_Vendas(this, new int(this->ui->tw_colabs->item(this->ui->tw_colabs->currentRow(), 0)->text().toInt()));
    fmVendas->setModal(true);
    fmVendas->exec();
    delete fmVendas;
}

void Fm_Colaboradores::closeTab(QWidget* tab)
{
    this->ui->tw_main->removeTab(this->ui->tw_main->indexOf(tab));
}

void Fm_Colaboradores::on_btt_edit_clicked()
{
    if (this->ui->tw_colabs->selectedItems().empty()) {
        QMessageBox::warning(this, "Sem Seleção", "Não há nenhuma linha selecionada!");
        return;
    }

    this->ui->tw_main->addTab(new Fm_Colaboradores_Editing(this,
                                                           new QString(this->ui->tw_colabs->item(this->ui->tw_colabs->currentRow(), 0)->text()),
                                                           this->DAO,
                                                           this),
                              this->ui->tw_colabs->item(this->ui->tw_colabs->currentRow(), 1)->text());
}

