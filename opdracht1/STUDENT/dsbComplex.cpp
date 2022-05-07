/*!
@file

Opdracht 1 DSB practicum. Werk deze opdracht verder uit aan de hand van het kommentaar.
Assignment 1 DSB practical. Elaborate this assignment on the basis of the comments.

@version $Rev: 3285 $
@author $Author: ewout $
@note  Werk deze code verder uit volgens de opdracht  / Complete this code according to the assignment.
@copyright Copyright 2006-2019 ir drs E.J Boks Hogeschool van Arnhem en Nijmegen
$Id: dsbklassen.cpp 3285 2019-01-17 14:25:32Z ewout $
*/

#include <cmath>
#include <cassert>

#include <dsbComplex.h>

#ifdef BouwDesktopApp
#include <iostream>
#include <wx/string.h>
#include <wx/log.h>

#include <wx/arrimpl.cpp> // This is a magic incantation which must be done!
WX_DEFINE_OBJARRAY(ComplexArray);

#endif

using namespace std;

#if (InterfaceTaalNederlands)
PolairGetal::PolairGetal(const float amp,
                         const float hoek) : grootte(amp),fase(hoek)
{

}

PolairGetal::PolairGetal(const Complex &z) : grootte(z.Mag()), fase(z.Arg())
{

}

#error “Dit stuk software ontbreekt / This part of the software is missing !!”
/* Geachte student,
    Dit stuk ontbreekt. Werk dit uit om de opdracht uit te voeren. 
     Honourable student,
     This part of the software is missing. Fill in your implementation to fulfill the task. */


#ifdef BouwDesktopApp
wxString PolairGetal::str() const
{
	const wxString uit(wxString::Format(wxT("|%.3f|*/_%.3f"),Mag(),Arg()));
	return(uit);
};

wxString PolairGetal::wiskstr() const
{
	const wxString uit(wxString::Format(wxT("%.3f:%.3f"),Mag(),Arg()));
	return(uit);
};

wxString Complex::str() const
{
	const wxString uit(wxString::Format(wxT("[Re:%.3f Im:%.3f]"),Re(),Im()));
	return(uit);
};

wxString Complex::wiskstr() const
{
	const wxString uit(wxString::Format(wxT("%.3f%+.3fj"),Re(),Im()));
	return(uit);
}

RetCode Complex::importeer(const wxString &invoer)
{
	auto retkode = RetCode::Onbekend;

	/* controleer of de string een imaginair stuk bevat */
	if (false == invoer.Contains(wxT("j")))
	{
		/* Kijk of het een polair getail is */
		if (false == invoer.Contains(wxT(":")))
		{
			/* Het is een volledig reel getal. */
			double waarde;
			const bool gelukt = invoer.ToDouble(&waarde);

			if (true == gelukt)
			{
				x = static_cast<float>(waarde);
				y = 0.0f;
			}
			retkode = (true == gelukt) ? RetCode::Ok : RetCode::Fout;
		}
		else
		{
			/* Het is een polair getal. */
			const wxString voorkomma(invoer.Before(':'));
			double rwaarde;
			const bool rgelukt = voorkomma.ToDouble(&rwaarde);
			if (false == rgelukt)
				retkode = RetCode::Fout;
			else
			{
				/* Doe phi */
				const wxString nakomma(invoer.After(':'));
				double phiwaarde;
				const bool phigelukt = nakomma.ToDouble(&phiwaarde);

				if (true == phigelukt)
				{
					/* voer het getal in */
					const PolairGetal pg(rwaarde, phiwaarde);
					Complex::operator=(pg);
				}

				retkode = ((true==phigelukt) ? RetCode::Ok : RetCode::Fout);
			}
		}
	}
	else
	{
		/* vind de reele en imaginaire komponenten. */
		wxString subinvoer(invoer.SubString(1,invoer.Length()));

		const bool posj = (true == subinvoer.Contains(wxT("+")));
		const bool negj = (true == subinvoer.Contains(wxT("-")));

		wxASSERT(posj != negj);

		if (true == posj)
		{
			const wxString voorj(invoer.Before('+'));
			double xwaarde;
			const bool xgelukt = voorj.ToDouble(&xwaarde);
			if (true == xgelukt)
				x = static_cast<float>(xwaarde);

			const wxString naplus(subinvoer.After('+'));
			const wxString imwaarde(naplus.Before('j'));
			double ywaarde;
			const bool ygelukt = imwaarde.ToDouble(&ywaarde);
			if (true == ygelukt)
				y = static_cast<float>(ywaarde);

			retkode = ((true==xgelukt) && (true==ygelukt)) ? RetCode::Ok : RetCode::Fout;
		}
		else
		{
			const wxString voorj(invoer.Before('-'));
			double xwaarde;
			const bool xgelukt = voorj.ToDouble(&xwaarde);
			if (true == xgelukt)
				x = static_cast<float>(xwaarde);

			const wxString naplus(subinvoer.After('-'));
			const wxString imwaarde(naplus.Before('j'));
			double ywaarde;
			const bool ygelukt = imwaarde.ToDouble(&ywaarde);
			if (true == ygelukt)
				y = -1.0f*static_cast<float>(ywaarde);

			retkode = ((true==xgelukt) && (true==ygelukt)) ? RetCode::Ok : RetCode::Fout;
		}
	}

	return(retkode);
}


#endif

#elif defined (InterfaceTaalEnglish)

PolarNumber::PolarNumber(const float amp,
                         const float angle) : magnitude(amp),
                                              phase(angle)
{

}

PolarNumber::PolarNumber(const Complex &z) : magnitude(z.Mag()),
                                             phase(z.Arg())
{

}

float PolarNumber::Mag()  const
{
    return magnitude;
}

float PolarNumber::Arg()  const
{
    return phase;
}

Complex::Complex(const float xin, const float yin) : x(xin), y(yin)
{

}

Complex::Complex(const PolarNumber&)
{
    x=Mag()*cos(Arg());
    y=Mag()*sin(Arg());
}

Complex Complex::operator+(const Complex &rhs)
{
    auto result = *this;
    result.x+= rhs.x;
    result.y+=rhs.y;
    return result;
}

Complex Complex::operator- (const Complex &rhs)
{
    auto result = *this;
    result.x-= rhs.x;
    result.y-=rhs.y;
    return result;
}

Complex Complex::operator* (const Complex &rhs)
{
    auto result = *this;
    result.x= (x*rhs.x)-(y*rhs.y);
    result.y= (x*rhs.y)+(y*rhs.x);
    return result;
}

Complex Complex::operator/ (const Complex &rhs)
{
    auto result = *this;
    result.x= ((x*rhs.x)+(y*rhs.y) / (rhs.x*rhs.x) + (rhs.y*rhs.y));
    result.y= ((x*rhs.y)-(y*rhs.x) / (rhs.x*rhs.x) + (rhs.y*rhs.y));
    return result;
}

bool Complex::operator== (const Complex& rhs) const
{
    //auto result = *this;
    if(rhs.x==x && rhs.y ==y){
        return true;
    }
    else{
            return false;
        }
}

Complex& Complex::operator+= (const Complex& rhs)
{
    x += rhs.x;
    y += rhs.y;

    return *this;
}

Complex& Complex::operator-= (const Complex& rhs)
{
    x -= rhs.x;
    y -= rhs.y;

    return *this;
}


float Complex::Mag() const
{
    float result = sqrt(x*x+y*y);
    return result;
}


float Complex::Arg() const
{
    float result = atan2(y,x);
    return result;
}




#ifdef BouwDesktopApp
wxString PolarNumber::str() const
{
	return(wxString::Format(wxT("|%.3f|*/_%.3f"),Mag(),Arg()));
};
wxString Complex::str() const
{
	return(wxString::Format(wxT("[Re:%.3f Im:%.3f]"),Re(),Im()));
};


wxString Complex::wiskstr() const
{
	const wxString uit(wxString::Format(wxT("%.3f%+.3fj"), Re(), Im()));
	return(uit);
}

RetCode Complex::import(const wxString& invoer)
{
	auto retkode = RetCode::Onbekend;

	/* controleer of de string een imaginair stuk bevat */
	if (false == invoer.Contains(wxT("j")))
	{
		/* Kijk of het een polair getail is */
		if (false == invoer.Contains(wxT(":")))
		{
			/* Het is een volledig reel getal. */
			double waarde;
			const bool gelukt = invoer.ToDouble(&waarde);

			if (true == gelukt)
			{
				x = static_cast<float>(waarde);
				y = 0.0f;
			}
			retkode = (true == gelukt) ? RetCode::Ok : RetCode::Fout;
		}
		else
		{
			/* Het is een polair getal. */
			const wxString voorkomma(invoer.Before(':'));
			double rwaarde;
			const bool rgelukt = voorkomma.ToDouble(&rwaarde);
			if (false == rgelukt)
				retkode = RetCode::Fout;
			else
			{
				/* Doe phi */
				const wxString nakomma(invoer.After(':'));
				double phiwaarde;
				const bool phigelukt = nakomma.ToDouble(&phiwaarde);

				if (true == phigelukt)
				{
					/* voer het getal in */
					const PolarNumber pg(rwaarde, phiwaarde);
					Complex::operator=(pg);
				}

				retkode = ((true == phigelukt) ? RetCode::Ok : RetCode::Fout);
			}
		}
	}
	else
	{
		/* vind de reele en imaginaire komponenten. */
		wxString subinvoer(invoer.SubString(1, invoer.Length()));

		const bool posj = (true == subinvoer.Contains(wxT("+")));
		const bool negj = (true == subinvoer.Contains(wxT("-")));

		wxASSERT(posj != negj);

		if (true == posj)
		{
			const wxString voorj(invoer.Before('+'));
			double xwaarde;
			const bool xgelukt = voorj.ToDouble(&xwaarde);
			if (true == xgelukt)
				x = static_cast<float>(xwaarde);

			const wxString naplus(subinvoer.After('+'));
			const wxString imwaarde(naplus.Before('j'));
			double ywaarde;
			const bool ygelukt = imwaarde.ToDouble(&ywaarde);
			if (true == ygelukt)
				y = static_cast<float>(ywaarde);

			retkode = ((true == xgelukt) && (true == ygelukt)) ? RetCode::Ok : RetCode::Fout;
		}
		else
		{
			const wxString voorj(invoer.Before('-'));
			double xwaarde;
			const bool xgelukt = voorj.ToDouble(&xwaarde);
			if (true == xgelukt)
				x = static_cast<float>(xwaarde);

			const wxString naplus(subinvoer.After('-'));
			const wxString imwaarde(naplus.Before('j'));
			double ywaarde;
			const bool ygelukt = imwaarde.ToDouble(&ywaarde);
			if (true == ygelukt)
				y = -1.0f * static_cast<float>(ywaarde);

			retkode = ((true == xgelukt) && (true == ygelukt)) ? RetCode::Ok : RetCode::Fout;
		}
	}

	return(retkode);
}

#endif


#endif
