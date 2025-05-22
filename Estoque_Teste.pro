QT       += core gui sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connectionfactory.cpp \
    fm_colaboradores.cpp \
    fm_colaboradores_dao.cpp \
    fm_colaboradores_editing.cpp \
    fm_estoque.cpp \
    fm_estoque_dao.cpp \
    fm_estoque_editing_page.cpp \
    fm_novavenda.cpp \
    fm_novavenda_dao.cpp \
    fm_pagamento.cpp \
    fm_pagamento_dao.cpp \
    fm_vendas.cpp \
    fm_vendas_dao.cpp \
    fm_vendasgerais.cpp \
    fm_vendasgerais_dao.cpp \
    log_in.cpp \
    log_in_dao.cpp \
    main.cpp \
    fm_principal.cpp \
    user.cpp

HEADERS += \
    accesstype.h \
    connectionfactory.h \
    fm_colaboradores.h \
    fm_colaboradores_dao.h \
    fm_colaboradores_editing.h \
    fm_estoque.h \
    fm_estoque_dao.h \
    fm_estoque_editing_page.h \
    fm_novavenda.h \
    fm_novavenda_dao.h \
    fm_pagamento.h \
    fm_pagamento_dao.h \
    fm_principal.h \
    fm_vendas.h \
    fm_vendas_dao.h \
    fm_vendasgerais.h \
    fm_vendasgerais_dao.h \
    log_in.h \
    log_in_dao.h \
    user.h

FORMS += \
    fm_colaboradores.ui \
    fm_colaboradores_editing.ui \
    fm_estoque.ui \
    fm_estoque_editing_page.ui \
    fm_novavenda.ui \
    fm_pagamento.ui \
    fm_principal.ui \
    fm_vendas.ui \
    fm_vendasgerais.ui \
    log_in.ui

TRANSLATIONS += \
    Estoque_Teste_pt_BR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
