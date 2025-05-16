#ifndef FM_COLABORADORES_H
#define FM_COLABORADORES_H

#include <QDialog>

#include "fm_colaboradores_dao.h"

namespace Ui {
class Fm_Colaboradores;
}

class Fm_Colaboradores : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_Colaboradores(QWidget *parent = nullptr);
    ~Fm_Colaboradores();

private slots:
    void on_btt_clearColab_clicked();

    void on_btt_userRegister_clicked();

private:
    Ui::Fm_Colaboradores *ui;

    Fm_Colaboradores_DAO *DAO;

    bool verifyBlank();
};

#endif // FM_COLABORADORES_H
