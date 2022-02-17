QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += _ATL_NATIVE_INITIALIZATION
INCLUDEPATH += $$PWD/include/                       \
               $$PWD/include/sensors                \
               $$PWD/include/gui                    \
               $$PWD/include/test                   \
               $$PWD/include/abstract               \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


test {
    message(Test build)
    QT += testlib
    TARGET = demo-test
    INCLUDEPATH += $$PWD/include/test                   \
                   $$PWD/include/test/mockups           \
                   $$PWD/include/test/integration_tests \
                   $$PWD/include/test/unit_tests        \
                   $$PWD/include/abstract               \

    SOURCES += \
        src/raum.cpp \
        src/haustuer.cpp \
        src/rauchmelder.cpp \
        src/fenstersicherung.cpp \
        src/authentifizierung.cpp \
        src/wasserflut.cpp \
        src/test/main.cpp \
        src/switcher.cpp \
        src/led.cpp \
        src/sensors/gluehbirne.cpp \
        src/sensors/alarm.cpp \
        src/sensors/pir_sensor.cpp \
        src/sensors/temperatursensor.cpp \
        src/sensors/wasserstandssensor.cpp \
        #Unit_tests
        src/test/unit_tests/test_rauchmelder.cpp \
        src/test/unit_tests/test_fenstersicherung.cpp \
        src/test/unit_tests/test_gluehbirne.cpp \
        src/test/unit_tests/test_wasserflut.cpp \
        src/test/unit_tests/test_alarm.cpp \
        src/test/unit_tests/test_authentifizierung.cpp \
        #Mockups
        src/test/mockups/authentifizierung_mockup.cpp \
        src/test/mockups/rauchmelder_mockup.cpp \
        src/test/mockups/wasserflut_mockup.cpp \
        src/test/mockups/fenstersicherung_mockup.cpp \
        src/test/mockups/alarm_mockup.cpp \
        #Integration_tests
        src/test/integration_tests/test_wasserflut_alarm.cpp \
        src/test/integration_tests/test_fenstersicherung_alarm.cpp \
        src/test/integration_tests/test_rauchmelder_alarm.cpp \
        src/test/integration_tests/test_authentifizierung_integration.cpp \
        src/test/integration_tests/test_alarm_integration.cpp \
        src/test/integration_tests/test_gluehbirne_raum.cpp\
        src/test/integration_tests/test_switcher_integration.cpp \
        #System_test
        src/test/test_system.cpp

    HEADERS += \
        include/sensors/alarm.h \
        include/authentifizierung.h \
        include/fenstersicherung.h \
        include/singleton.h \
        include/switcher.h \
        include/haustuer.h \
        include/macros.h \
        include/led.h \
        include/sensors/pir_sensor.h \
        include/rauchmelder.h \
        include/sensors/gluehbirne.h \
        include/sensors/temperatursensor.h \
        include/wasserflut.h \
        include/sensors/wasserstandssensor.h \
        include/raum.h \
        #Unit_tests
        include/test/unit_tests/test_rauchmelder.h \
        include/test/unit_tests/test_fenstersicherung.h \
        include/test/unit_tests/test_gluehbirne.h \
        include/test/unit_tests/test_wasserflut.h \
        include/test/unit_tests/test_alarm.h \
        include/test/unit_tests/test_authentifizierung.h \
        #Mockups
        include/test/mockups/authentifizierung_mockup.h \
        include/test/mockups/alarm_mockup.h \
        include/test/mockups/rauchmelder_mockup.h \
        include/test/mockups/fenstersicherung_mockup.h \
        include/test/mockups/wasserflut_mockup.h \
        #Integration_tests
        include/test/integration_tests/test_authentifizierung_integration.h \
        include/test/integration_tests/test_wasserflut_alarm.h \
        include/test/integration_tests/test_fenstersicherung_alarm.h \
        include/test/integration_tests/test_rauchmelder_alarm.h \
        include/test/integration_tests/test_alarm_integration.h \
        include/test/integration_tests/test_gluehbirne_raum.h\
        include/test/integration_tests/test_switcher_integration.h \
        #System_test
        include/test/test_system.h

} else {
    message(Normal build)

    SOURCES += \
        src/sensors/pir_sensor.cpp \
        src/sensors/alarm.cpp \
        src/sensors/temperatursensor.cpp \
        src/sensors/gluehbirne.cpp \
        src/sensors/wasserstandssensor.cpp \
        src/authentifizierung.cpp \
        src/haustuer.cpp \
        src/led.cpp \
        src/main.cpp \
        src/fenstersicherung.cpp \
        src/rauchmelder.cpp \
        src/raum.cpp \
        src/wasserflut.cpp \
        src/switcher.cpp \
        src/gui/authentifizierung_window.cpp \
        src/gui/alarm_window.cpp \
        src/gui/home_simulation.cpp \
        src/gui/view.cpp    \
        src/gui/einstellungen.cpp \
        src/gui/app.cpp \
        src/gui/switcher_window.cpp \
        src/gui/about.cpp

    HEADERS += \
        include/sensors/alarm.h \
        include/gui/app.h \
        include/authentifizierung.h \
        include/fenstersicherung.h \
        include/haustuer.h \
        include/led.h \
        include/rauchmelder.h \
        include/raum.h \
        include/macros.h \
        include/singleton.h \
        include/switcher.h \
        include/wasserflut.h \
        include/sensors/gluehbirne.h \
        include/sensors/pir_sensor.h \
        include/sensors/temperatursensor.h \
        include/sensors/wasserstandssensor.h \
        include/gui/authentifizierung_window.h \
        include/gui/alarm_window.h \
        include/gui/home_simulation.h \
        include/gui/view.h \
        include/gui/einstellungen.h \
        include/gui/switcher_window.h \
        include/gui/about.h
}

FORMS += \
    ui/about.ui \
    ui/alarm_window.ui \
    ui/authentifizierung_window.ui \
    ui/einstellungen.ui \
    ui/app.ui \
    ui/home_simulation.ui \
    ui/switcher_window.ui

DISTFILES += \
    assets/bg2.png \
    assets/main_pic.jpg \

RESOURCES += \
    assets/imgs   \
    assets/Bilder.qrc  \

HEADERS += include/abstract/abstract_fenstersicherung.h \
           include/abstract/abstract_rauchmelder.h \
           include/abstract/abstract_authentifizierung.h \
           include/abstract/abstract_wasserflut.h \
           include/abstract/abstract_alarm.h \






