#-------------------------------------------------
#
# Project created by QtCreator 2018-01-16T21:53:34
#
#-------------------------------------------------

TARGET = QRtf
TEMPLATE = lib

DEFINES += QRTF_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    rtfcontextstack.cpp \
    abstractrtfcontext.cpp \
    command.cpp \
    nullcontext.cpp \
    defaultfont.cpp \
    defaultfonttable.cpp \
    paragraphlist.cpp \
    defaultparagraph.cpp \
    defaultparagraphstyle.cpp \
    defaultstyle.cpp \
    defaultcharacterstyle.cpp \
    rootcontext.cpp \
    defaultchunk.cpp \
    defaultannotation.cpp \
    defaultcharacterstyletable.cpp \
    defaultcolor.cpp \
    defaultcolortable.cpp \
    defaultparagraphstyletable.cpp \
    defaultstylesheet.cpp \
    documentbuilder.cpp \
    standardrtfparser.cpp \
    defaultdocument.cpp \
    sectionlist.cpp \
    defaultsection.cpp \
    rawrtfparser.cpp \
    documentpartcontext.cpp \
    documentcontext.cpp \
    defaultheader.cpp \
    defaultfooter.cpp \
    colortablecontext.cpp \
    fonttablecontext.cpp \
    fontcontext.cpp \
    stylesheetcontext.cpp \
    paragraphstylecontext.cpp \
    characterstylecontext.cpp \
    documentsettings.cpp \
    pagesettings.cpp \
    annotationcontext.cpp \
    annotationidcontext.cpp \
    annotationauthorcontext.cpp \
    timecontext.cpp \
    defaulteventhandler.cpp \
    stringevent.cpp \
    binarybytesevent.cpp \
    commandevent.cpp \
    documentendevent.cpp \
    documentstartevent.cpp \
    groupendevent.cpp \
    groupstartevent.cpp \
    uprhandler.cpp \
    qrtfreader.cpp

HEADERS += \
        qrtf_global.h \ 
    rtfcontext.h \
    rtfcontextstack.h \
    abstractrtfcontext.h \
    command.h \
    element.h \
    text.h \
    nullcontext.h \
    font.h \
    defaultfont.h \
    documentpart.h \
    document.h \
    fonttable.h \
    defaultfonttable.h \
    annotation.h \
    paragraphlist.h \
    defaultparagraph.h \
    paragraph.h \
    style.h \
    characterstyle.h \
    color.h \
    paragraphstyle.h \
    chunk.h \
    defaultparagraphstyle.h \
    defaultstyle.h \
    defaultcharacterstyle.h \
    rootcontext.h \
    defaultchunk.h \
    exception.h \
    defaultannotation.h \
    characterstyletable.h \
    colortable.h \
    documentsettings.h \
    footer.h \
    header.h \
    pagesettings.h \
    paragraphstyletable.h \
    section.h \
    stylesheet.h \
    defaultcharacterstyletable.h \
    defaultcolor.h \
    defaultcolortable.h \
    styletable.h \
    defaultparagraphstyletable.h \
    defaultstylesheet.h \
    documentbuilder.h \
    irtflistener.h \
    irtfparser.h \
    standardrtfparser.h \
    defaultdocument.h \
    sectionlist.h \
    defaultsection.h \
    rawrtfparser.h \
    documentpartcontext.h \
    documentcontext.h \
    encoding.h \
    defaultheader.h \
    defaultfooter.h \
    colortablecontext.h \
    fonttablecontext.h \
    fontcontext.h \
    stylesheetcontext.h \
    paragraphstylecontext.h \
    characterstylecontext.h \
    annotationcontext.h \
    annotationidcontext.h \
    annotationauthorcontext.h \
    timecontext.h \
    iparseevent.h \
    iparsereventhandler.h \
    defaulteventhandler.h \
    stringevent.h \
    binarybytesevent.h \
    commandevent.h \
    documentendevent.h \
    documentstartevent.h \
    groupendevent.h \
    groupstartevent.h \
    parserstate.h \
    uprhandler.h \
    fontcharset.h \
    qrtfreader.h \
    qrtfreader_p.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
