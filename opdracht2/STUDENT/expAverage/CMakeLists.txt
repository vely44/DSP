#/************************************************************************
# CMake script voor wxWidgets CMake software bouwen.
# Copyright 2004-2019 Hogeschool van Arnhem en Nijmegen
# Opleiding Embedded Systems Engineering
# $Id: CMakeLists.txt 3285 2019-01-17 14:25:32Z ewout $
#************************************************************************/

set(SRCS expAverage.cpp)

list(SORT SRCS)

add_library(ExpAverageLib STATIC ${SRCS})