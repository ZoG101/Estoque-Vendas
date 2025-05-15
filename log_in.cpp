#include "log_in.h"
#include "ui_log_in.h"

log_in::log_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log_in)
{
    ui->setupUi(this);

    this->id = new int(-1);

    this->logDao = new Log_in_DAO();
    this->user = nullptr;
}

log_in::~log_in()
{
    delete ui;
    delete id;
    delete logDao;
}

int log_in::exec()
{
    QDialog::exec();
    return *this->id;
}

void log_in::on_btt_cancelar_clicked()
{
    this->close();
}


void log_in::on_btt_logar_clicked()
{
    if (this->ui->le_username->text().isEmpty()) {
        QMessageBox::information(this, "Campo vazio!", "O campo de usuário está vazio");
        this->ui->le_username->setFocus();
        return;
    } else if (this->ui->le_senha->text().isEmpty()) {
        QMessageBox::information(this, "Campo vazio!", "O campo de senha está vazio");
        this->ui->le_senha->setFocus();
        return;
    }

    *this->id = this->logDao->valid(this->ui->le_username->text(), this->ui->le_senha->text());

    if (*this->id >= 0) {
        this->user = this->logDao->getUser();
        this->close();
    } else {
        switch (*this->id) {
            case -1:
                QMessageBox::critical(this, "Erro", "Erro ao abrir DB<br/>Erro: -1");
                break;
            case -2:
                QMessageBox::warning(this, "Campo incorreto", "Campo de usuário e/ou de senha incorreto(s)");
                this->ui->le_username->clear();
                this->ui->le_senha->clear();
                this->ui->le_username->setFocus();
                break;
            case -3:
                QMessageBox::critical(this, "Erro", "Erro ao excutar busca<br/>ERRO: -3");
                break;
            default:
                QMessageBox::critical(this, "Erro", "Erro desconhecido<br/>ERRO: ?");
                break;
        }
    }
}

User* log_in::getUser()
{
    return this->user;
}

