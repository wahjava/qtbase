# Generated from qdiriterator.pro.

#####################################################################
## tst_bench_qdiriterator Binary:
#####################################################################

qt_add_benchmark(tst_bench_qdiriterator
    SOURCES
        main.cpp
        qfilesystemiterator.cpp qfilesystemiterator.h
    PUBLIC_LIBRARIES
        Qt::Test
)

## Scopes:
#####################################################################

qt_extend_target(tst_bench_qdiriterator CONDITION (QT_FEATURE_cxx17_filesystem) AND (GCC AND (QMAKE_GCC_MAJOR_VERSION LESS 9))
    LINK_OPTIONS
        "-lstdc++fs"
)
