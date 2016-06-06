QT += widgets
QT += network
CONFIG += console c++11

SOURCES += \
    Body.cpp \
    Brain.cpp \
    Cam.cpp \
    CmdLeftEngine.cpp \
    CommandBuilder.cpp \
    Engine.cpp \
    main.cpp \
    Network.cpp

DISTFILES += \
    Data_Interchange_Protocol

HEADERS += \
    Body.h \
    Brain.h \
    Cam.h \
    CmdLeftEngine.h \
    CommandBuilder.h \
    Engine.h \
    ICam.h \
    ICmd.h \
    IEngine.h \
    Network.h

