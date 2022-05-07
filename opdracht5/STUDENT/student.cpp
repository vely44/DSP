/*!
@file
Opdracht 5 DSB practicum. Werk deze opdracht verder uit aan de hand van het commentaar.
@version $Rev: 3773 $
@author $Author: ewout $

@copyright Copyright 2006-2020 ir drs E.J Boks, Hogeschool van Arnhem en Nijmegen. https://ese.han.nl

$Id: student.cpp 3773 2020-01-31 10:06:06Z ewout $
************************************************************************/

#if (InterfaceTaalNederlands)
#error  "(student.cpp) Student naam en nummer moeten beneden in de velden worden ingevuld."
#elif defined (InterfaceTaalEnglish)
#error  "(student.cpp) Student name and number must be entered into the fields below."
#endif
/********  Naam/name     :               ******/
/********  Studentnummer :               ******/

#include <student.h>
#include <firfilterexport.h>   /* Dit MOET aanwezig zijn in de map / this MUST be present in the directory.  */
#include <RTT/SEGGER_RTT.h>

STM32FilterApp::STM32FilterApp(): ESEBoardController(96),
                                   coeffsBuffer(AantalTaps,
                                                filterFixedCoeffs),
                                   filter(coeffsBuffer,filterInputBuffer,
                                          SchaalFaktor)
{
	/* Laat onderstaande statements zoals zij zijn /
	 * Leave following statements untouched. */
	schakelSysTick(Schakelaar::Uit);
	selekteerInput(STM32BoardController::DSBSignaalSelektor::BNCSignaal);
	selekteerADCAntiAlias(STM32BoardController::AntiAliasCtrl::AA5kHz);
	selekteerDACAntiAlias(STM32BoardController::AntiAliasCtrl::AA5kHz);
}


#ifdef InterfaceTaalNederlands
void STM32FilterApp::hoofdlus()
#else
void STM32FilterApp::mainloop()
#endif
{
#ifdef InterfaceTaalNederlands
	SEGGER_RTT_WriteString(0,"Start van filter applikatie.\n");
	SEGGER_RTT_WriteString(0,"Gebruik Segger RTT om het filtergedrag te debuggen, indien nodig.\n");
#else
	SEGGER_RTT_WriteString(0,"Start of the filter application.\n");
	SEGGER_RTT_WriteString(0,"Use Segger RTT to debug the filter performance, if required.\n");
#endif

	/* Werk deze funktie verder uit om er voor te zorgen dat :
		- De bemonstering frequentie van de ADC zodanig ingesteld wordt dat aan de opdrachteisen is voldaan.
		- De ADC start en dat de DA converter ook opgestart is.
	    - Gewacht wordt tot een sample ingelezen is.
	    - Het sample uit de ADC wordt opgehaald en wordt ingeladen in het filter.
	    - Het filter een waarde teruggeeft, welke vervolgens in de DA converter wordt ingeladen.
	    
	    English :
	    Develop this function further to ensure that:
		- The sampling frequency of the ADC is set so that the assignment requirements are met.
		- The ADC starts and that the DA converter is also started.
		- Wait until a sample has been read.
		- The sample from the ADC is retrieved and loaded into the filter.
		- The filter returns a value, which is then loaded into the DA converter.
	 */

#error “Dit stuk software ontbreekt / This part of the software is missing !!”
/* Geachte student,
    Dit stuk ontbreekt. Werk dit uit om de opdracht uit te voeren. 
     Honourable student,
     This part of the software is missing. Fill in your implementation to fulfill the task. */


	/* Hier mag de uitvoering niet komen / execution should not reach this point. */
	StopHier();

}

