# This project is not actually used to build qmake, but to support development
# with Qt Creator. The real build system is made up by the Makefile templates
# and the configures.

option(host_build)
CONFIG += cmdline
CONFIG -= qt

DEFINES += \
    PROEVALUATOR_FULL \
    QT_BOOTSTRAPPED \
    QT_BUILD_QMAKE \
    QT_USE_QSTRINGBUILDER \
    QT_NO_FOREACH \
    $$shell_quote(QT_VERSION_STR=\"$$QT_VERSION\") \
    QT_VERSION_MAJOR=$$QT_MAJOR_VERSION \
    QT_VERSION_MINOR=$$QT_MINOR_VERSION \
    QT_VERSION_PATCH=$$QT_PATCH_VERSION \
    PCRE2_DISABLE_JIT

win32: DEFINES += \
    UNICODE \
    _ENABLE_EXTENDED_ALIGNED_STORAGE \
    _CRT_SECURE_NO_WARNINGS _SCL_SECURE_NO_WARNINGS

# qmake code

PRECOMPILED_HEADER = qmake_pch.h

INCLUDEPATH += \
    . \
    library \
    generators \
    generators/unix \
    generators/win32 \
    generators/mac \
    ../src/3rdparty/tinycbor/src

SOURCES += \
    main.cpp \
    meta.cpp \
    option.cpp \
    project.cpp \
    property.cpp \
    library/ioutils.cpp \
    library/proitems.cpp \
    library/qmakebuiltins.cpp \
    library/qmakeevaluator.cpp \
    library/qmakeglobals.cpp \
    library/qmakeparser.cpp \
    library/qmakevfs.cpp \
    generators/makefile.cpp \
    generators/makefiledeps.cpp \
    generators/metamakefile.cpp \
    generators/projectgenerator.cpp \
    generators/xmloutput.cpp \
    generators/mac/pbuilder_pbx.cpp \
    generators/unix/unixmake.cpp \
    generators/unix/unixmake2.cpp \
    generators/win32/mingw_make.cpp \
    generators/win32/msbuild_objectmodel.cpp \
    generators/win32/msvc_nmake.cpp \
    generators/win32/msvc_objectmodel.cpp \
    generators/win32/msvc_vcproj.cpp \
    generators/win32/msvc_vcxproj.cpp \
    generators/win32/winmakefile.cpp

HEADERS += \
    cachekeys.h \
    meta.h \
    option.h \
    project.h \
    property.h \
    library/ioutils.h \
    library/proitems.h \
    library/qmake_global.h \
    library/qmakeevaluator.h \
    library/qmakeevaluator_p.h \
    library/qmakeglobals.h \
    library/qmakeparser.h \
    library/qmakevfs.h \
    generators/makefile.h \
    generators/makefiledeps.h \
    generators/metamakefile.h \
    generators/projectgenerator.h \
    generators/xmloutput.h \
    generators/mac/pbuilder_pbx.h \
    generators/unix/unixmake.h \
    generators/win32/mingw_make.h \
    generators/win32/msbuild_objectmodel.h \
    generators/win32/msvc_nmake.h \
    generators/win32/msvc_objectmodel.h \
    generators/win32/msvc_vcproj.h \
    generators/win32/msvc_vcxproj.h \
    generators/win32/winmakefile.h

# qt code

bp = $$shadowed(..)
INCLUDEPATH += \
    $$bp/include $$bp/include/QtCore \
    $$bp/include/QtCore/$$QT_VERSION $$bp/include/QtCore/$$QT_VERSION/QtCore \
    $$bp/src/corelib/global

VPATH += \
    ../src/corelib/global \
    ../src/corelib/text \
    ../src/corelib/tools \
    ../src/corelib/kernel \
    ../src/corelib/codecs \
    ../src/corelib/plugin \
    ../src/corelib/io \
        ../src/corelib/time \
    ../src/corelib/serialization

SOURCES += \
    qabstractfileengine.cpp \
    qarraydata.cpp \
    qbitarray.cpp \
    qbuffer.cpp \
    qbytearray.cpp \
    qbytearraymatcher.cpp \
    qcalendar.cpp \
    qcborstreamwriter.cpp \
    qcborvalue.cpp \
    qcryptographichash.cpp \
    qdatetime.cpp \
    qdir.cpp \
    qdiriterator.cpp \
    qfile.cpp \
    qfiledevice.cpp \
    qfileinfo.cpp \
    qfilesystemengine.cpp \
    qfilesystementry.cpp \
    qfsfileengine.cpp \
    qfsfileengine_iterator.cpp \
    qglobal.cpp \
    qgregoriancalendar.cpp \
    qhash.cpp \
    qiodevice.cpp \
    qjsonarray.cpp \
    qjsoncbor.cpp \
    qjsondocument.cpp \
    qjsonobject.cpp \
    qjsonparser.cpp \
    qjsonvalue.cpp \
    qlibraryinfo.cpp \
    qlist.cpp \
    qlocale.cpp \
    qlocale_tools.cpp \
    qlogging.cpp \
    qmalloc.cpp \
    qmap.cpp \
    qmetatype.cpp \
    qnumeric.cpp \
    qregexp.cpp \
    qregularexpression.cpp \
    qromancalendar.cpp \
    qsettings.cpp \
    qstring.cpp \
    qstringbuilder.cpp \
    qstringlist.cpp \
    qsystemerror.cpp \
    qtemporaryfile.cpp \
    qtextstream.cpp \
    qutfcodec.cpp \
    quuid.cpp \
    qvariant.cpp \
    qversionnumber.cpp \
    qvsnprintf.cpp \
    qxmlstream.cpp \
    qxmlutils.cpp

HEADERS += \
    qabstractfileengine_p.h \
    qarraydata.h \
    qarraydataops.h \
    qarraydatapointer.h \
    qbitarray.h \
    qbuffer.h \
    qbytearray.h \
    qbytearraymatcher.h \
    qcalendar.h \
    qcalendarbackend_p.h \
    qcalendarmath_p.h \
    qcborstreamwriter.h \
    qcborvalue.h \
    qcborvalue_p.h \
    qchar.h \
    qcryptographichash.h \
    qdatetime.h \
    qdatetime_p.h \
    qdir.h \
    qdir_p.h \
    qdiriterator.h \
    qfile.h \
    qfileinfo.h \
    qglobal.h \
    qgregoriancalendar_p.h \
    qhash.h \
    qiodevice.h \
    qjson_p.h \
    qjsonarray.h \
    qjsondocument.h \
    qjsonobject.h \
    qjsonparser_p.h \
    qjsonvalue.h \
    qjsonwriter_p.h \
    qlist.h \
    qlocale.h \
    qlocale_tools_p.h \
    qmap.h \
    qmetatype.h \
    qnumeric.h \
    qregexp.h \
    qregularexpression.h \
    qromancalendar_p.h \
    qstring.h \
    qstringbuilder.h \
    qstringlist.h \
    qstringmatcher.h \
    qsystemerror_p.h \
    qtemporaryfile.h \
    qtextstream.h \
    qutfcodec_p.h \
    quuid.h \
    qvector.h \
    qversionnumber.h \
    qxmlstream.h \
    qxmlutils_p.h

include(../src/3rdparty/pcre2/pcre2.pri)

unix {
    SOURCES += \
        qcore_unix.cpp \
        qfilesystemengine_unix.cpp \
        qfilesystemiterator_unix.cpp \
        qfsfileengine_unix.cpp \
        qlocale_unix.cpp
    macos {
        SOURCES += \
            qcore_foundation.mm \
            qcore_mac.mm \
            qoperatingsystemversion_darwin.mm \
            qsettings_mac.cpp
        LIBS += \
            -framework ApplicationServices \
            -framework CoreServices \
            -framework Foundation
        QMAKE_CXXFLAGS += -fconstant-cfstrings
    }
} else {
    SOURCES += \
        qfilesystemengine_win.cpp \
        qfilesystemiterator_win.cpp \
        qfsfileengine_win.cpp \
        qlocale_win.cpp \
        qoperatingsystemversion_win.cpp \
        qsettings_win.cpp \
        qsystemlibrary.cpp \
        registry.cpp
    LIBS += -lole32 -ladvapi32 -lkernel32 -lnetapi32
    mingw: LIBS += -luuid
    clang: QMAKE_CXXFLAGS += -fms-compatibility-version=19.00.23506 -Wno-microsoft-enum-value
}
