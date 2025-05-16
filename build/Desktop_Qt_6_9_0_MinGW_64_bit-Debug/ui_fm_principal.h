/********************************************************************************
** Form generated from reading UI file 'fm_principal.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_PRINCIPAL_H
#define UI_FM_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fm_Principal
{
public:
    QAction *actionEstoque;
    QAction *actionColaboradores;
    QAction *actionVendas;
    QAction *actionSobre;
    QAction *actionSair;
    QWidget *centralwidget;
    QPushButton *btt_novaVenda;
    QPushButton *btt_block;
    QLabel *lbl_username;
    QMenuBar *menubar;
    QMenu *menuGest_o;
    QMenu *menuSistema;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Fm_Principal)
    {
        if (Fm_Principal->objectName().isEmpty())
            Fm_Principal->setObjectName("Fm_Principal");
        Fm_Principal->resize(800, 600);
        Fm_Principal->setMinimumSize(QSize(800, 600));
        Fm_Principal->setMaximumSize(QSize(16777215, 16777215));
        actionEstoque = new QAction(Fm_Principal);
        actionEstoque->setObjectName("actionEstoque");
        actionColaboradores = new QAction(Fm_Principal);
        actionColaboradores->setObjectName("actionColaboradores");
        actionVendas = new QAction(Fm_Principal);
        actionVendas->setObjectName("actionVendas");
        actionSobre = new QAction(Fm_Principal);
        actionSobre->setObjectName("actionSobre");
        actionSair = new QAction(Fm_Principal);
        actionSair->setObjectName("actionSair");
        centralwidget = new QWidget(Fm_Principal);
        centralwidget->setObjectName("centralwidget");
        btt_novaVenda = new QPushButton(centralwidget);
        btt_novaVenda->setObjectName("btt_novaVenda");
        btt_novaVenda->setGeometry(QRect(30, 40, 161, 41));
        btt_novaVenda->setStyleSheet(QString::fromUtf8("background: #248;\n"
"color: #ffffff;\n"
"border: none;\n"
"border-radius: 10px;\n"
"font-size: 16pt;"));
        btt_block = new QPushButton(centralwidget);
        btt_block->setObjectName("btt_block");
        btt_block->setGeometry(QRect(0, 530, 32, 32));
        btt_block->setMinimumSize(QSize(32, 32));
        btt_block->setMaximumSize(QSize(32, 32));
        btt_block->setFlat(true);
        lbl_username = new QLabel(centralwidget);
        lbl_username->setObjectName("lbl_username");
        lbl_username->setGeometry(QRect(40, 540, 51, 16));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_username->sizePolicy().hasHeightForWidth());
        lbl_username->setSizePolicy(sizePolicy);
        Fm_Principal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Fm_Principal);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuGest_o = new QMenu(menubar);
        menuGest_o->setObjectName("menuGest_o");
        menuSistema = new QMenu(menubar);
        menuSistema->setObjectName("menuSistema");
        Fm_Principal->setMenuBar(menubar);
        statusbar = new QStatusBar(Fm_Principal);
        statusbar->setObjectName("statusbar");
        Fm_Principal->setStatusBar(statusbar);

        menubar->addAction(menuGest_o->menuAction());
        menubar->addAction(menuSistema->menuAction());
        menuGest_o->addAction(actionEstoque);
        menuGest_o->addAction(actionColaboradores);
        menuGest_o->addAction(actionVendas);
        menuSistema->addAction(actionSobre);
        menuSistema->addSeparator();
        menuSistema->addAction(actionSair);

        retranslateUi(Fm_Principal);

        QMetaObject::connectSlotsByName(Fm_Principal);
    } // setupUi

    void retranslateUi(QMainWindow *Fm_Principal)
    {
        Fm_Principal->setWindowTitle(QCoreApplication::translate("Fm_Principal", "Fm_Principal", nullptr));
        actionEstoque->setText(QCoreApplication::translate("Fm_Principal", "Estoque", nullptr));
        actionColaboradores->setText(QCoreApplication::translate("Fm_Principal", "Colaboradores", nullptr));
        actionVendas->setText(QCoreApplication::translate("Fm_Principal", "Vendas", nullptr));
        actionSobre->setText(QCoreApplication::translate("Fm_Principal", "Sobre", nullptr));
        actionSair->setText(QCoreApplication::translate("Fm_Principal", "Sair", nullptr));
        btt_novaVenda->setText(QCoreApplication::translate("Fm_Principal", "Nova venda", nullptr));
        btt_block->setText(QCoreApplication::translate("Fm_Principal", "block", nullptr));
        lbl_username->setText(QCoreApplication::translate("Fm_Principal", "TextLabel", nullptr));
        menuGest_o->setTitle(QCoreApplication::translate("Fm_Principal", "Gest\303\243o", nullptr));
        menuSistema->setTitle(QCoreApplication::translate("Fm_Principal", "Sistema", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fm_Principal: public Ui_Fm_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_PRINCIPAL_H
