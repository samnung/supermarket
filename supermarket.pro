#-------------------------------------------------
#
# Projekt Supermarket, kalkulacka pro Supermarket
# fondu od spolecnosti Pioneer Investments.
#
#-------------------------------------------------

QT		+= core gui network

TARGET		= Supermarket

TEMPLATE	= app

HEADERS += \
	splashscreen.h \
	seznam.h \
	prehled.h \
	podrobnosti.h \
	oaplikaci.h \
	mainwindow.h \
	podrobnosti_adv.h \
	window_control.h \
	files_control.h \
	define.h \
	MyQToolButton.h \
	MyQMainWindow.h \
	cenik.h

SOURCES	+= \
	splashscreen.cpp \
	seznam.cpp \
	prehled.cpp \
	podrobnosti.cpp \
	oaplikaci.cpp \
	mainwindow.cpp \
	main.cpp \
	podrobnosti_adv.cpp \
	window_control.cpp \
	files_control.cpp \
	cenik.cpp

FORMS	+= \
	prehled.ui \
	mainwindow.ui

debug {
	CONFIG += console
}

# build path
DESTDIR = $${PWD}/../build

# path to sources
SRCS = $${PWD}

# path to icons from sources
ICONS_PATH = "$${SRCS}/img/*.*"


macx {
	# set program icon
	ICON = img/icon.icns

	# set bundle info
	QMAKE_INFO_PLIST = Info.plist

	# set path to Resources of bundle
	RESOURCES_PATH = $${DESTDIR}/Supermarket.app/Contents/Resources/

	# command to copy icons
	copyfiles.commands += "cp $${ICONS_PATH} $${RESOURCES_PATH}"
}

win32 {
	# set rc file for program icon
	RC_FILE += img/ico/icon.rc

	# set path to icons folder
	RESOURCE_PATH = $${DESTDIR}/img/

	# command to copy icons
	copyfiles.commands = @call copy $${ICONS_PATH} $${RESOURCE_PATH}
}

# commands for copy files
QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles

