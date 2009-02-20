TEMPLATE = lib
TARGET = CppTools
include(../../qworkbenchplugin.pri)
include(../../plugins/quickopen/quickopen.pri)
include(cpptools_dependencies.pri)

# DEFINES += QT_NO_CAST_FROM_ASCII
DEFINES += QT_NO_CAST_TO_ASCII
INCLUDEPATH += .
DEFINES += CPPTOOLS_LIBRARY
HEADERS += completionsettingspage.h \
    cppclassesfilter.h \
    cppcodecompletion.h \
    cppfunctionsfilter.h \
    cppmodelmanager.h \
    cppmodelmanagerinterface.h \
    cppquickopenfilter.h \
    cpptools_global.h \
    cpptoolsconstants.h \
    cpptoolseditorsupport.h \
    cpptoolsplugin.h \
    searchsymbols.h \
    cppdoxygen.h

SOURCES += completionsettingspage.cpp \
    cppclassesfilter.cpp \
    cppcodecompletion.cpp \
    cppfunctionsfilter.cpp \
    cppmodelmanager.cpp \
    cppquickopenfilter.cpp \
    cpptoolseditorsupport.cpp \
    cpptoolsplugin.cpp \
    searchsymbols.cpp \
    cppdoxygen.cpp

FORMS += completionsettingspage.ui
