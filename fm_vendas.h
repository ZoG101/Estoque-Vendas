#ifndef FM_VENDAS_H
#define FM_VENDAS_H

#include <QDialog>

namespace Ui {
class Fm_Vendas;
}

class Fm_Vendas : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_Vendas(QWidget *parent = nullptr);
    ~Fm_Vendas();

private:
    Ui::Fm_Vendas *ui;
};

#endif // FM_VENDAS_H
