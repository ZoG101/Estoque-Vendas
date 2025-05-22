#include "fm_colaboradores_editing.h"
#include "ui_fm_colaboradores_editing.h"

#include <QMessageBox>

Fm_Colaboradores_Editing::Fm_Colaboradores_Editing(QWidget *parent, QString* editingId, Fm_Colaboradores_DAO* DAO, Fm_Colaboradores* father)
    : QDialog(parent)
    , ui(new Ui::Fm_Colaboradores_Editing)
{
    ui->setupUi(this);

    this->editingId = editingId;
    this->DAO = DAO;
    this->father = father;

    this->setUser();
}

Fm_Colaboradores_Editing::~Fm_Colaboradores_Editing()
{
    delete ui;
    delete editingId;
}

bool Fm_Colaboradores_Editing::verifyBlank()
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

void Fm_Colaboradores_Editing::on_btt_cancel_clicked()
{
    this->father->closeTab(this, this->editingId);
    this->close();
}

void Fm_Colaboradores_Editing::setUser()
{
    int *id = new int(this->editingId->toInt());

    QStringList* func = this->DAO->getFunc(id);

    if (func == nullptr) {
        QMessageBox::critical(this, "Erro", "Erro ao excutar busca de usuário<br/>ERRO: -3");
        delete id;
        this->on_btt_cancel_clicked();
        return;
    } else if (func->empty()) {
        QMessageBox::critical(this, "Erro", "Não foi encontrado nenhum resultado de usuário<br/>ERRO: -4");
        delete func;
        delete id;
        this->on_btt_cancel_clicked();
        return;
    }

    this->ui->le_name->setText(func->at(1));
    this->ui->le_username->setText(func->at(2));
    this->ui->le_password->setText(func->at(3));
    this->ui->le_tel->setText(func->at(4));
    this->ui->cb_accessType->setCurrentText(func->at(5));

    delete id;
    delete func;
}

void Fm_Colaboradores_Editing::on_btt_update_clicked()
{
    if (this->verifyBlank()) return;

    std::array<QString, 5>* data = new std::array<QString, 5>({this->ui->le_name->text(),
                                                               this->ui->le_tel->text(),
                                                               this->ui->le_username->text(),
                                                               this->ui->le_password->text(),
                                                               this->ui->cb_accessType->currentText()});

    switch (this->DAO->updateUser(data, this->editingId)) {
        case -2:
            QMessageBox::critical(this, "ERRO", "Não foi possível atualizar o colaborador, erro interno!<br/>ERRO: -2");
            delete data;
            break;
        case -1:
            QMessageBox::critical(this, "ERRO", "Não foi possível atualizar o colaborador por falta de conexão com o BD!<br/>ERRO: -1");
            delete data;
            break;
        case 0:
            QMessageBox::information(this, "Sucesso!", "O usuário foi atualizado com sucesso!");
            delete data;
            this->father->closeTab(this, this->editingId);
            this->close();
            break;
        default:
            QMessageBox::critical(this, "ERRO", "Não foi possível atualizar o colaborador!<br/>ERRO: DESCONHECIDO");
            delete data;
            break;
    }
}

