#ifndef FM_VENDASGERAIS_H
#define FM_VENDASGERAIS_H

#include <QDialog>

namespace Ui {
class Fm_VendasGerais;
}

class Fm_VendasGerais : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_VendasGerais(QWidget *parent = nullptr);
    ~Fm_VendasGerais();

private:
    Ui::Fm_VendasGerais *ui;
};

#endif // FM_VENDASGERAIS_H
