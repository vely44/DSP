////// -----*- C++ -*- generated by wxGlade 0.4 on Fri Feb 16 10:31:09 2007
/* $Id: filterOntwerper.h 3938 2020-06-13 12:18:19Z ewout $                    */

/************ Opdracht 3  DSB practicum                   ***************/
/************ Werk deze code verder uit volgens de opdracht      ********/
/************ Copyright 2006-2015 Hogeschool van Arnhem en Nijmegen     ********/
/************ ir drs E.J Boks                                    ********/

#ifndef HANESE_FILTERONTWERPER_OPDRACHT4_H
#define HANESE_FILTERONTWERPER_OPDRACHT4_H

#include <h/filterDesignerBasis.h>

#include <assert.h>

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/image.h>
#endif


#include <wx/config.h>
#include <wx/snglinst.h>
#include <wx/timer.h>
#include <wx/tooltip.h>

#include <algdef.h>

// begin wxGlade: ::dependencies
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/tglbtn.h>
// end wxGlade

#include <firfilter.h>

/*! @brief Deze klasse implementeert een wxWindow waarin de FIR berekening wordt uitgevoerd */
class FilterVenster: public wxFrame,public FilterDesignerBasis
{
public:
				// begin wxGlade: FilterVenster::ids
				// end wxGlade

	FilterVenster();

	~FilterVenster();

protected:

				// begin wxGlade: FilterVenster::attributes
				wxMenu* Bestandmenu;
				wxMenu* Filtermenu;
				wxMenuBar* venster_menubar;
				GrafiekVenster* tijdDomeinGrafiek;
				wxStaticText* tijdDomeinCoords;
				wxStaticLine* static_line_2;
				GrafiekVenster* freqDomeinGrafiek;
				wxCheckBox* toonAnalogeFrequentiesCheckBox;
				wxStaticText* freqDomeinCoords;
				GrafiekVenster* testGrafiek;
				wxScrolledWindow* testPaneel;
				wxStaticLine* static_line_1;
				wxButton* sampFreqButton;
				wxStaticText* sampFreqText;
				wxButton* ordeButton;
				wxStaticText* filterOrdeText;
				wxStaticText* nulDBniveauTxt;
				wxSpinCtrl* maxVersterkingSpinCtrl;
				wxStaticText* vensterTypeText;
				wxChoice* vensterChoice;
				wxStaticText* fipBitsText;
				wxSpinCtrl* fipBitsSpinCtrl;
				wxButton* berekenFilterKnop;
				wxCheckBox* toonfilterCoeffsCB;
				wxSlider* bandBeginSlider;
				wxSlider* bandEindeSlider;
				wxChoice* testSignaalChoice;
				wxToggleButton* filterTestButton;
				wxSlider* testSignaalSlider;
				wxSlider* testSignaalAmplitudeSlider;
				wxCheckBox* tekenOrigineelCheckBox;
				wxCheckBox* tekenSplineCheckBox;
				wxButton* button_1;
				wxPanel* hoofdPaneel;
				// end wxGlade


	void bandUpdateHandler(wxUpdateUIEvent &);
	void berekenUpdateHandler(wxUpdateUIEvent &);
	void testUpdateHandler(wxUpdateUIEvent &);
	void testOptiesUpdateHandler(wxUpdateUIEvent &);
	void testFreqGeldigHandler(wxUpdateUIEvent &);

	void eindeHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void sampFreqHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void testFreqHandler(wxScrollEvent &event); // wxGlade: <event_handler>
	void filterTestHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void berekenFilterHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void beginBandHandler(wxScrollEvent &event); // wxGlade: <event_handler>
	void eindeBandHandler(wxScrollEvent &event); // wxGlade: <event_handler>
	void bandControleHandler(wxScrollEvent &);  // wxGlade: <event_handler>
	void toonCoefficientenHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void filterOrdeHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void slaOpFilterHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void toonCopyrightHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void maxVersterkingHandler(wxSpinEvent &event); // wxGlade: <event_handler>
	void hammingVeranderdHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void slaOpFreqBeeldHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void toonAnalogeFreqsHandler(wxCommandEvent &event); // wxGlade: <event_handler>
	void testAmplHandler(wxScrollEvent &event); // wxGlade: <event_handler>
    void exporteerFilterImpulsBeeldHandler(wxCommandEvent &event); // wxGlade: <event_handler>

	/* event handlers om muisbeweging te detecteren */
	void tijdViewMuisBewegingHandler(wxMouseEvent &);
	void tijdViewBinnenkomstHandler(wxMouseEvent &);
	void tijdViewBuitengangHandler(wxMouseEvent &);

	void freqViewMuisBewegingHandler(wxMouseEvent &);
	void freqViewBinnenkomstHandler(wxMouseEvent &);
	void freqViewBuitengangHandler(wxMouseEvent &);

	void klokVerlopenHandler(wxTimerEvent &);

DECLARE_EVENT_TABLE();

private:

	/*! @note Vanaf hier \/  Door de student in te vullen funkties */
#ifdef InterfaceTaalNederlands
	/*! @brief de funktie die het Driehoek venster berekent.
	 * @param[in] n : het samplemoment.
	 * @return : DE vensterwaarde voor (n,M) */
	double driehoek(const Int32 n ) const;

	/*! @brief de funktie die het Hamming venster berekent.
	 * @param[in] n : het samplemoment.
	 * @return : DE vensterwaarde voor (n,M) */
	double hamming(const Int32 n) const;

	/*! @brief De funktie die sinc(hoek) uitvoert.
	 * @param[in] n : de hoek.
	 * @return : De sinc waar voor (hoek) */
	double sinc(double hoek ) const;

	void berekenFreqResponsie();  /* bereken de freq responsie  */
	void tekenFreqSpectrum() const;

	/*! @brief Deze  funktie moeten worden gebruikt om van
	 * floating point naar fixed point te converteren.
	 * @param flp : Floating point waarde.
	 * @return : De overeenkomstige fixed point waarde. */
	Int16 berekenFixedPoint(const float flp) const;

	/*! @brief Deze  funktie moeten worden gebruikt om van fixed point
	 * naar floating point te converteren.
	 * @param fixp : fixed point waarde.
	 * @return : De overeenkomstige floating point waarde. */
	float berekenFloatingPoint(const Int16 fixp) const;

#elif defined(InterfaceTaalEnglish)
	/*! @brief the function that calculates the Triangle window.
	 * @param[in] n : the sample moment.
	 * @return : The window value for (n) */
	double triangle(const Int32 n ) const;

	/*! @brief the function that calculates the Hamming window.
	 * @param[in] n : the sample moment.
	 * @return : The window value for (n) */
	double hamming(const Int32 n) const;

	/*! @brief the function that computes the sinc value.
	 * @param[in] angle : the angle.
	 * @return : The sinc value for (angle) */
	double sinc(double angle ) const;

	/*! @brief Compute the frequency response. */
	void computeFreqResponse();

	/*! @brief Draw the frequency response. */
	void drawFreqSpectrum() const;

	/*! @brief This feature must be used to from
	 * convert floating point to fixed point.
	 * @param flp : Floating point value.
	 * @return : The reciprocal fixed point value. */
	Int16 computeFixedPoint(const float flp) const;

	/*! @brief This function must be used to switch from fixed point
	 * convert to floating point.
	 * @param fixp : fixed point value.
	 * @return : The reciprocal floating point value. */
	float computeFloatingPoint(const Int16 fixp) const;


#endif
	/*! @note Tot hier /\  Door de student in te vullen funkties*/


	/*! @brief start en stop het filter */
	void filterStart();
	void filterStop();

				// begin wxGlade: FilterVenster::methods
				void set_properties();
				void do_layout();
				// end wxGlade

	bool bandControleRoutine(wxScrollEvent &) const;

	wxConfig *filterConfig;
	wxString dataPad;

	wxTimer klok;

	//UInt16 taps,orde;
	//Teller testIndex,testTekenIndex;

	PuntLijst filterSignaalLijst;

	/* Voor studenten : Dit is een array voor de fixed point filter coefficienten, vul deze uit jullie coefficientenfunktie.
	 * For students : This is an array for the fixed point filter coefficients, fill this out of your coefficient function. */
	wxArrayShort filterCoeffs;

	/* Voor studenten : Dit is een array voor de frequentie spectrum punten.
	 * For students : This is an array for the frequency spectrum points. */
	wxArrayDouble H_Omega;

	/* Voor studenten De minimale en maximale H(omega) respons. Let op H(omega) altijd 0 of kleiner !
	 * Gebruik deze waarden om te schalen.
	 * For students: The minimum and maximum H (omega) response. Note H (omega) always 0 or smaller!
	 * Use these values to scale.
	 */
	double H_Omega_min,H_Omega_max;

	FilterFirInt16 *filter;

	typedef enum
	{
		TijdGrafiekVensterID=0,
		FreqGrafiekVensterID,
		TestGrafiekVensterID,
		SampFreqID,
		SampFreqTextID,
		FilterOrdeID,
		FilterOrdeTextID,
		MaxVersterkingTextID,
		MaxVersterkingID,
		VensterKeuzeID,
		VensterKeuzeTekstID,
		FIPBitsTekstID,
		FIPBitsID,
		BandBeginSliderID,
		BandEindeSliderID,
		BerekenFilterAktieID,
		TestSignaalKeuzeID,
		TestFreqID,
		TestAmplitudeID,
		TekenOrigineelID,
		TekenSplineID,
		FilterTestID,
		ExporteerFilterImpulseBeeldID,
		ExporteerFreqBeeldID,
		ToonfilterCoeffsCBID,
		ToonAnalogeFrequentiesID,
		KlokVerlopenID,
		TijdCoordID,
		FreqCoordID
	} EventHandlerIDs;

	void OnMotion(wxMouseEvent &event);

	void OnEnterWindow(wxMouseEvent &event);

	void OnLeaveWindow(wxMouseEvent &event);
}; // wxGlade: end class




#endif // GEMWAARDE_H

