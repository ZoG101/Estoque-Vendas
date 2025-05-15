/********************************************************************************
** Form generated from reading UI file 'fm_pagamento.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_PAGAMENTO_H
#define UI_FM_PAGAMENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Fm_Pagamento
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *cb_pagamento;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btt_confirm;
    QPushButton *btt_cancel;

    void setupUi(QDialog *Fm_Pagamento)
    {
        if (Fm_Pagamento->objectName().isEmpty())
            Fm_Pagamento->setObjectName("Fm_Pagamento");
        Fm_Pagamento->resize(400, 300);
        verticalLayout = new QVBoxLayout(Fm_Pagamento);
        verticalLayout->setObjectName("verticalLayout");
        cb_pagamento = new QComboBox(Fm_Pagamento);
        cb_pagamento->setObjectName("cb_pagamento");

        verticalLayout->addWidget(cb_pagamento);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btt_confirm = new QPushButton(Fm_Pagamento);
        btt_confirm->setObjectName("btt_confirm");

        horizontalLayout->addWidget(btt_confirm);

        btt_cancel = new QPushButton(Fm_Pagamento);
        btt_cancel->setObjectName("btt_cancel");

        horizontalLayout->addWidget(btt_cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Fm_Pagamento);

        QMetaObject::connectSlotsByName(Fm_Pagamento);
    } // setupUi

    void retranslateUi(QDialog *Fm_Pagamento)
    {
        Fm_Pagamento->setWindowTitle(QCoreApplication::translate("Fm_Pagamento", "Dialog", nullptr));
        btt_confirm->setText(QCoreApplication::translate("Fm_Pagamento", "Confirmar", nullptr));
        btt_cancel->setText(QCoreApplication::translate("Fm_Pagamento", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fm_Pagamento: public Ui_Fm_Pagamento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_PAGAMENTO_H
