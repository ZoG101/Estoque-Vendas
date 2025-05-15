/********************************************************************************
** Form generated from reading UI file 'fm_estoque.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_ESTOQUE_H
#define UI_FM_ESTOQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fm_Estoque
{
public:
    QVBoxLayout *verticalLayout_10;
    QTabWidget *tw_main;
    QWidget *tab_addProd;
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
    QPushButton *btt_add;
    QPushButton *btt_clear;
    QWidget *tab_manegeProd;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *gb_filtros;
    QVBoxLayout *verticalLayout_11;
    QRadioButton *rb_nome;
    QRadioButton *rb_descricao;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_pesquisa;
    QLineEdit *le_pesquisa;
    QPushButton *btt_reload;
    QTableWidget *tw_produtos;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btt_editar;
    QPushButton *btt_excluir;

    void setupUi(QDialog *Fm_Estoque)
    {
        if (Fm_Estoque->objectName().isEmpty())
            Fm_Estoque->setObjectName("Fm_Estoque");
        Fm_Estoque->resize(800, 520);
        Fm_Estoque->setMinimumSize(QSize(800, 520));
        Fm_Estoque->setMaximumSize(QSize(1024, 600));
        verticalLayout_10 = new QVBoxLayout(Fm_Estoque);
        verticalLayout_10->setObjectName("verticalLayout_10");
        tw_main = new QTabWidget(Fm_Estoque);
        tw_main->setObjectName("tw_main");
        tab_addProd = new QWidget();
        tab_addProd->setObjectName("tab_addProd");
        verticalLayout_9 = new QVBoxLayout(tab_addProd);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_prodCod = new QLabel(tab_addProd);
        lbl_prodCod->setObjectName("lbl_prodCod");

        verticalLayout->addWidget(lbl_prodCod);

        le_prodCod = new QLineEdit(tab_addProd);
        le_prodCod->setObjectName("le_prodCod");

        verticalLayout->addWidget(le_prodCod);


        verticalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_prodName = new QLabel(tab_addProd);
        lbl_prodName->setObjectName("lbl_prodName");

        verticalLayout_2->addWidget(lbl_prodName);

        le_prodName = new QLineEdit(tab_addProd);
        le_prodName->setObjectName("le_prodName");

        verticalLayout_2->addWidget(le_prodName);


        verticalLayout_8->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lbl_prodDesc = new QLabel(tab_addProd);
        lbl_prodDesc->setObjectName("lbl_prodDesc");

        verticalLayout_3->addWidget(lbl_prodDesc);

        le_prodDesc = new QLineEdit(tab_addProd);
        le_prodDesc->setObjectName("le_prodDesc");

        verticalLayout_3->addWidget(le_prodDesc);


        verticalLayout_8->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        lbl_prodQtt = new QLabel(tab_addProd);
        lbl_prodQtt->setObjectName("lbl_prodQtt");

        verticalLayout_4->addWidget(lbl_prodQtt);

        le_prodQtt = new QLineEdit(tab_addProd);
        le_prodQtt->setObjectName("le_prodQtt");

        verticalLayout_4->addWidget(le_prodQtt);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        lbl_bValue = new QLabel(tab_addProd);
        lbl_bValue->setObjectName("lbl_bValue");

        verticalLayout_5->addWidget(lbl_bValue);

        dsb_bValue = new QDoubleSpinBox(tab_addProd);
        dsb_bValue->setObjectName("dsb_bValue");

        verticalLayout_5->addWidget(dsb_bValue);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        lbl_sValue = new QLabel(tab_addProd);
        lbl_sValue->setObjectName("lbl_sValue");

        verticalLayout_6->addWidget(lbl_sValue);

        dsb_sValue = new QDoubleSpinBox(tab_addProd);
        dsb_sValue->setObjectName("dsb_sValue");

        verticalLayout_6->addWidget(dsb_sValue);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        lbl_supplier = new QLabel(tab_addProd);
        lbl_supplier->setObjectName("lbl_supplier");

        verticalLayout_7->addWidget(lbl_supplier);

        cb_supplier = new QComboBox(tab_addProd);
        cb_supplier->setObjectName("cb_supplier");

        verticalLayout_7->addWidget(cb_supplier);


        horizontalLayout->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btt_add = new QPushButton(tab_addProd);
        btt_add->setObjectName("btt_add");

        horizontalLayout_2->addWidget(btt_add);

        btt_clear = new QPushButton(tab_addProd);
        btt_clear->setObjectName("btt_clear");

        horizontalLayout_2->addWidget(btt_clear);


        verticalLayout_8->addLayout(horizontalLayout_2);


        verticalLayout_9->addLayout(verticalLayout_8);

        tw_main->addTab(tab_addProd, QString());
        tab_manegeProd = new QWidget();
        tab_manegeProd->setObjectName("tab_manegeProd");
        horizontalLayout_6 = new QHBoxLayout(tab_manegeProd);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        gb_filtros = new QGroupBox(tab_manegeProd);
        gb_filtros->setObjectName("gb_filtros");
        verticalLayout_11 = new QVBoxLayout(gb_filtros);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(-1, -1, -1, 0);
        rb_nome = new QRadioButton(gb_filtros);
        rb_nome->setObjectName("rb_nome");
        rb_nome->setCheckable(true);
        rb_nome->setChecked(false);

        verticalLayout_11->addWidget(rb_nome);

        rb_descricao = new QRadioButton(gb_filtros);
        rb_descricao->setObjectName("rb_descricao");

        verticalLayout_11->addWidget(rb_descricao);


        horizontalLayout_4->addWidget(gb_filtros);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 50, -1, -1);
        lbl_pesquisa = new QLabel(tab_manegeProd);
        lbl_pesquisa->setObjectName("lbl_pesquisa");
        QFont font;
        font.setPointSize(10);
        lbl_pesquisa->setFont(font);

        horizontalLayout_3->addWidget(lbl_pesquisa);

        le_pesquisa = new QLineEdit(tab_manegeProd);
        le_pesquisa->setObjectName("le_pesquisa");

        horizontalLayout_3->addWidget(le_pesquisa);

        btt_reload = new QPushButton(tab_manegeProd);
        btt_reload->setObjectName("btt_reload");

        horizontalLayout_3->addWidget(btt_reload);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_12->addLayout(horizontalLayout_4);

        tw_produtos = new QTableWidget(tab_manegeProd);
        if (tw_produtos->columnCount() < 6)
            tw_produtos->setColumnCount(6);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tw_produtos->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tw_produtos->setObjectName("tw_produtos");

        verticalLayout_12->addWidget(tw_produtos);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btt_editar = new QPushButton(tab_manegeProd);
        btt_editar->setObjectName("btt_editar");

        horizontalLayout_5->addWidget(btt_editar);

        btt_excluir = new QPushButton(tab_manegeProd);
        btt_excluir->setObjectName("btt_excluir");

        horizontalLayout_5->addWidget(btt_excluir);


        verticalLayout_12->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_12);

        tw_main->addTab(tab_manegeProd, QString());

        verticalLayout_10->addWidget(tw_main);


        retranslateUi(Fm_Estoque);

        tw_main->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Fm_Estoque);
    } // setupUi

    void retranslateUi(QDialog *Fm_Estoque)
    {
        Fm_Estoque->setWindowTitle(QCoreApplication::translate("Fm_Estoque", "Dialog", nullptr));
        lbl_prodCod->setText(QCoreApplication::translate("Fm_Estoque", "Cod. Produto", nullptr));
        lbl_prodName->setText(QCoreApplication::translate("Fm_Estoque", "Nome do Produto", nullptr));
        lbl_prodDesc->setText(QCoreApplication::translate("Fm_Estoque", "Descri\303\247\303\243o do Produto", nullptr));
        lbl_prodQtt->setText(QCoreApplication::translate("Fm_Estoque", "Quantidade em Estoque", nullptr));
        lbl_bValue->setText(QCoreApplication::translate("Fm_Estoque", "Valor de Compra", nullptr));
        lbl_sValue->setText(QCoreApplication::translate("Fm_Estoque", "Valor de Venda", nullptr));
        lbl_supplier->setText(QCoreApplication::translate("Fm_Estoque", "Fornecedor", nullptr));
        btt_add->setText(QCoreApplication::translate("Fm_Estoque", "Adicionar", nullptr));
        btt_clear->setText(QCoreApplication::translate("Fm_Estoque", "Limpar", nullptr));
        tw_main->setTabText(tw_main->indexOf(tab_addProd), QCoreApplication::translate("Fm_Estoque", "Adicionar Produto", nullptr));
        gb_filtros->setTitle(QCoreApplication::translate("Fm_Estoque", "Filtros:", nullptr));
        rb_nome->setText(QCoreApplication::translate("Fm_Estoque", "Nome", nullptr));
        rb_descricao->setText(QCoreApplication::translate("Fm_Estoque", "Decri\303\247\303\243o", nullptr));
        lbl_pesquisa->setText(QCoreApplication::translate("Fm_Estoque", "Pesquisa:", nullptr));
        btt_reload->setText(QCoreApplication::translate("Fm_Estoque", "Recarregar", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tw_produtos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Fm_Estoque", "Cod. Produto", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tw_produtos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Fm_Estoque", "Nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tw_produtos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Fm_Estoque", "Valor - Compra", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tw_produtos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Fm_Estoque", "Valor - Venda", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tw_produtos->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Fm_Estoque", "Estoque", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tw_produtos->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Fm_Estoque", "Fornecedor", nullptr));
        btt_editar->setText(QCoreApplication::translate("Fm_Estoque", "Editar", nullptr));
        btt_excluir->setText(QCoreApplication::translate("Fm_Estoque", "Excluir", nullptr));
        tw_main->setTabText(tw_main->indexOf(tab_manegeProd), QCoreApplication::translate("Fm_Estoque", "Gerenciamento de produtos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fm_Estoque: public Ui_Fm_Estoque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_ESTOQUE_H
