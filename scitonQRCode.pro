TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
#CONFIG += c++17

SOURCES += main.cpp \
    libs/QR-Code-generator/QrCode.cpp \
    libs/tinypngout/TinyPngOut.cpp \
    libs/Qr-To-Png/QrToPng.cpp \
    libs/Qr-To-Png/fileOperations.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    libs/QR-Code-generator/QrCode.hpp \
    libs/tinypngout/TinyPngOut.hpp \
    libs/Qr-To-Png/QrToPng.h \
    libs/Qr-To-Png/fileOperations.h \
    libs/CLI/App.hpp \
    libs/CLI/CLI.hpp \
    libs/CLI/Config.hpp \
    libs/CLI/ConfigFwd.hpp \
    libs/CLI/Error.hpp \
    libs/CLI/Formatter.hpp \
    libs/CLI/FormatterFwd.hpp \
    libs/CLI/Macros.hpp \
    libs/CLI/Option.hpp \
    libs/CLI/Split.hpp \
    libs/CLI/StringTools.hpp \
    libs/CLI/Timer.hpp \
    libs/CLI/TypeTools.hpp \
    libs/CLI/Validators.hpp \
    libs/CLI/Version.hpp \
    QrReturnCodes.h

OTHER_FILES += \
    Scripts/qrScript.sh
