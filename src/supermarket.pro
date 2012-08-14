#-------------------------------------------------
#
# Projekt Supermarket, kalkulačka pro Supermarket
# fondů od společnosti Pioneer Investments.
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
	cenik.h \
    SMainWindow.h

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

RESOURCE_PATH = ../resources

macx {

	# nastaveni adresy pro výstup
	DESTDIR = ../build

	# nastavení ikony
	ICON = ../mac/icon.icns

	# nastavení .plist souboru (informace o aplikaci)
	QMAKE_INFO_PLIST = ../mac/Info.plist


	# nastavení příkazu pro kopírování
	RESOURCE_FILES = $${RESOURCE_PATH}/


	for(FILE, RESOURCE_FILES) {
	    QMAKE_POST_LINK += $$quote(cp -R $${FILE} $${DESTDIR}/$${TARGET}.app/Contents/Resources$$escape_expand(\n\t))
	}
	#RES_COMMAND.commands += "cp resources/*.* $${DESTDIR}/$${TARGET}.app/Contents/Resources/"
	#RES_COMMAND.target = $${DESTDIR}/$${TARGET}.app/Contents/Resources
}

win32 {

	# nastaveni adresy pro výstup
	DESTDIR = ..\\build

	# nastavení .rc souboru pro načtení ikony
	RC_FILE += win\\icon.rc

	# nastavení příkazu pro kopírování
	RES_COMMAND.commands = "ROBOCOPY resources $${DESTDIR}\\resources /MIR"
	RES_COMMAND.target = $${DESTDIR}\\resources

	# Copy required DLLs to output directory
	CONFIG(debug, debug|release) {

		QtCored4.commands = copy /Y %QTDIR%\\bin\\QtCored4.dll $${DESTDIR}
		QtCored4.target = $${DESTDIR}/QtCored4.dll
		QtGuid4.commands = copy /Y %QTDIR%\\bin\\QtGuid4.dll $${DESTDIR}
		QtGuid4.target = $${DESTDIR}/QtGuid4.dll

		QMAKE_EXTRA_TARGETS += QtCored4 QtGuid4
		PRE_TARGETDEPS += $${DESTDIR}/QtCored4.dll $${DESTDIR}/QtGuid4.dll

	} else:CONFIG(release, debug|release) {

		QtCore4.commands = copy /Y %QTDIR%\\bin\\QtCore4.dll $${DESTDIR}
		QtCore4.target = $${DESTDIR}/QtCore4.dll
		QtGui4.commands = copy /Y %QTDIR%\\bin\\QtGui4.dll $${DESTDIR}
		QtGui4.target = $${DESTDIR}/QtGui4.dll

		QMAKE_EXTRA_TARGETS += QtCore4 QtGui4
		PRE_TARGETDEPS += $${DESTDIR}/QtCore4.dll $${DESTDIR}/QtGui4.dll
	} else {
		error(Unknown set of dependencies.)
	}

	mingwm.commands = copy /Y %QTDIR%\\bin\\mingwm10.dll $${DESTDIR}
	mingwm.target = $${DESTDIR}/mingwm10.dll
	libgcc.commands = copy /Y %QTDIR%\\bin\\libgcc_s_dw2-1.dll $${DESTDIR}
	libgcc.target = $${DESTDIR}/libgcc_s_dw2-1.dll

	QMAKE_EXTRA_TARGETS += mingwm libgcc
	PRE_TARGETDEPS += $${DESTDIR}/mingwm10.dll $${DESTDIR}/libgcc_s_dw2-1.dll

}

# okopírování příkazu "kopírování obsahu složky Resources" do fronty
QMAKE_EXTRA_TARGETS += RES_COMMAND
PRE_TARGETDEPS += $${RES_COMMAND.target}
