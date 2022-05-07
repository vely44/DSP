/*************** DSB practicum opdracht 5 *****************/
/* $Id: student.h 3563 2019-07-04 12:42:53Z ewout $     */
/*************** Code API van de student *********************/

#ifndef DSBOPDRACHT5_STUDENT_H
#define DSBOPDRACHT5_STUDENT_H

/*************** VUL HIER NAAM en STUDENTNUMMER in ************/
/*************** en verwijder de preprocessor error aanduiding */
//#error  "(student.h) nog geen naam en studentnummer ingevuld ingevuld."    
/********  Naam :               ******/
/********  Studentnummer :      ******/

#include <firfilter.h>

#include <ESEBoardController.h>
#include "firfilterexport.h"
/******************************************************************************************************/
/* Geachte student : vul in deze klasse jullie code in */
/******************************************************************************************************/

class STM32FilterApp : public ESEBoardController
{
public:
    explicit STM32FilterApp();

    /*! @brief De hoofdlus van het programma. Hierin wordt het filter toegepast.
	   The main loop of the program. The filter is applied here. */
#ifdef InterfaceTaalNederlands
    void hoofdlus();
#else
	void mainloop();
#endif

private:

	StaticFilterRingBuffer<AantalTaps> filterInputBuffer;
	FilterRingBuffer coeffsBuffer;

	/*! @brief Dit is het filter dat door jullie geimplementeerd werd in opdracht 4.
	 * This is the filter that you implemented in assignment 4. */
	FilterFirInt16 filter;


	char tekstbuffer[100];
	static constexpr auto DSB_ADC_Channel=ADS131A02::Kanaal::K2;
	static constexpr auto DSB_DAC_Channel=MAX5136::Kanaal::K2;
};



#endif /* DSB_STUDENT_H */


