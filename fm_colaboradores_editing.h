#ifndef FM_COLABORADORES_EDITING_H
#define FM_COLABORADORES_EDITING_H

#include "fm_colaboradores.h"
#include "fm_colaboradores_dao.h"

#include <QDialog>

namespace Ui {
class Fm_Colaboradores_Editing;
}

class Fm_Colaboradores_Editing : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_Colaboradores_Editing(QWidget *parent = nullptr, QString* editingId = nullptr, Fm_Colaboradores_DAO* DAO = nullptr, Fm_Colaboradores* father = nullptr);

    ~Fm_Colaboradores_Editing();

private slots:
    void on_btt_cancel_clicked();

    void on_btt_update_clicked();

private:
    Ui::Fm_Colaboradores_Editing *ui;

    QString* editingId;

    Fm_Colaboradores* father;

    Fm_Colaboradores_DAO* DAO;

    bool verifyBlank();

    void setUser();
};

#endif // FM_COLABORADORES_EDITING_H
