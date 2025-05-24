#ifndef FM_VENDASGERAIS_H
#define FM_VENDASGERAIS_H

#include "fm_vendasgerais_dao.h"
#include "qtablewidget.h"

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

private slots:
    void on_tw_sellings_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);

    void on_tw_sellings_itemClicked(QTableWidgetItem *item);

    void on_btt_filter_clicked();

    void on_btt_filterUndo_clicked();

    void on_btt_generatePDF_clicked();

private:
    Ui::Fm_VendasGerais *ui;

    Fm_VendasGerais_DAO* DAO;

    QString* getSaveileName();

    bool* firstTime;

    void setTable();

    void insertValueOnTableSellingsItems(QList<QStringList*>* sellings);

    bool insertValueOnTableSellings(QList<QStringList>* sellings);
};

#endif // FM_VENDASGERAIS_H
