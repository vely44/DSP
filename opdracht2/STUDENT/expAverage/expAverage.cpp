/*!
@file
Exponentieel Gemiddelde (Exponential Average) implementatie voor Opdracht 2 / Assignment 2.

@version $Rev: 3303 $
@author $Author: ewout $
@copyright Copyright 2006-2019 ir drs E.J Boks Hogeschool van Arnhem en Nijmegen
$Id: expAverage.cpp 3303 2019-01-29 11:41:50Z ewout $
*/

#include "expAverage.h"
#include <assert.h>

ExponentialAverageFilter::ExponentialAverageFilter(const float wf) : alfa(wf),minalfa(1.0f-wf)
{
	assert((alfa > 0.0f) && (alfa <= 1.0f));
}

float ExponentialAverageFilter::filter(const float input)
{
#error “Dit stuk software ontbreekt / This part of the software is missing !!”
/* Geachte student,
    Dit stuk ontbreekt. Werk dit uit om de opdracht uit te voeren. 
     Honourable student,
     This part of the software is missing. Fill in your implementation to fulfill the task. */

}

