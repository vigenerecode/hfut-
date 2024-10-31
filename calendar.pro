QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clock.cpp \
    index.cpp \
    main.cpp \
    mywidget.cpp \
    rect_ymd.cpp \
    today_todolist.cpp \
    updateanddelete.cpp \
    util_calendar.cpp \
    widget.cpp \
    y_m.cpp \
    year_month_day.cpp

HEADERS += \
    clock.h \
    index.h \
    mywidget.h \
    rect_ymd.h \
    today_todolist.h \
    updateanddelete.h \
    util_calendar.h \
    widget.h \
    y_m.h \
    year_month_day.h

FORMS += \
    clock.ui \
    index.ui \
    mywidget.ui \
    today_todolist.ui \
    updateanddelete.ui \
    widget.ui \
    y_m.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    images.qrc
