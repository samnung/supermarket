#-------------------------------------------------
#
# Project created by QtCreator 2010-11-20T23:04:33
#
#-------------------------------------------------

QT		+= core gui network

TARGET		= Supermarket
TEMPLATE	= app

HEADERS += \
		src/splashscreen.h \
		src/seznam.h \
		src/prehled.h \
		src/podrobnosti.h \
		src/oaplikaci.h \
		src/mainwindow.h \
		src/podrobnosti_adv.h \
		src/window_control.h \
		src/files_control.h \
		src/define.h \
		src/MyQToolButton.h \
		src/MyQMainWindow.h \
		src/cenik.h

SOURCES	+= \
		src/splashscreen.cpp \
		src/seznam.cpp \
		src/prehled.cpp \
		src/podrobnosti.cpp \
		src/oaplikaci.cpp \
		src/mainwindow.cpp \
		src/main.cpp \
		src/podrobnosti_adv.cpp \
		src/window_control.cpp \
		src/files_control.cpp \
		src/cenik.cpp

FORMS	+= \
		src/prehled.ui \
		src/mainwindow.ui

RESOURCES	+=

macx {
	ICON = img/icon.icns
}
win32 {
	RC_FILE += img/ico/icon.rc
}

OTHER_FILES +=
