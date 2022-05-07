/* Dit is een C/C++ Header bestand                                                         */
/* Opdracht 4 Digitale Signaalbewerking                                                */
/* Copyright 2006-2017 Opleiding Embedded Systems Engineering, Hogeschool van Arnhem en Nijmegen          */
/* Tijdstempel : 2017-06-01 18:20:07 */
/* Onderstaande coefficienten zijn voor een bandpass Q14 fixed-point implementatie FIR filter */
/* Start van de band : 0,097656*PI (2000 Hz bij fs=20480 Hz) */
/* Einde van de band : 0,122070*PI (2500 Hz bij fs=20480 Hz) */
/* Taps : 61 */

#ifndef FilterCoeffsExport_H
#define FilterCoeffsExport_H

typedef signed short Int16;

const unsigned int AantalTaps=61;
const Int16 SchaalFaktor=16383;

const Int16 filterFixedCoeffs[AantalTaps] = 
{
#error “Dit stuk software ontbreekt / This part of the software is missing !!”
/* Geachte student,
    Dit stuk ontbreekt. Werk dit uit om de opdracht uit te voeren. 
     Honourable student,
     This part of the software is missing. Fill in your implementation to fulfill the task. */

};

const float filterFloatCoeffs[AantalTaps] = 
{
#error “Dit stuk software ontbreekt / This part of the software is missing !!”
/* Geachte student,
    Dit stuk ontbreekt. Werk dit uit om de opdracht uit te voeren. 
     Honourable student,
     This part of the software is missing. Fill in your implementation to fulfill the task. */

};


#endif
