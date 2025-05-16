#include "fm_colaboradores.h"
#include "ui_fm_colaboradores.h"

#include <QMessageBox>

Fm_Colaboradores::Fm_Colaboradores(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Fm_Colaboradores)
{
    ui->setupUi(this);

    this->DAO = new Fm_Colaboradores_DAO();
}

Fm_Colaboradores::~Fm_Colaboradores()
{
    delete ui;
    delete DAO;
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

    switch (*res) {
        case -2:
            QMessageBox::critical(this, "ERRO", "Não foi possível cadastrar o colaborador, erro interno!<br/>ERRO: -2");
            break;
        case -1:
            QMessageBox::critical(this, "ERRO", "Não foi possível cadastrar o colaborador por falta de conexão com o BD!<br/>ERRO: -1");
            break;
        case 0:
            QMessageBox::information(this, "Sucesso!", "Colaborador cadastrado com sucesso!");
            break;
        default:
            QMessageBox::critical(this, "ERRO", "Não foi possível cadastrar o colaborador!<br/>ERRO: DESCONHECIDO");
            break;
    }

    this->on_btt_clearColab_clicked();

    delete data;
    delete res;
}

