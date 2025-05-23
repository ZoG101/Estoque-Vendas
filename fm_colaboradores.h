#ifndef FM_COLABORADORES_H
#define FM_COLABORADORES_H

#include <QDialog>
#include <map>

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

    void closeTab(QWidget *tab, QString* id);

private slots:
    void on_btt_clearColab_clicked();

    void on_btt_userRegister_clicked();

    void on_le_search_textChanged(const QString &arg1);

    void on_btt_refresh_clicked();

    void on_btt_del_clicked();

    void on_btt_est_clicked();

    void on_btt_edit_clicked();

private:
    Ui::Fm_Colaboradores *ui;

    Fm_Colaboradores_DAO *DAO;

    std::map<QString, QWidget*>* editingMap;

    bool verifyBlank();

    void setTable();

    void setRows(QVector<QStringList*>* data);

    void setRow(QStringList* data);

    void clearRows();
};

#endif // FM_COLABORADORES_H
