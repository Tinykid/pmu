#-------------------------------------------------
#
# Project created by QtCreator 2015-11-08T08:30:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pmu
TEMPLATE = app

INCLUDEPATH += pmuIHM

INCLUDEPATH += pmuCom

SOURCES +=  main.cpp\
            pmuIHM/GuessULikeWidget.cpp \
            pmuIHM/HottipsWidget.cpp \
            pmuIHM/InstitutionWidget.cpp \
            pmuIHM/PrivilegeWidget.cpp \
            pmuIHM/RegAndSignPage.cpp \
            pmuIHM/PmuHomeTabPage.cpp \
            pmuIHM/PmuMainPage.cpp \
            pmuIHM/PmuEnterPage.cpp \
            pmuIHM/SearchWidget.cpp \
            pmuIHM/CoursePublishPage.cpp \
            pmuIHM/MyOwnPage.cpp \
            pmuIHM/TemplateWidget.cpp \
            AndroidGestureEvent.cpp \
            pmuIHM/ClassificationWidget.cpp \
            pmuIHM/MyRssCourse.cpp \
            pmuIHM/MySchedulePage.cpp \
            pmuIHM/PmuNeighborPage.cpp \
            pmuCom/ConnectToServer.cpp \
            pmuCom/CurrentAction.cpp \
            pmuCom/ReceptionTask.cpp \
            pmuIHM/CLabel.cpp \
    pmuIHM/PmuPersonalHomepage.cpp \
    pmuIHM/PmuTitleBar.cpp \
    pmuCom/ActionHistory.cpp \
    pmuIHM/SelectPage.cpp

HEADERS  += \
            pmuIHM/GuessULikeWidget.h \
            pmuIHM/HottipsWidget.h \
            pmuIHM/InstitutionWidget.h \
            pmuIHM/PrivilegeWidget.h \
            pmuIHM/RegAndSignPage.h \
            pmuIHM/PmuHomeTabPage.h \
            pmuIHM/PmuEnterPage.h \
            pmuIHM/PmuMainPage.h \
            pmuIHM/SearchWidget.h \
            pmuIHM/CoursePublishPage.h \
            pmuIHM/MyOwnPage.h \
            pmuIHM/TemplateWidget.h \
            AndroidGestureEvent.h \
            pmuIHM/ClassificationWidget.h \
            pmuIHM/MyRssCourse.h \
            pmuIHM/MySchedulePage.h \
            pmuIHM/PmuNeighborPage.h \
            pmuCom/ConnectToServer.h \
            pmuCom/CurrentAction.h \
    pmuCom/ReceptionTask.h \
    pmuCom/ActionHistory.h \
    pmuIHM/CLabel.h \
    pmuIHM/PmuPersonalHomepage.h \
    pmuIHM/PmuTitleBar.h \
    pmuIHM/SelectPage.h

RESOURCES += \
        imageresources.qrc

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

