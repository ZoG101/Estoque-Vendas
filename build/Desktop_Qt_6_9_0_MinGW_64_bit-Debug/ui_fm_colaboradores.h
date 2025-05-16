/********************************************************************************
** Form generated from reading UI file 'fm_colaboradores.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_COLABORADORES_H
#define UI_FM_COLABORADORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fm_Colaboradores
{
public:
    QVBoxLayout *verticalLayout_11;
    QTabWidget *tw_main;
    QWidget *tab1;
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
    QPushButton *btt_userRegister;
    QPushButton *btt_clearColab;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_search;
    QLineEdit *le_search;
    QTableWidget *tw_colabs;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btt_edit;
    QPushButton *btt_est;
    QPushButton *btt_del;

    void setupUi(QDialog *Fm_Colaboradores)
    {
        if (Fm_Colaboradores->objectName().isEmpty())
            Fm_Colaboradores->setObjectName("Fm_Colaboradores");
        Fm_Colaboradores->resize(800, 600);
        Fm_Colaboradores->setMinimumSize(QSize(800, 600));
        verticalLayout_11 = new QVBoxLayout(Fm_Colaboradores);
        verticalLayout_11->setObjectName("verticalLayout_11");
        tw_main = new QTabWidget(Fm_Colaboradores);
        tw_main->setObjectName("tw_main");
        tab1 = new QWidget();
        tab1->setObjectName("tab1");
        verticalLayout_8 = new QVBoxLayout(tab1);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_name = new QLabel(tab1);
        lbl_name->setObjectName("lbl_name");

        verticalLayout->addWidget(lbl_name);

        le_name = new QLineEdit(tab1);
        le_name->setObjectName("le_name");

        verticalLayout->addWidget(le_name);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_tel = new QLabel(tab1);
        lbl_tel->setObjectName("lbl_tel");

        verticalLayout_2->addWidget(lbl_tel);

        le_tel = new QLineEdit(tab1);
        le_tel->setObjectName("le_tel");

        verticalLayout_2->addWidget(le_tel);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        lbl_username = new QLabel(tab1);
        lbl_username->setObjectName("lbl_username");

        verticalLayout_5->addWidget(lbl_username);

        le_username = new QLineEdit(tab1);
        le_username->setObjectName("le_username");

        verticalLayout_5->addWidget(le_username);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        lbl_password = new QLabel(tab1);
        lbl_password->setObjectName("lbl_password");

        verticalLayout_4->addWidget(lbl_password);

        le_password = new QLineEdit(tab1);
        le_password->setObjectName("le_password");

        verticalLayout_4->addWidget(le_password);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(horizontalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        lbl_accessType = new QLabel(tab1);
        lbl_accessType->setObjectName("lbl_accessType");

        verticalLayout_6->addWidget(lbl_accessType);

        cb_accessType = new QComboBox(tab1);
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
        btt_userRegister = new QPushButton(tab1);
        btt_userRegister->setObjectName("btt_userRegister");

        horizontalLayout_2->addWidget(btt_userRegister);

        btt_clearColab = new QPushButton(tab1);
        btt_clearColab->setObjectName("btt_clearColab");
        btt_clearColab->setAutoDefault(false);

        horizontalLayout_2->addWidget(btt_clearColab);


        verticalLayout_7->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(verticalLayout_7);

        tw_main->addTab(tab1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_10 = new QVBoxLayout(tab_2);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lbl_search = new QLabel(tab_2);
        lbl_search->setObjectName("lbl_search");

        horizontalLayout_4->addWidget(lbl_search);

        le_search = new QLineEdit(tab_2);
        le_search->setObjectName("le_search");

        horizontalLayout_4->addWidget(le_search);


        verticalLayout_9->addLayout(horizontalLayout_4);

        tw_colabs = new QTableWidget(tab_2);
        tw_colabs->setObjectName("tw_colabs");

        verticalLayout_9->addWidget(tw_colabs);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btt_edit = new QPushButton(tab_2);
        btt_edit->setObjectName("btt_edit");
        btt_edit->setAutoDefault(false);

        horizontalLayout_3->addWidget(btt_edit);

        btt_est = new QPushButton(tab_2);
        btt_est->setObjectName("btt_est");
        btt_est->setAutoDefault(false);

        horizontalLayout_3->addWidget(btt_est);

        btt_del = new QPushButton(tab_2);
        btt_del->setObjectName("btt_del");
        btt_del->setAutoDefault(false);

        horizontalLayout_3->addWidget(btt_del);


        verticalLayout_9->addLayout(horizontalLayout_3);


        verticalLayout_10->addLayout(verticalLayout_9);

        tw_main->addTab(tab_2, QString());

        verticalLayout_11->addWidget(tw_main);

#if QT_CONFIG(shortcut)
        lbl_name->setBuddy(le_name);
        lbl_tel->setBuddy(le_tel);
        lbl_username->setBuddy(le_username);
        lbl_password->setBuddy(le_password);
        lbl_accessType->setBuddy(cb_accessType);
        lbl_search->setBuddy(le_search);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Fm_Colaboradores);

        tw_main->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Fm_Colaboradores);
    } // setupUi

    void retranslateUi(QDialog *Fm_Colaboradores)
    {
        Fm_Colaboradores->setWindowTitle(QCoreApplication::translate("Fm_Colaboradores", "Dialog", nullptr));
        lbl_name->setText(QCoreApplication::translate("Fm_Colaboradores", "Nome:", nullptr));
        lbl_tel->setText(QCoreApplication::translate("Fm_Colaboradores", "Telefone:", nullptr));
        lbl_username->setText(QCoreApplication::translate("Fm_Colaboradores", "Username:", nullptr));
        lbl_password->setText(QCoreApplication::translate("Fm_Colaboradores", "Senha:", nullptr));
        lbl_accessType->setText(QCoreApplication::translate("Fm_Colaboradores", "Tipo de Acesso:", nullptr));
        cb_accessType->setItemText(0, QCoreApplication::translate("Fm_Colaboradores", "Selecione", nullptr));
        cb_accessType->setItemText(1, QCoreApplication::translate("Fm_Colaboradores", "A", nullptr));
        cb_accessType->setItemText(2, QCoreApplication::translate("Fm_Colaboradores", "B", nullptr));

        btt_userRegister->setText(QCoreApplication::translate("Fm_Colaboradores", "Registrar", nullptr));
        btt_clearColab->setText(QCoreApplication::translate("Fm_Colaboradores", "Limpar", nullptr));
        tw_main->setTabText(tw_main->indexOf(tab1), QCoreApplication::translate("Fm_Colaboradores", "Adicionar Colaborador", nullptr));
        lbl_search->setText(QCoreApplication::translate("Fm_Colaboradores", "Pesquisar:", nullptr));
        btt_edit->setText(QCoreApplication::translate("Fm_Colaboradores", "Editar", nullptr));
        btt_est->setText(QCoreApplication::translate("Fm_Colaboradores", "Estat\303\255sticas", nullptr));
        btt_del->setText(QCoreApplication::translate("Fm_Colaboradores", "Deletar", nullptr));
        tw_main->setTabText(tw_main->indexOf(tab_2), QCoreApplication::translate("Fm_Colaboradores", "Gest\303\243o de Colaboradores", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fm_Colaboradores: public Ui_Fm_Colaboradores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_COLABORADORES_H
