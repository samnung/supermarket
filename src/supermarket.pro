# !!! UTF-8 !!!
#-------------------------------------------------
#
# Projekt Supermarket, kalkulačka pro Supermarket fondů od společnosti Pioneer Investments.
#
#-------------------------------------------------

QT		+= core gui network xml

TARGET		= Supermarket

TEMPLATE	= app

debug {
	CONFIG += console
}

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
    SMainWindow.h \
    supdate.h \
    sdownload.h

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
	cenik.cpp \
    supdate.cpp \
    sdownload.cpp

FORMS	+= \
	prehled.ui \
	mainwindow.ui \
    updateAlert.ui

macx {

	RESOURCE_PATH = ../resources
	RESOURCE_FILES = $${RESOURCE_PATH}/

	# nastaveni adresy pro výstup
	DESTDIR = ../build

	# nastavení ikony
	ICON = ../mac/icon.icns

	# nastavení .plist souboru (informace o aplikaci)
	QMAKE_INFO_PLIST = ../mac/Info.plist


	for(FILE, RESOURCE_FILES) {
	    QMAKE_POST_LINK += $$quote(cp -R $${FILE} $${DESTDIR}/$${TARGET}.app/Contents/Resources$$escape_expand(\n\t))
	}
	#RES_COMMAND.commands += "cp resources/*.* $${DESTDIR}/$${TARGET}.app/Contents/Resources/"
	#RES_COMMAND.target = $${DESTDIR}/$${TARGET}.app/Contents/Resources
}

win32 {

	RESOURCE_PATH = ..\\resources
	RESOURCE_FILES = $${RESOURCE_PATH}

	# nastaveni adresy pro výstup
	DESTDIR = ..\\build

	# nastavení .rc souboru pro načtení ikony
	RC_FILE += ..\\win\\icon.rc

	# nastavení příkazu pro kopírování
	QMAKE_POST_LINK += $$quote(ROBOCOPY $${RESOURCE_PATH} $${DESTDIR}\\resources /MIR)

	# Copy required DLLs to output directory
	CONFIG(debug, debug|release) {

		QtCored4.commands = copy /Y %QTDIR%\\bin\\QtCored4.dll $${DESTDIR}\\debug\\
		QtCored4.target = $${DESTDIR}\\debug\\QtCored4.dll
		QtGuid4.commands = copy /Y %QTDIR%\\bin\\QtGuid4.dll $${DESTDIR}\\debug\\
		QtGuid4.target = $${DESTDIR}\\debug\\QtGuid4.dll

		#QMAKE_EXTRA_TARGETS += QtCored4 QtGuid4
		#PRE_TARGETDEPS += $${DESTDIR}/QtCored4.dll $${DESTDIR}/QtGuid4.dll

	} else:CONFIG(release, debug|release) {

		QtCore4.commands = copy /Y %QTDIR%\\bin\\QtCore4.dll $${DESTDIR}\\release\\
		QtCore4.target = $${DESTDIR}\\release\\QtCore4.dll
		QtGui4.commands = copy /Y %QTDIR%\\bin\\QtGui4.dll $${DESTDIR}\\release\\
		QtGui4.target = $${DESTDIR}\\release\\QtGui4.dll

		#QMAKE_EXTRA_TARGETS += QtCore4 QtGui4
		#PRE_TARGETDEPS += $${DESTDIR}/QtCore4.dll $${DESTDIR}/QtGui4.dll
	} else {
		error(Unknown set of dependencies.)
	}

	mingwm.commands = copy /Y %QTDIR%\\bin\\mingwm10.dll $${DESTDIR}
	mingwm.target = $${DESTDIR}/mingwm10.dll
	libgcc.commands = copy /Y %QTDIR%\\bin\\libgcc_s_dw2-1.dll $${DESTDIR}
	libgcc.target = $${DESTDIR}/libgcc_s_dw2-1.dll

	#QMAKE_EXTRA_TARGETS += mingwm libgcc
	#PRE_TARGETDEPS += $${DESTDIR}/mingwm10.dll $${DESTDIR}/libgcc_s_dw2-1.dll

}

# okopírování příkazu "kopírování obsahu složky Resources" do fronty
#QMAKE_EXTRA_TARGETS += RES_COMMAND
#PRE_TARGETDEPS += $${RES_COMMAND.target}
