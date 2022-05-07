/*!
@file

Opdracht 4 DSB practicum (filter gedeelte). Werk deze opdracht verder uit aan de hand van het kommentaar.
Assignment 4 DSB practical (filter part). Elaborate this assignment on the basis of the comments.

@version $Rev: 4067 $
@author $Author: ewout $

@copyright Copyright 2006-2020 ir drs E.J Boks, Hogeschool van Arnhem en Nijmegen. https://ese.han.nl


$Id: firfilter.cpp 4067 2021-01-14 17:10:15Z ewout $
************************************************************************/

/* $Id: firfilter.cpp 4067 2021-01-14 17:10:15Z ewout $                               */

#include <assert.h>
#include <math.h>

#include "firfilter.h"

#if (InterfaceTaalNederlands)
#ifdef BouwDesktopApp
FilterFirInt16::FilterFirInt16(const FilterRingBuffer &coeffs,
                               const Int16 schaal) :  filterCoeffs(coeffs),
                                                      filterMemory(coeffs.geefAantal()),
                                                      loopUnroll4(coeffs.geefAantal()/4),
                                                      unrollRem(coeffs.geefAantal() % 4),
                                                      scaleFactor(schaal)
{

}
#endif

FilterFirInt16::FilterFirInt16(const FilterRingBuffer &coeffs,
                               const FilterRingBuffer &werkgeheugen,
                               const Int16 schaal) :  filterCoeffs(coeffs),
                                                      filterMemory(werkgeheugen),
                                                      loopUnroll4(coeffs.geefAantal()/4),
                                                      unrollRem(coeffs.geefAantal() % 4),
                                                      scaleFactor(schaal)
{

}

#elif defined (InterfaceTaalEnglish)

#ifdef BouwDesktopApp
FilterFirInt16::FilterFirInt16(const FilterRingBuffer &coeffs,
                               const Int16 scale) :  filterCoeffs(coeffs),
                                                      filterMemory(coeffs.giveSize()),
                                                      loopUnroll4(coeffs.giveSize()/4),
                                                      unrollRem(coeffs.giveSize() % 4),
                                                      scaleFactor(scale)
{

}
#endif

FilterFirInt16::FilterFirInt16(const FilterRingBuffer &coeffs,
                               const FilterRingBuffer &workMemory,
                               const Int16 scale) :  filterCoeffs(coeffs),
                                                      filterMemory(workMemory),
                                                      loopUnroll4(coeffs.giveSize()/4),
                                                      unrollRem(coeffs.giveSize() % 4),
                                                      scaleFactor(scale)
{

}


#endif

void FilterFirInt16::reset()
{

#error “Dit stuk software ontbreekt / This part of the software is missing !!”
/* Geachte student,
    Dit stuk ontbreekt. Werk dit uit om de opdracht uit te voeren. 
     Honourable student,
     This part of the software is missing. Fill in your implementation to fulfill the task. */


}


/* Implementatie van het filter */
Int16 FilterFirInt16::filter(const Int16 input)
{
#error “Dit stuk software ontbreekt / This part of the software is missing !!”
/* Geachte student,
    Dit stuk ontbreekt. Werk dit uit om de opdracht uit te voeren. 
     Honourable student,
     This part of the software is missing. Fill in your implementation to fulfill the task. */

}



