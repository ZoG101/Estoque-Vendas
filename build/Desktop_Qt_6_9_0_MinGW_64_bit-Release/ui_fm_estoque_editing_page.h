/********************************************************************************
** Form generated from reading UI file 'fm_estoque_editing_page.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_ESTOQUE_EDITING_PAGE_H
#define UI_FM_ESTOQUE_EDITING_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Fm_estoque_editing_page
{
public:
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_prodCod;
    QLineEdit *le_prodCod;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_prodName;
    QLineEdit *le_prodName;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbl_prodDesc;
    QLineEdit *le_prodDesc;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *lbl_prodQtt;
    QLineEdit *le_prodQtt;
    QVBoxLayout *verticalLayout_5;
    QLabel *lbl_bValue;
    QDoubleSpinBox *dsb_bValue;
    QVBoxLayout *verticalLayout_6;
    QLabel *lbl_sValue;
    QDoubleSpinBox *dsb_sValue;
    QVBoxLayout *verticalLayout_7;
    QLabel *lbl_supplier;
    QComboBox *cb_supplier;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btt_att;
    QPushButton *btt_cancelar;

    void setupUi(QDialog *Fm_estoque_editing_page)
    {
        if (Fm_estoque_editing_page->objectName().isEmpty())
            Fm_estoque_editing_page->setObjectName("Fm_estoque_editing_page");
        Fm_estoque_editing_page->resize(536, 430);
        Fm_estoque_editing_page->setMinimumSize(QSize(530, 430));
        verticalLayout_9 = new QVBoxLayout(Fm_estoque_editing_page);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_prodCod = new QLabel(Fm_estoque_editing_page);
        lbl_prodCod->setObjectName("lbl_prodCod");

        verticalLayout->addWidget(lbl_prodCod);

        le_prodCod = new QLineEdit(Fm_estoque_editing_page);
        le_prodCod->setObjectName("le_prodCod");

        verticalLayout->addWidget(le_prodCod);


        verticalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_prodName = new QLabel(Fm_estoque_editing_page);
        lbl_prodName->setObjectName("lbl_prodName");

        verticalLayout_2->addWidget(lbl_prodName);

        le_prodName = new QLineEdit(Fm_estoque_editing_page);
        le_prodName->setObjectName("le_prodName");

        verticalLayout_2->addWidget(le_prodName);


        verticalLayout_8->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lbl_prodDesc = new QLabel(Fm_estoque_editing_page);
        lbl_prodDesc->setObjectName("lbl_prodDesc");

        verticalLayout_3->addWidget(lbl_prodDesc);

        le_prodDesc = new QLineEdit(Fm_estoque_editing_page);
        le_prodDesc->setObjectName("le_prodDesc");

        verticalLayout_3->addWidget(le_prodDesc);


        verticalLayout_8->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        lbl_prodQtt = new QLabel(Fm_estoque_editing_page);
        lbl_prodQtt->setObjectName("lbl_prodQtt");

        verticalLayout_4->addWidget(lbl_prodQtt);

        le_prodQtt = new QLineEdit(Fm_estoque_editing_page);
        le_prodQtt->setObjectName("le_prodQtt");

        verticalLayout_4->addWidget(le_prodQtt);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        lbl_bValue = new QLabel(Fm_estoque_editing_page);
        lbl_bValue->setObjectName("lbl_bValue");

        verticalLayout_5->addWidget(lbl_bValue);

        dsb_bValue = new QDoubleSpinBox(Fm_estoque_editing_page);
        dsb_bValue->setObjectName("dsb_bValue");

        verticalLayout_5->addWidget(dsb_bValue);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        lbl_sValue = new QLabel(Fm_estoque_editing_page);
        lbl_sValue->setObjectName("lbl_sValue");

        verticalLayout_6->addWidget(lbl_sValue);

        dsb_sValue = new QDoubleSpinBox(Fm_estoque_editing_page);
        dsb_sValue->setObjectName("dsb_sValue");

        verticalLayout_6->addWidget(dsb_sValue);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        lbl_supplier = new QLabel(Fm_estoque_editing_page);
        lbl_supplier->setObjectName("lbl_supplier");

        verticalLayout_7->addWidget(lbl_supplier);

        cb_supplier = new QComboBox(Fm_estoque_editing_page);
        cb_supplier->setObjectName("cb_supplier");

        verticalLayout_7->addWidget(cb_supplier);


        horizontalLayout->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btt_att = new QPushButton(Fm_estoque_editing_page);
        btt_att->setObjectName("btt_att");

        horizontalLayout_2->addWidget(btt_att);

        btt_cancelar = new QPushButton(Fm_estoque_editing_page);
        btt_cancelar->setObjectName("btt_cancelar");
        btt_cancelar->setAutoDefault(false);

        horizontalLayout_2->addWidget(btt_cancelar);


        verticalLayout_8->addLayout(horizontalLayout_2);


        verticalLayout_9->addLayout(verticalLayout_8);

#if QT_CONFIG(shortcut)
        lbl_prodCod->setBuddy(le_prodCod);
        lbl_prodName->setBuddy(le_prodName);
        lbl_prodDesc->setBuddy(le_prodDesc);
        lbl_prodQtt->setBuddy(le_prodQtt);
        lbl_bValue->setBuddy(dsb_bValue);
        lbl_sValue->setBuddy(dsb_sValue);
        lbl_supplier->setBuddy(cb_supplier);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Fm_estoque_editing_page);

        QMetaObject::connectSlotsByName(Fm_estoque_editing_page);
    } // setupUi

    void retranslateUi(QDialog *Fm_estoque_editing_page)
    {
        Fm_estoque_editing_page->setWindowTitle(QCoreApplication::translate("Fm_estoque_editing_page", "Dialog", nullptr));
        lbl_prodCod->setText(QCoreApplication::translate("Fm_estoque_editing_page", "Cod. Produto", nullptr));
        lbl_prodName->setText(QCoreApplication::translate("Fm_estoque_editing_page", "Nome do Produto", nullptr));
        lbl_prodDesc->setText(QCoreApplication::translate("Fm_estoque_editing_page", "Descri\303\247\303\243o do Produto", nullptr));
        lbl_prodQtt->setText(QCoreApplication::translate("Fm_estoque_editing_page", "Quantidade em Estoque", nullptr));
        lbl_bValue->setText(QCoreApplication::translate("Fm_estoque_editing_page", "Valor de Compra", nullptr));
        lbl_sValue->setText(QCoreApplication::translate("Fm_estoque_editing_page", "Valor de Venda", nullptr));
        lbl_supplier->setText(QCoreApplication::translate("Fm_estoque_editing_page", "Fornecedor", nullptr));
        btt_att->setText(QCoreApplication::translate("Fm_estoque_editing_page", "Atualizar", nullptr));
        btt_cancelar->setText(QCoreApplication::translate("Fm_estoque_editing_page", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fm_estoque_editing_page: public Ui_Fm_estoque_editing_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_ESTOQUE_EDITING_PAGE_H
