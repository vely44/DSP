/*!
  @file 

  Opdracht 1 DSB practicum. Werk deze opdracht verder uit aan de hand van het kommentaar.
  Assignment 1 DSB practical. Elaborate this assignment on the basis of the comments.

  @version $Rev: 3286 $
  @author $Author: ewout $ 
  @note  Werk deze code verder uit volgens de opdracht   / Complete this code according to the assignment.
  @copyright Copyright 2006-2019 ir drs E.J Boks Hogeschool van Arnhem en Nijmegen
  $Id: dsbklassen.h 3286 2019-01-18 15:46:42Z ewout $
*/

#ifndef DSBCOMPLEX_H
#define DSBCOMPLEX_H

#include <algdef.h>
#include <string.h>

#ifdef BouwDesktopApp
#include <wx/string.h>
#endif

#if (InterfaceTaalNederlands)

/* voorwaarts */
class Complex;

/*! @brief een polair getal heeft een amplitude en richting als bepalende kenmerken. */
class PolairGetal
{
public:

	/*! @brief Std constructor met grootte en fasehoek. */
	explicit PolairGetal(const float amp = 0,
	                     const float hoek = 0);

	/*! @brief Constructor op basis van een cartesisch complex getal. */
	explicit PolairGetal(const Complex &);

	/*! @brief Geef de grootte (lineair) van het polaire getal.
	 * @return de grootte. */
	float Mag() const;
	/*! @brief Geef de fasehoek (0 .. 2*pi) van het polaire getal.
	 * @return de fasehoek. */
	float Arg() const;

#ifdef BouwDesktopApp
	/*! @brief logging funktie */
	wxString str() const;
	/*! @brief Formatteer als string in een formaat dat ook geimporteerd kan worden. */
	wxString wiskstr() const;
#endif

private:
	float grootte,fase;
};

/*! @class Een cartesisch complex getal bestaand uit een reÃ«el en een imaginair gedeelte. */
class Complex
{
public:
	/*! @brief constexpr constructors for the Complex class. */
	explicit constexpr Complex(const float xin=0,const float yin=0) : x(xin),y(yin)
	{

	};

	/*! @brief Constructors for the Complex class.
	 * @note Geen template ==> maak deze constructors aan in de cpp file. */
	explicit Complex(const PolairGetal &);

	/*! @brief Importeer een polair getal. */
	Complex & operator = (const PolairGetal &);

	/*! @brief Belangrijke overloaded operators van een complex getal.
	 * @note maak deze funkties in de cpp file. */
	bool operator == (const Complex &rhs) const;
	Complex  operator + (const Complex &rhs) const; /* + overload */
	Complex  operator - (const Complex &rhs) const;  /* - overload */
	Complex  operator * (const Complex &rhs) const;  /* * overload */
	Complex  operator * (const float rhs) const;  /* * met float overload */
	Complex  operator / (const Complex &rhs) const;  /* / overload */
	Complex & operator += (const Complex &rhs);  /* += overload */
	Complex & operator -= (const Complex &rhs); /* -= overload */

	/*! @brief Bereken de wortel van een complex getal.
		@return de waarde. 
		@note De student hoeft deze functie niet te implementeren. */
	Complex sqrt() const;

	float Re() const
	{
		return(x);
	};

	float Im() const
	{
		return(y);
	};

	bool isImaginair() const
	{
		const bool imag = (x == 0.0f);
		return(imag);
	}

	bool isReeel() const
	{
		const bool re = (y == 0.0f);
		return(re);
	}

	/*! @brief Conversie funkties naar grootte/argument.
	 * @note maak deze in de cpp file aan. */
	float Mag() const;      /* grootte (lineair) */
	float Arg() const;      /* fasehoek (0 .. 2*pi) */

	/*! @brief Conversie naar polaire representatie.
	 * @note maak deze aan */
	PolairGetal polair() const;

	/*! @brief De funktie levert de geconjugeerde versie van het huidige object. Maak aan. */
	Complex conj() const;

#ifdef BouwDesktopApp
	/*! @brief print het complexe getal als wxString */
	wxString str() const;
	/*! @brief Formatteer als string in een formaat dat ook geimporteerd kan worden. */
	wxString wiskstr() const;

	/*! @brief importeer een string in het formaat a+bj of r,phi in deze variabele.
	 * @param De tekst met het compelxe getal.
	 * @note Het formaat moet zijn : a+bj of r,phi .
	 * @return Is de importeer aktie gelukt of niet. */
	RetCode importeer(const wxString &);
#endif

protected:


private:

	float x,y;   /* het complexe getal z=x+jy */
};

#elif defined (InterfaceTaalEnglish)

/* forward declaration.  */
class Complex;

/*! @class a polar number has an amplitude and direction as defining characteristics. */
class PolarNumber
{
public:

	/*! @brief Std constructor with size and phase angle. */
	explicit PolarNumber(const float amp = 0.0,
	                     const float angle = 0.0);

	/*! @brief Constructor based on a Cartesian complex number. */
	explicit PolarNumber(const Complex &);

	/*! @brief Specify the size (linear) of the polar number.
	 * @return The size. */
	float Mag() const;
	/*! @brief Enter the phase angle (0 .. 2 * pi) of the polar number.
	 * @return the phase angle. */
	float Arg() const;

    void setMag(float mag) { magnitude = mag; }
    void setArg(float arg) { phase = arg; }
#ifdef BouwDesktopApp
	/*! @brief logging function */
	wxString str() const;
#endif

private:
	float magnitude,phase;
};

/*! @class A Cartesian complex number consisting of a real and an imaginary part. */
class Complex
{
public:
	/*! @brief Constructors for the Complex class.
	 * @note No template ==> create these constructors in the cpp file. */
	explicit Complex(const float xin=0,const float yin=0);
	explicit Complex(const PolarNumber &);

	/*! @brief Import a polar number using the operator. */
	Complex& operator = (const PolarNumber &);
	
	/*! @brief Important overloaded operators of a complex number.
	 * @note make these functions in the cpp file. */
	bool operator == (const Complex &rhs) const;
	Complex  operator + (const Complex &rhs); /* + overload */
	Complex  operator - (const Complex &rhs);  /* - overload */
	Complex  operator * (const Complex &rhs);  /* * overload */
	Complex  operator / (const Complex &rhs);  /* / overload */
	Complex & operator += (const Complex &rhs);  /* += overload */
	Complex & operator -= (const Complex &rhs); /* -= overload */

	float Re() const
	{
		return(x);
	};

	float Im() const
	{
		return(y);
	};

	/*! @brief Conversion functions to size / argument.
	 * @note make these functions in the cpp file. */
	float Mag() const;      /* magnitude (linear) */
	float Arg() const;      /* phase angle (0 .. 2*pi) */

	/*! @brief Conversion to polar representation.
	 * @note make this function in the cpp file */
	PolarNumber polar() const;

	/*! @brief The function provides the conjugate version of the current object. */
	Complex conj() const;

#ifdef BouwDesktopApp
	/*! @brief print the complex number as a wxString */
	wxString str() const;
	
	/*! @brief Format as string in a format dat can be imported below. */
	wxString wiskstr() const;

	/*! @brief import a string in the format a+bj or r,phi into this variable.
	 * @param The text containing the complex number.
	 * @note The format should be : a+bj or r,phi .
	 * @return Status of the import. */
	RetCode import(const wxString&);
#endif

protected:


private:

	float x,y;   /* The complexe number z=x+jy */
};

#else
#error "Defineer een taal !!!!\n Define a language !!!!"
#endif /* #if (InterfaceTaalNederlands) */


#ifdef BouwDesktopApp

#include <wx/dynarray.h>
/*! @brief Een ComplexArray is een wxArray van Complex.
 */
WX_DECLARE_OBJARRAY(Complex, ComplexArray);

#endif

#endif




