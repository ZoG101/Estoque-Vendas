/********************************************************************************
** Form generated from reading UI file 'fm_colaboradores_editing.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_COLABORADORES_EDITING_H
#define UI_FM_COLABORADORES_EDITING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Fm_Colaboradores_Editing
{
public:
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_name;
    QLineEdit *le_name;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_tel;
    QLineEdit *le_tel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *lbl_username;
    QLineEdit *le_username;
    QVBoxLayout *verticalLayout_4;
    QLabel *lbl_password;
    QLineEdit *le_password;
    QVBoxLayout *verticalLayout_6;
    QLabel *lbl_accessType;
    QComboBox *cb_accessType;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btt_update;
    QPushButton *btt_cancel;

    void setupUi(QDialog *Fm_Colaboradores_Editing)
    {
        if (Fm_Colaboradores_Editing->objectName().isEmpty())
            Fm_Colaboradores_Editing->setObjectName("Fm_Colaboradores_Editing");
        Fm_Colaboradores_Editing->resize(679, 546);
        verticalLayout_8 = new QVBoxLayout(Fm_Colaboradores_Editing);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_name = new QLabel(Fm_Colaboradores_Editing);
        lbl_name->setObjectName("lbl_name");

        verticalLayout->addWidget(lbl_name);

        le_name = new QLineEdit(Fm_Colaboradores_Editing);
        le_name->setObjectName("le_name");

        verticalLayout->addWidget(le_name);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_tel = new QLabel(Fm_Colaboradores_Editing);
        lbl_tel->setObjectName("lbl_tel");

        verticalLayout_2->addWidget(lbl_tel);

        le_tel = new QLineEdit(Fm_Colaboradores_Editing);
        le_tel->setObjectName("le_tel");

        verticalLayout_2->addWidget(le_tel);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        lbl_username = new QLabel(Fm_Colaboradores_Editing);
        lbl_username->setObjectName("lbl_username");

        verticalLayout_5->addWidget(lbl_username);

        le_username = new QLineEdit(Fm_Colaboradores_Editing);
        le_username->setObjectName("le_username");

        verticalLayout_5->addWidget(le_username);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        lbl_password = new QLabel(Fm_Colaboradores_Editing);
        lbl_password->setObjectName("lbl_password");

        verticalLayout_4->addWidget(lbl_password);

        le_password = new QLineEdit(Fm_Colaboradores_Editing);
        le_password->setObjectName("le_password");

        verticalLayout_4->addWidget(le_password);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(horizontalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        lbl_accessType = new QLabel(Fm_Colaboradores_Editing);
        lbl_accessType->setObjectName("lbl_accessType");

        verticalLayout_6->addWidget(lbl_accessType);

        cb_accessType = new QComboBox(Fm_Colaboradores_Editing);
        cb_accessType->addItem(QString());
        cb_accessType->addItem(QString());
        cb_accessType->addItem(QString());
        cb_accessType->setObjectName("cb_accessType");

        verticalLayout_6->addWidget(cb_accessType);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btt_update = new QPushButton(Fm_Colaboradores_Editing);
        btt_update->setObjectName("btt_update");

        horizontalLayout_2->addWidget(btt_update);

        btt_cancel = new QPushButton(Fm_Colaboradores_Editing);
        btt_cancel->setObjectName("btt_cancel");
        btt_cancel->setAutoDefault(false);

        horizontalLayout_2->addWidget(btt_cancel);


        verticalLayout_7->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(verticalLayout_7);

#if QT_CONFIG(shortcut)
        lbl_name->setBuddy(le_name);
        lbl_tel->setBuddy(le_tel);
        lbl_username->setBuddy(le_username);
        lbl_password->setBuddy(le_password);
        lbl_accessType->setBuddy(cb_accessType);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Fm_Colaboradores_Editing);

        QMetaObject::connectSlotsByName(Fm_Colaboradores_Editing);
    } // setupUi

    void retranslateUi(QDialog *Fm_Colaboradores_Editing)
    {
        Fm_Colaboradores_Editing->setWindowTitle(QCoreApplication::translate("Fm_Colaboradores_Editing", "Dialog", nullptr));
        lbl_name->setText(QCoreApplication::translate("Fm_Colaboradores_Editing", "Nome:", nullptr));
        lbl_tel->setText(QCoreApplication::translate("Fm_Colaboradores_Editing", "Telefone:", nullptr));
        lbl_username->setText(QCoreApplication::translate("Fm_Colaboradores_Editing", "Username:", nullptr));
        lbl_password->setText(QCoreApplication::translate("Fm_Colaboradores_Editing", "Senha:", nullptr));
        lbl_accessType->setText(QCoreApplication::translate("Fm_Colaboradores_Editing", "Tipo de Acesso:", nullptr));
        cb_accessType->setItemText(0, QCoreApplication::translate("Fm_Colaboradores_Editing", "Selecione", nullptr));
        cb_accessType->setItemText(1, QCoreApplication::translate("Fm_Colaboradores_Editing", "A", nullptr));
        cb_accessType->setItemText(2, QCoreApplication::translate("Fm_Colaboradores_Editing", "B", nullptr));

        btt_update->setText(QCoreApplication::translate("Fm_Colaboradores_Editing", "Atualizar", nullptr));
        btt_cancel->setText(QCoreApplication::translate("Fm_Colaboradores_Editing", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fm_Colaboradores_Editing: public Ui_Fm_Colaboradores_Editing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_COLABORADORES_EDITING_H
