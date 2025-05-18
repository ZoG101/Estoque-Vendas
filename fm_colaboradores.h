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

    void on_le_search_textChanged(const QString &arg1);

    void on_btt_refresh_clicked();

    void on_btt_del_clicked();

    void on_btt_est_clicked();

private:
    Ui::Fm_Colaboradores *ui;

    Fm_Colaboradores_DAO *DAO;

    bool verifyBlank();

    void setTable();

    void setRows(QVector<QStringList*>* data);

    void setRow(QStringList* data);

    void clearRows();
};

#endif // FM_COLABORADORES_H
