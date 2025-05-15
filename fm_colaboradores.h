#ifndef FM_COLABORADORES_H
#define FM_COLABORADORES_H

#include <QDialog>

namespace Ui {
class Fm_Colaboradores;
}

class Fm_Colaboradores : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_Colaboradores(QWidget *parent = nullptr);
    ~Fm_Colaboradores();

private:
    Ui::Fm_Colaboradores *ui;
};

#endif // FM_COLABORADORES_H
