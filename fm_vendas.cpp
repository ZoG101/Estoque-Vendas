#include "fm_vendas.h"
#include "ui_fm_vendas.h"

#include <QMessageBox>
#include <QDateTime>

Fm_Vendas::Fm_Vendas(QWidget *parent, int *id)
    : QDialog(parent)
    , ui(new Ui::Fm_Vendas)
{
    ui->setupUi(this);

    this->id = id;
    this->DAO = new Fm_Vendas_DAO();
    this->axisX = nullptr;
    this->axisY = nullptr;

    series = new QLineSeries();

    this->chart = new QChart();
    this->chart->addSeries(this->series);
    this->chart->createDefaultAxes();
    this->chart->setTheme(QChart::ChartTheme::ChartThemeDark);
    this->chart->setAnimationOptions(QChart::AnimationOption::AllAnimations);

    this->chartView = new QChartView(this->chart);
    this->chartView->setRenderHint(QPainter::Antialiasing);

    this->oneYear = new QRadioButton("1 - ano", this);
    this->oneMonth = new QRadioButton("1 - mês", this);
    this->oneWeek = new QRadioButton("1 - semana", this);

    this->layout = new QVBoxLayout();
    this->layout->addWidget(this->chartView);
    this->layout->addWidget(this->oneYear);
    this->layout->addWidget(this->oneMonth);
    this->layout->addWidget(this->oneWeek);
    this->setLayout(layout);

    connect(this->oneYear, SIGNAL(clicked()), this, SLOT(oneYear_clicked()));
    connect(this->oneMonth, SIGNAL(clicked()), this, SLOT(oneMonth_clicked()));
    connect(this->oneWeek, SIGNAL(clicked()), this, SLOT(oneWeek_clicked()));

    this->oneYear->click();
}

Fm_Vendas::~Fm_Vendas()
{
    delete ui;
    delete oneYear;
    delete oneMonth;
    delete oneWeek;
    delete series;
    delete chart;
    delete chartView;
    delete layout;
    delete id;
    delete DAO;
}

void Fm_Vendas::setAxis(QVector<QStringList*>* data)
{
    this->series->clear();

    QList<QAbstractAxis*>* eixos = new QList<QAbstractAxis*>(chart->axes());
    foreach (QAbstractAxis *eixo, *eixos) {
        chart->removeAxis(eixo);
        delete eixo;
    }

    delete this->series;
    this->series = new QLineSeries();
    this->chart->addSeries(this->series);

    this->axisX = new QDateTimeAxis();
    this->axisY = new QValueAxis();

    this->axisX->setTitleText("Data");
    this->axisX->setFormat("dd/MM");
    this->axisX->setTickCount(5);
    this->axisX->setRange(QDateTime::fromString(data->at(0)->at(0)), QDateTime::fromString(data->at(data->size() - 1)->at(0)));

    this->axisY->setTitleText("Total/Dia");
    this->axisY->setRange(0, data->at(data->size() - 1)->at(1).toDouble());

    this->chart->addAxis(this->axisX, Qt::AlignBottom);
    this->chart->addAxis(this->axisY, Qt::AlignLeft);

    this->series->attachAxis(this->axisX);
    this->series->attachAxis(this->axisY);

    for (int i = 0; i < data->size(); i++) {
        this->series->append(QDateTime::fromString(data->at(i)->at(0)).toMSecsSinceEpoch(),
                             data->at(i)->at(1).toDouble());

        if (this->axisY->max() < data->at(i)->at(1).toDouble())
            this->axisY->setMax(data->at(i)->at(1).toDouble());
    }

    this->chartView->update();
    this->chartView->repaint();

    delete eixos;
}

void Fm_Vendas::oneYear_clicked()
{
    QVector<QStringList*>* data = this->DAO->getData('Y', this->id);

    if ((data == nullptr) or (data->empty())) {
        QMessageBox::warning(this, "Sem dados", "Colaborador não possui dados!");
        return;
    }

    this->setAxis(data);

    foreach (const auto& i, *data)
        delete i;
    delete data;
}

void Fm_Vendas::oneMonth_clicked()
{
    QVector<QStringList*>* data = this->DAO->getData('M', this->id);

    if ((data == nullptr) or (data->empty())) {
        QMessageBox::warning(this, "Sem dados", "Colaborador não possui dados!");
        return;
    }

    this->setAxis(data);

    foreach (const auto& i, *data)
        delete i;
    delete data;
}

void Fm_Vendas::oneWeek_clicked()
{
    QVector<QStringList*>* data = this->DAO->getData('W', this->id);

    if ((data == nullptr) or (data->empty())) {
        QMessageBox::warning(this, "Sem dados", "Colaborador não possui dados!");
        return;
    }

    this->setAxis(data);

    foreach (const auto& i, *data)
        delete i;
    delete data;
}
