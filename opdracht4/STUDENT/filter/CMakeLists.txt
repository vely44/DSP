#  @file 
#  FirFilter voor opdracht 4 en 5 DSB practicum
#  @version $Rev: 4060 $
#  @author $Author: ewout $ 
#  @copyright Copyright 2006-2019 ir drs E.J Boks Hogeschool van Arnhem en Nijmegen
#  $Id: CMakeLists.txt 4060 2021-01-14 14:44:56Z ewout $

set(Opdracht1Dir ../../../opdracht1)

include_directories(${Opdracht1Dir})

set(SRCS firfilter.cpp)

list(SORT SRCS)

add_library(FirFilterLib STATIC ${SRCS})
