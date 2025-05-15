#include "fm_principal.h"
#include "ui_fm_principal.h"
#include "log_in.h"
#include "fm_novavenda.h"
#include "fm_estoque.h"
#include "fm_colaboradores.h"
#include "fm_vendas.h"

Fm_Principal::Fm_Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fm_Principal)
{
    ui->setupUi(this);

    this->bloqueado = new QIcon(":/block/img/img/lock_locked.png");
    this->desbloqueado = new QIcon(":/block/img/img/lock_unlocked.png");

    this->ui->btt_block->setText("");
    this->ui->btt_block->setIcon(*this->bloqueado);

    this->ui->statusbar->addWidget(this->ui->btt_block);
    this->ui->statusbar->addWidget(this->ui->lbl_username);

    this->block = new bool(true);
    this->id = new int(-1);

    this->user = nullptr;
    this->ui->lbl_username->setText("Usuário não logado");
}

Fm_Principal::~Fm_Principal()
{
    delete ui;
    delete id;
    delete bloqueado;
    delete desbloqueado;
    delete block;

    if (user != nullptr) delete user;
}

void Fm_Principal::on_btt_block_clicked()
{
    if (*this->block) {
        log_in *logInPage = new log_in(this);
        logInPage->setModal(true);
        *this->id = logInPage->exec();

        if (*this->id >= 0) {
            this->ui->btt_block->setIcon(*this->desbloqueado);

            if (this->user != nullptr) delete this->user;

            this->user = logInPage->getUser();
            this->ui->lbl_username->setText(this->user->getName());

            *this->block = false;
        }

        delete logInPage;
    } else {

        this->ui->btt_block->setIcon(*this->bloqueado);

        if (this->user != nullptr) {
            delete this->user;
            this->user = nullptr;
        }

        this->ui->lbl_username->setText("Usuário não logado");

        *this->id = -1;
        *this->block = true;
    }
}

bool Fm_Principal::isBlock()
{
    if (*this->block) {
        QMessageBox::warning(this, "Log in", "É necessário fazer login primeiro!<br/>Clique no cadeado vermelho no canto inferior esquerdo.");
        return true;
    }
    return false;
}

AccessType* Fm_Principal::accessControl(const char& type)
{
    AccessType *access;

    switch (type) {
    case AccessType::A:
        access = new AccessType(AccessType::A);
        break;
    case AccessType::B:
        access = new AccessType(AccessType::B);
        break;
    default:
        access =  new AccessType(AccessType::UNDEFINED);
        break;
    }

    return access;
}

bool Fm_Principal::accesValidationTypeB()
{
    AccessType *access = this->accessControl(this->user->getAccess());

    if (*access != AccessType::B) {
        QMessageBox::warning(this, "Acesso negado", "Acesso negado por falta de privilégios");
        delete access;
        return false;
    }

    delete access;
    return true;
}

void Fm_Principal::on_btt_novaVenda_clicked()
{
    if (this->isBlock()) return;

    Fm_NovaVenda *novaVendaPage = new Fm_NovaVenda(this, this->user);
    novaVendaPage->setModal(true);

    this->hide();

    novaVendaPage->exec();

    this->show();
}

void Fm_Principal::on_actionEstoque_triggered()
{
    if (this->isBlock()) return;
    else if (!this->accesValidationTypeB()) return;

    Fm_Estoque *estoquePage = new Fm_Estoque(this);
    estoquePage->setModal(true);

    this->hide();

    estoquePage->exec();

    this->show();

    delete estoquePage;
}

void Fm_Principal::on_actionColaboradores_triggered()
{
    if (this->isBlock()) return;
    else if (!this->accesValidationTypeB()) return;

    Fm_Colaboradores *colaboradoresPage = new Fm_Colaboradores(this);
    colaboradoresPage->setModal(true);

    this->hide();

    colaboradoresPage->exec();

    this->show();

    delete colaboradoresPage;
}

void Fm_Principal::on_actionVendas_triggered()
{
    if (this->isBlock()) return;
    else if (!this->accesValidationTypeB()) return;

    Fm_Vendas *vendasPage = new Fm_Vendas(this);
    vendasPage->setModal(true);

    this->hide();

    vendasPage->exec();

    this->show();

    delete vendasPage;
}

void Fm_Principal::on_actionSobre_triggered()
{
    QMessageBox::about(this, "Sobre", "É um programa de teste de controle de estoque");
}

void Fm_Principal::on_actionSair_triggered()
{
    this->close();
}

