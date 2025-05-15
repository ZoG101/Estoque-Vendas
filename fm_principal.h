#ifndef FM_PRINCIPAL_H
#define FM_PRINCIPAL_H

#include <QApplication>
#include <QMessageBox>
#include <QMainWindow>

#include "accesstype.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Fm_Principal;
}
QT_END_NAMESPACE

class Fm_Principal : public QMainWindow
{
    Q_OBJECT

public:
    Fm_Principal(QWidget *parent = nullptr);
    ~Fm_Principal();

private slots:
    void on_btt_block_clicked();

    void on_btt_novaVenda_clicked();

    void on_actionSobre_triggered();

    void on_actionEstoque_triggered();

    void on_actionColaboradores_triggered();

    void on_actionVendas_triggered();

    void on_actionSair_triggered();

private:
    bool isBlock();
    bool accesValidationTypeB();
    AccessType* accessControl(const char& type);

    Ui::Fm_Principal *ui;

    bool *block;
    int *id;

    QIcon *bloqueado;
    QIcon *desbloqueado;

    User *user;
};
#endif // FM_PRINCIPAL_H
