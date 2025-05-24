#include "fm_vendasgerais.h"
#include "ui_fm_vendasgerais.h"

#include <QDesktopServices>
#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QDir>

Fm_VendasGerais::Fm_VendasGerais(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Fm_VendasGerais)
{
    ui->setupUi(this);

    this->DAO = new Fm_VendasGerais_DAO();
    this->firstTime = new bool(true);

    this->setTable();
    this->ui->tw_sellings->selectRow(0);
    this->on_tw_sellings_itemClicked(nullptr);
}

Fm_VendasGerais::~Fm_VendasGerais()
{
    delete ui;
    delete DAO;
    delete firstTime;
}

bool Fm_VendasGerais::insertValueOnTableSellings(QList<QStringList>* sellings)
{
    try {
        if (this->ui->tw_sellings->rowCount() > 0) {
            for (int i = 0; i < this->ui->tw_sellings->rowCount(); i++)
                this->ui->tw_sellings->removeRow(i);

            this->ui->tw_sellings->setRowCount(-1);
        }
    } catch (...) {
        return false;
    }

    try {
        for (int i = 0; i < sellings->size(); i++) {
            this->ui->tw_sellings->setRowCount(i);
            this->ui->tw_sellings->insertRow(i);
            this->ui->tw_sellings->setItem(i, 0, new QTableWidgetItem(sellings->at(i).at(0)));
            this->ui->tw_sellings->setItem(i, 1, new QTableWidgetItem(sellings->at(i).at(1)));
            this->ui->tw_sellings->setItem(i, 2, new QTableWidgetItem(sellings->at(i).at(2)));
            this->ui->tw_sellings->setItem(i, 3, new QTableWidgetItem(sellings->at(i).at(3)));
            this->ui->tw_sellings->setItem(i, 4, new QTableWidgetItem(sellings->at(i).at(4)));
            this->ui->tw_sellings->setItem(i, 5, new QTableWidgetItem(sellings->at(i).at(5)));
        }
    } catch (...) {
        return false;
    }

    return true;
}

void Fm_VendasGerais::setTable()
{
    QList<QStringList>* sellings = this->DAO->getAllVendas();

    if (sellings == nullptr) {
        QMessageBox::critical(this, "ERRO", "Não foi possível montar a tabela!<br/> ERRO: -3");
        this->close();
        return;
    } else if (sellings->empty()) {
        QMessageBox::critical(this, "ERRO", "Não foi possível montar a tabela!<br/> ERRO: -4");
        delete sellings;
        this->close();
        return;
    }

    if (!this->insertValueOnTableSellings(sellings)) {
        QMessageBox::critical(this, "ERRO", "Não foi possível montar a tabela!<br/> ERRO: -6");
        sellings->clear();
        delete sellings;
        this->close();
        return;
    }

    if (*this->firstTime) {
        this->ui->tw_sellings->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
        this->ui->tw_sellings->setEditTriggers(QAbstractItemView::NoEditTriggers);
        this->ui->tw_sellings->setSelectionBehavior(QAbstractItemView::SelectRows);
        this->ui->tw_sellings->verticalHeader()->setVisible(false);

        this->ui->tw_sellingItems->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
        this->ui->tw_sellingItems->setEditTriggers(QAbstractItemView::NoEditTriggers);
        this->ui->tw_sellingItems->setSelectionBehavior(QAbstractItemView::SelectRows);
        this->ui->tw_sellingItems->verticalHeader()->setVisible(false);

        *this->firstTime = false;
    }

    sellings->clear();
    delete sellings;
}

void Fm_VendasGerais::insertValueOnTableSellingsItems(QList<QStringList*>* sellings)
{

    if (this->ui->tw_sellingItems->rowCount() > 0) {
        for (int i = 0; i < this->ui->tw_sellingItems->rowCount(); i++)
            this->ui->tw_sellingItems->removeRow(i);

        this->ui->tw_sellingItems->setRowCount(-1);
    }

    for (int i = 0; i < sellings->size(); i++) {
        this->ui->tw_sellingItems->setRowCount(i);
        this->ui->tw_sellingItems->insertRow(i);
        this->ui->tw_sellingItems->setItem(i, 0, new QTableWidgetItem(sellings->at(i)->at(0)));
        this->ui->tw_sellingItems->setItem(i, 1, new QTableWidgetItem(sellings->at(i)->at(1)));
        this->ui->tw_sellingItems->setItem(i, 2, new QTableWidgetItem(sellings->at(i)->at(2)));
        this->ui->tw_sellingItems->setItem(i, 3, new QTableWidgetItem(QString::number(sellings->at(i)->at(2).toDouble() * sellings->at(i)->at(1).toDouble())));
    }
}

void Fm_VendasGerais::on_tw_sellings_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous)
{
    return;
}

void Fm_VendasGerais::on_tw_sellings_itemClicked(QTableWidgetItem *item)
{
    if (this->ui->tw_sellings->selectedItems().empty()) return;

    QList<QStringList*>* data = this->DAO->getSellingProds(new int(this->ui->tw_sellings->selectedItems().at(0)->text().toInt()));

    if (data == nullptr) {
        return;
    } else if (data->empty()) {
        delete data;
        return;
    }

    this->insertValueOnTableSellingsItems(data);

    foreach (const auto& i, *data)
        delete i;
    data->clear();
    delete data;
}

void Fm_VendasGerais::on_btt_filter_clicked()
{
    if (!(this->ui->de_from->date().year() > this->ui->de_to->date().year())) {
        if (this->ui->de_from->date().year() == this->ui->de_to->date().year()) {
            if (this->ui->de_from->date().month() > this->ui->de_to->date().month()) {
                QMessageBox::critical(this, "ERRO", "Data invávida!<br/>Datas primeira data superior a segunda.");
                return;
            } else if ((this->ui->de_from->date().day() > this->ui->de_to->date().day()) and (this->ui->de_from->date().month() > this->ui->de_to->date().month())) {
                QMessageBox::critical(this, "ERRO", "Data invávida!<br/>Datas primeira data superior a segunda.");
                return;
            }
        }

        qDebug() << this->ui->de_from->date().toString("yyyy-MM-dd");
        QList<QStringList>* data = this->DAO->getSellingPeriod(this->ui->de_from->date().toString("yyyy-MM-dd"), this->ui->de_to->date().toString("yyyy-MM-dd"));

        if (data == nullptr) {
            QMessageBox::warning(this, "Nada encontrado", "Não foi encontrado nenhum registro de venda dentro do período selecionado.");
            return;
        } else if (data->empty()) {
            QMessageBox::warning(this, "Nada encontrado", "Não foi encontrado nenhum registro de venda dentro do período selecionado.");
            delete data;
            return;
        }

        this->insertValueOnTableSellings(data);

        delete data;
    } else {
        QMessageBox::critical(this, "ERRO", "Data invávida!<br/>Datas primeira data superior a segunda.");
    }
}

void Fm_VendasGerais::on_btt_filterUndo_clicked()
{
    this->setTable();
}

QString* Fm_VendasGerais::getSaveileName()
{
    QString* path = new QString(QFileDialog::getSaveFileName(this, "Salvar como", QDir::homePath(), "Arquivos PDF (*.pdf)"));

    if (*path == "") return nullptr;
    else return path;
}

void Fm_VendasGerais::on_btt_generatePDF_clicked()
{
    QString* path = new QString(QFileDialog::getSaveFileName(this, "Salvar como", QDir::homePath(), "Arquivos PDF (*.pdf)"));

    if (path == nullptr) return;

    QPrinter* printer = new QPrinter();
    printer->setOutputFormat(QPrinter::PdfFormat);
    printer->setOutputFileName(*path);

    QPainter* painter = new QPainter();

    if (!painter->begin(printer)) {
        QMessageBox::critical(this, "ERRO", "Erro ao abrir local do arquivo!");

        delete painter;
        delete printer;
        delete path;

        return;
    }

    this->ui->tw_sellings->render(painter);

    printer->newPage();

    this->ui->tw_sellingItems->render(painter);

    painter->end();

    QDesktopServices::openUrl(QUrl("file:///" + *path));

    delete painter;
    delete printer;
    delete path;

    this->ui->tw_sellings->selectRow(0);
}

