/********************************************************************************
** Form generated from reading UI file 'fm_vendas.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_VENDAS_H
#define UI_FM_VENDAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Fm_Vendas
{
public:

    void setupUi(QDialog *Fm_Vendas)
    {
        if (Fm_Vendas->objectName().isEmpty())
            Fm_Vendas->setObjectName("Fm_Vendas");
        Fm_Vendas->resize(400, 300);

        retranslateUi(Fm_Vendas);

        QMetaObject::connectSlotsByName(Fm_Vendas);
    } // setupUi

    void retranslateUi(QDialog *Fm_Vendas)
    {
        Fm_Vendas->setWindowTitle(QCoreApplication::translate("Fm_Vendas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fm_Vendas: public Ui_Fm_Vendas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_VENDAS_H
