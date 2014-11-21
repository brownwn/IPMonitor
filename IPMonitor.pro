TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    IPMonitor.cpp \
    NICDevices.cpp \
    common.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    common.h \
    IPMonitor.h \
    NICDevices.h

