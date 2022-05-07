
#/************************************************************************
# CMake script voor het bouwen van wxWidgets CMake software
# Copyright 2004-2017 Hogeschool van Arnhem en Nijmegen
# Opleiding Embedded Systems Engineering
# $Id: CMakeLists.txt 3884 2020-05-25 13:57:12Z ewout $
#************************************************************************/


include_directories(h)

set(SRCS filterOntwerper.cpp filterDesignerBasis.cpp)

list(SORT SRCS)

add_library(FilterOntwerperLib STATIC ${SRCS})