#ifndef LOG_IN_H
#define LOG_IN_H

#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDialog>

#include "log_in_dao.h"
#include "user.h"

namespace Ui {
class log_in;
}

class log_in : public QDialog
{
    Q_OBJECT

public:
    explicit log_in(QWidget *parent = nullptr);
    ~log_in();

    User* getUser();

public slots:
    int exec() override;

private slots:
    void on_btt_cancelar_clicked();

    void on_btt_logar_clicked();

private:
    Ui::log_in *ui;

    Log_in_DAO *logDao;
    User *user;

    int *id;
};

#endif // LOG_IN_H
