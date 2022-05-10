/*!
@file
Exponentieel Gemiddelde (Exponential Average) API voor Opdracht 2 / Assignment 2.

@version $Rev: 3524 $
@author $Author: ewout $
@copyright Copyright 2006-2019 ir drs E.J Boks Hogeschool van Arnhem en Nijmegen
$Id: expAverage.h 3524 2019-05-27 14:10:06Z ewout $
*/

#ifndef ExpGemiddelde_H
#define ExpGemiddelde_H

class ExponentialAverageFilter
{
public:
	/*! @brief Constructor for the exponential averaging filter.
	 * @param The Weighing factor alfa (0..1,0)
	 */
	explicit ExponentialAverageFilter(const float );


	/*! @brief perform an averaging action on the input
	 * @param The input sample.
	 * @return the exp average value. */
	float filter(const float);

private:

    /* Student part here */
    float ema = 0.0f;


	/* The weighing factor and its counterpart (1-alfa)  */
	const float alfa;
	const float minalfa;
};


#endif // ExpGemiddelde_H


