/********************************************************************************
** Form generated from reading UI file 'fm_novavenda.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_NOVAVENDA_H
#define UI_FM_NOVAVENDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Fm_NovaVenda
{
public:
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbl_qtde;
    QLineEdit *le_qtde;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_codProd;
    QLineEdit *le_codProd;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QPushButton *btt_pesquisar;
    QHBoxLayout *mainLayout;
    QTableWidget *tw_produtos;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_name;
    QLabel *lbl_desc;
    QLabel *lbl_prodQtde;
    QLabel *lbl_sellingValue;
    QPushButton *btt_confirmAdding;
    QVBoxLayout *verticalLayout_4;
    QLabel *lbl_total;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btt_delete;
    QPushButton *btt_edit;
    QPushButton *btt_sell;

    void setupUi(QDialog *Fm_NovaVenda)
    {
        if (Fm_NovaVenda->objectName().isEmpty())
            Fm_NovaVenda->setObjectName("Fm_NovaVenda");
        Fm_NovaVenda->resize(800, 600);
        Fm_NovaVenda->setMinimumSize(QSize(800, 600));
        verticalLayout_7 = new QVBoxLayout(Fm_NovaVenda);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, -1, 10, -1);
        lbl_qtde = new QLabel(Fm_NovaVenda);
        lbl_qtde->setObjectName("lbl_qtde");

        verticalLayout_3->addWidget(lbl_qtde);

        le_qtde = new QLineEdit(Fm_NovaVenda);
        le_qtde->setObjectName("le_qtde");
        le_qtde->setStyleSheet(QString::fromUtf8("height: 1.2em;\n"
"border-radius: 5px;"));

        verticalLayout_3->addWidget(le_qtde);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(44, -1, -1, -1);
        lbl_codProd = new QLabel(Fm_NovaVenda);
        lbl_codProd->setObjectName("lbl_codProd");

        verticalLayout_2->addWidget(lbl_codProd);

        le_codProd = new QLineEdit(Fm_NovaVenda);
        le_codProd->setObjectName("le_codProd");
        le_codProd->setStyleSheet(QString::fromUtf8("height: 1.2em;\n"
"border-radius: 5px;"));

        verticalLayout_2->addWidget(le_codProd);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label = new QLabel(Fm_NovaVenda);
        label->setObjectName("label");

        verticalLayout_5->addWidget(label);

        btt_pesquisar = new QPushButton(Fm_NovaVenda);
        btt_pesquisar->setObjectName("btt_pesquisar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btt_pesquisar->sizePolicy().hasHeightForWidth());
        btt_pesquisar->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(btt_pesquisar);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_2);

        mainLayout = new QHBoxLayout();
        mainLayout->setObjectName("mainLayout");
        tw_produtos = new QTableWidget(Fm_NovaVenda);
        if (tw_produtos->columnCount() < 5)
            tw_produtos->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tw_produtos->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tw_produtos->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tw_produtos->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tw_produtos->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tw_produtos->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tw_produtos->setObjectName("tw_produtos");

        mainLayout->addWidget(tw_produtos);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_name = new QLabel(Fm_NovaVenda);
        lbl_name->setObjectName("lbl_name");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_name->sizePolicy().hasHeightForWidth());
        lbl_name->setSizePolicy(sizePolicy1);
        lbl_name->setStyleSheet(QString::fromUtf8("text-align: start;"));
        lbl_name->setTextFormat(Qt::TextFormat::PlainText);
        lbl_name->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(lbl_name);

        lbl_desc = new QLabel(Fm_NovaVenda);
        lbl_desc->setObjectName("lbl_desc");
        lbl_desc->setStyleSheet(QString::fromUtf8("text-align: start;"));
        lbl_desc->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(lbl_desc);

        lbl_prodQtde = new QLabel(Fm_NovaVenda);
        lbl_prodQtde->setObjectName("lbl_prodQtde");
        lbl_prodQtde->setStyleSheet(QString::fromUtf8("text-align: start;"));
        lbl_prodQtde->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(lbl_prodQtde);

        lbl_sellingValue = new QLabel(Fm_NovaVenda);
        lbl_sellingValue->setObjectName("lbl_sellingValue");
        lbl_sellingValue->setStyleSheet(QString::fromUtf8("text-align: start;"));
        lbl_sellingValue->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(lbl_sellingValue);

        btt_confirmAdding = new QPushButton(Fm_NovaVenda);
        btt_confirmAdding->setObjectName("btt_confirmAdding");
        btt_confirmAdding->setStyleSheet(QString::fromUtf8(""));
        btt_confirmAdding->setAutoDefault(false);

        verticalLayout->addWidget(btt_confirmAdding);


        mainLayout->addLayout(verticalLayout);


        verticalLayout_6->addLayout(mainLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        lbl_total = new QLabel(Fm_NovaVenda);
        lbl_total->setObjectName("lbl_total");

        verticalLayout_4->addWidget(lbl_total);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btt_delete = new QPushButton(Fm_NovaVenda);
        btt_delete->setObjectName("btt_delete");
        btt_delete->setAutoDefault(false);

        horizontalLayout_3->addWidget(btt_delete);

        btt_edit = new QPushButton(Fm_NovaVenda);
        btt_edit->setObjectName("btt_edit");
        btt_edit->setAutoDefault(false);

        horizontalLayout_3->addWidget(btt_edit);

        btt_sell = new QPushButton(Fm_NovaVenda);
        btt_sell->setObjectName("btt_sell");
        btt_sell->setAutoDefault(false);

        horizontalLayout_3->addWidget(btt_sell);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(verticalLayout_6);

#if QT_CONFIG(shortcut)
        lbl_qtde->setBuddy(le_qtde);
        lbl_codProd->setBuddy(le_codProd);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(le_qtde, le_codProd);
        QWidget::setTabOrder(le_codProd, btt_delete);
        QWidget::setTabOrder(btt_delete, btt_pesquisar);
        QWidget::setTabOrder(btt_pesquisar, btt_sell);
        QWidget::setTabOrder(btt_sell, btt_edit);
        QWidget::setTabOrder(btt_edit, tw_produtos);

        retranslateUi(Fm_NovaVenda);

        QMetaObject::connectSlotsByName(Fm_NovaVenda);
    } // setupUi

    void retranslateUi(QDialog *Fm_NovaVenda)
    {
        Fm_NovaVenda->setWindowTitle(QCoreApplication::translate("Fm_NovaVenda", "Dialog", nullptr));
        lbl_qtde->setText(QCoreApplication::translate("Fm_NovaVenda", "Quantidade:", nullptr));
        lbl_codProd->setText(QCoreApplication::translate("Fm_NovaVenda", "C\303\263digo do produto:", nullptr));
        label->setText(QString());
        btt_pesquisar->setText(QCoreApplication::translate("Fm_NovaVenda", "Pesquisar", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tw_produtos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Fm_NovaVenda", "Cod. Produto", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tw_produtos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Fm_NovaVenda", "Produto", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tw_produtos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Fm_NovaVenda", "Quantidade", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tw_produtos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Fm_NovaVenda", "Valor Un.", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tw_produtos->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Fm_NovaVenda", "Valor Total", nullptr));
        lbl_name->setText(QCoreApplication::translate("Fm_NovaVenda", "Nome: ", nullptr));
        lbl_desc->setText(QCoreApplication::translate("Fm_NovaVenda", "Desc:", nullptr));
        lbl_prodQtde->setText(QCoreApplication::translate("Fm_NovaVenda", "Quantidade em estoque:", nullptr));
        lbl_sellingValue->setText(QCoreApplication::translate("Fm_NovaVenda", "Valor de venda: ", nullptr));
        btt_confirmAdding->setText(QCoreApplication::translate("Fm_NovaVenda", "Confirmar adi\303\247\303\243o", nullptr));
        lbl_total->setText(QCoreApplication::translate("Fm_NovaVenda", "Valor Total: R$...", nullptr));
        btt_delete->setText(QCoreApplication::translate("Fm_NovaVenda", "Excluir", nullptr));
        btt_edit->setText(QCoreApplication::translate("Fm_NovaVenda", "Editar", nullptr));
        btt_sell->setText(QCoreApplication::translate("Fm_NovaVenda", "Finalizar Venda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fm_NovaVenda: public Ui_Fm_NovaVenda {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_NOVAVENDA_H
