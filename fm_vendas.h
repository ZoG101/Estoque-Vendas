#ifndef FM_VENDAS_H
#define FM_VENDAS_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QDialog>

#include "qboxlayout.h"
#include "qradiobutton.h"
#include "fm_vendas_dao.h"

namespace Ui {
class Fm_Vendas;
}

class Fm_Vendas : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_Vendas(QWidget *parent = nullptr, int *id = nullptr);

    ~Fm_Vendas();

private slots:
    void oneYear_clicked();

    void oneMonth_clicked();

    void oneWeek_clicked();

private:
    Ui::Fm_Vendas *ui;

    QLineSeries *series;

    QChart *chart;

    QChartView *chartView;

    QRadioButton* oneYear;

    QRadioButton* oneWeek;

    QRadioButton* oneMonth;

    QVBoxLayout *layout;

    Fm_Vendas_DAO* DAO;

    QDateTimeAxis *axisX;

    QValueAxis *axisY;

    int *id;

    void setAxis(QVector<QStringList*>* data);
};

#endif // FM_VENDAS_H
