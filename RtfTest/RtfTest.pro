QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

INCLUDEPATH += ../QRtf

LIBS += -L/Volumes/Data/Development/build-QRtf-Desktop_Qt_5_9_1_clang_64bit-Debug/QRtf -lQRtf

TEMPLATE = app

SOURCES += \ 
    tst_paragraphList.cpp \
    tst_paragraph.cpp \
    main.cpp \
    tst_builderparse.cpp \
    tst_rawrtfparser.cpp \
    rtfdumper.cpp \
    tst_standardrtfparser.cpp \
    testutils.cpp

HEADERS += \
    tst_paragraph.h \
    tst_paragraphlist.h \
    tst_builderparse.h \
    tst_rawrtfparser.h \
    rtfdumper.h \
    tst_standardrtfparser.h \
    testutils.h

RESOURCES += \
    resource.qrc
