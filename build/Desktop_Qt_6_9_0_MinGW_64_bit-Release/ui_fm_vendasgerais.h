/********************************************************************************
** Form generated from reading UI file 'fm_vendasgerais.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_VENDASGERAIS_H
#define UI_FM_VENDASGERAIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Fm_VendasGerais
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_from;
    QDateEdit *de_from;
    QLabel *lbl_to;
    QDateEdit *de_to;
    QPushButton *btt_filter;
    QPushButton *btt_filterUndo;
    QVBoxLayout *verticalLayout;
    QTableWidget *tw_sellings;
    QTableWidget *tw_sellingItems;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btt_generatePDF;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Fm_VendasGerais)
    {
        if (Fm_VendasGerais->objectName().isEmpty())
            Fm_VendasGerais->setObjectName("Fm_VendasGerais");
        Fm_VendasGerais->resize(800, 600);
        Fm_VendasGerais->setMinimumSize(QSize(800, 600));
        verticalLayout_3 = new QVBoxLayout(Fm_VendasGerais);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_from = new QLabel(Fm_VendasGerais);
        lbl_from->setObjectName("lbl_from");

        horizontalLayout_2->addWidget(lbl_from);

        de_from = new QDateEdit(Fm_VendasGerais);
        de_from->setObjectName("de_from");

        horizontalLayout_2->addWidget(de_from);


        horizontalLayout->addLayout(horizontalLayout_2);

        lbl_to = new QLabel(Fm_VendasGerais);
        lbl_to->setObjectName("lbl_to");

        horizontalLayout->addWidget(lbl_to);

        de_to = new QDateEdit(Fm_VendasGerais);
        de_to->setObjectName("de_to");

        horizontalLayout->addWidget(de_to);


        horizontalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        btt_filter = new QPushButton(Fm_VendasGerais);
        btt_filter->setObjectName("btt_filter");

        horizontalLayout_4->addWidget(btt_filter);

        btt_filterUndo = new QPushButton(Fm_VendasGerais);
        btt_filterUndo->setObjectName("btt_filterUndo");

        horizontalLayout_4->addWidget(btt_filterUndo);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tw_sellings = new QTableWidget(Fm_VendasGerais);
        if (tw_sellings->columnCount() < 6)
            tw_sellings->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tw_sellings->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tw_sellings->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tw_sellings->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tw_sellings->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tw_sellings->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tw_sellings->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tw_sellings->setObjectName("tw_sellings");

        verticalLayout->addWidget(tw_sellings);

        tw_sellingItems = new QTableWidget(Fm_VendasGerais);
        if (tw_sellingItems->columnCount() < 4)
            tw_sellingItems->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tw_sellingItems->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tw_sellingItems->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tw_sellingItems->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tw_sellingItems->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        tw_sellingItems->setObjectName("tw_sellingItems");

        verticalLayout->addWidget(tw_sellingItems);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btt_generatePDF = new QPushButton(Fm_VendasGerais);
        btt_generatePDF->setObjectName("btt_generatePDF");

        horizontalLayout_5->addWidget(btt_generatePDF);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Fm_VendasGerais);

        QMetaObject::connectSlotsByName(Fm_VendasGerais);
    } // setupUi

    void retranslateUi(QDialog *Fm_VendasGerais)
    {
        Fm_VendasGerais->setWindowTitle(QCoreApplication::translate("Fm_VendasGerais", "Dialog", nullptr));
        lbl_from->setText(QCoreApplication::translate("Fm_VendasGerais", "De:", nullptr));
        lbl_to->setText(QCoreApplication::translate("Fm_VendasGerais", "At\303\251:", nullptr));
        btt_filter->setText(QCoreApplication::translate("Fm_VendasGerais", "Filtrar", nullptr));
        btt_filterUndo->setText(QCoreApplication::translate("Fm_VendasGerais", "Sem Filtro", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tw_sellings->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Fm_VendasGerais", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tw_sellings->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Fm_VendasGerais", "DATA", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tw_sellings->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Fm_VendasGerais", "HORA", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tw_sellings->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Fm_VendasGerais", "COLABORADOR", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tw_sellings->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Fm_VendasGerais", "VALOR TOTAL", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tw_sellings->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Fm_VendasGerais", "PAGAMENTO", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tw_sellingItems->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Fm_VendasGerais", "PRODUTO", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tw_sellingItems->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Fm_VendasGerais", "QUANTIDADE", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tw_sellingItems->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Fm_VendasGerais", "VALOR UN.", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tw_sellingItems->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Fm_VendasGerais", "VALOR TOTAL", nullptr));
        btt_generatePDF->setText(QCoreApplication::translate("Fm_VendasGerais", "Gerar PDF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fm_VendasGerais: public Ui_Fm_VendasGerais {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_VENDASGERAIS_H
