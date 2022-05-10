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

    /* Student part
     * calculate moving average */
    ema = (alfa * input) + (minalfa * ema);
    return ema;

}

