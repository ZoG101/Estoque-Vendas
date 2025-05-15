/********************************************************************************
** Form generated from reading UI file 'log_in.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_IN_H
#define UI_LOG_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_log_in
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_username;
    QLineEdit *le_username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_senha;
    QSpacerItem *horizontalSpacer;
    QLineEdit *le_senha;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btt_logar;
    QPushButton *btt_cancelar;

    void setupUi(QDialog *log_in)
    {
        if (log_in->objectName().isEmpty())
            log_in->setObjectName("log_in");
        log_in->resize(450, 400);
        log_in->setMinimumSize(QSize(450, 400));
        log_in->setMaximumSize(QSize(450, 400));
        verticalLayout_2 = new QVBoxLayout(log_in);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lbl_username = new QLabel(log_in);
        lbl_username->setObjectName("lbl_username");

        horizontalLayout->addWidget(lbl_username);

        le_username = new QLineEdit(log_in);
        le_username->setObjectName("le_username");

        horizontalLayout->addWidget(le_username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_senha = new QLabel(log_in);
        lbl_senha->setObjectName("lbl_senha");

        horizontalLayout_2->addWidget(lbl_senha);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        le_senha = new QLineEdit(log_in);
        le_senha->setObjectName("le_senha");
        le_senha->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_2->addWidget(le_senha);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btt_logar = new QPushButton(log_in);
        btt_logar->setObjectName("btt_logar");

        horizontalLayout_3->addWidget(btt_logar);

        btt_cancelar = new QPushButton(log_in);
        btt_cancelar->setObjectName("btt_cancelar");

        horizontalLayout_3->addWidget(btt_cancelar);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(log_in);

        QMetaObject::connectSlotsByName(log_in);
    } // setupUi

    void retranslateUi(QDialog *log_in)
    {
        log_in->setWindowTitle(QCoreApplication::translate("log_in", "Dialog", nullptr));
        lbl_username->setText(QCoreApplication::translate("log_in", "Username:", nullptr));
        lbl_senha->setText(QCoreApplication::translate("log_in", "Senha:", nullptr));
        btt_logar->setText(QCoreApplication::translate("log_in", "Logar", nullptr));
        btt_cancelar->setText(QCoreApplication::translate("log_in", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class log_in: public Ui_log_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_IN_H
