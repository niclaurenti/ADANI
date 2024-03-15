/*
 * =====================================================================================
 *
 *       Filename:  HighScaleCoefficientFunctions.h
 *
 *    Description:  Header file for the
 * HighScaleCoefficientFunctions.cc file.
 *
 *         Author:  Da quella posizione trasforma l'acqua in
 * vino
 *
 *  In this file there are the coefficient functions in the
 * high scale limit, i.e. Q^2 >> m^2
 *
 * =====================================================================================
 */

#ifndef HighScale_h
#define HighScale_h

#include "adani/CoefficientFunction.h"
#include "adani/MasslessCoefficientFunctions.h"
#include "adani/MatchingConditions.h"

//==========================================================================================//
//                      The notation used is the following:
//                      C^{(k)} = k-th order expansion in
//                      terms of \alpha_s^{[nf]} D^{(k)} =
//                      k-th order expansion in terms of
//                      \alpha_s^{[nf+1]}
//------------------------------------------------------------------------------------------//

class HighScaleCoefficientFunction : public CoefficientFunction {
    public:
        HighScaleCoefficientFunction(const int& order, const char& kind, const char& channel, const bool& exact, const bool& revised_approx) ;
        ~HighScaleCoefficientFunction() override ;

        Value fx(double x, double m2Q2, double m2mu2, int nf) const ;

    private:
        MasslessCoefficientFunction* massless_lo_;
        MasslessCoefficientFunction* massless_nlo_;
        MasslessCoefficientFunction* massless_nnlo_;
        MatchingCondition* a_muindep_;

//==========================================================================================//
//                      High scale (Q^2 >> m^2) coefficient
//                      functions O(alpha_s)
//------------------------------------------------------------------------------------------//

double C2_g1_highscale(double x, double m2Q2) const ;
double CL_g1_highscale(double x) const ;

double D2_g1_highscale(double x, double m2Q2) const ;
double DL_g1_highscale(double x) const;

//==========================================================================================//
//                      High scale (Q^2 >> m^2) coefficient
//                      functions O(alpha_s^2)
//------------------------------------------------------------------------------------------//

double C2_g2_highscale(double x, double m2Q2, double m2mu2) const ;
double C2_ps2_highscale(double z, double m2Q2, double m2mu2) const ;

double CL_g2_highscale(double x, double m2Q2, double m2mu2) const ;
double CL_ps2_highscale(double x, double m2Q2, double m2mu2) const ;

double D2_g2_highscale(double x, double m2Q2, double m2mu2) const ;
double D2_ps2_highscale(double x, double m2Q2, double m2mu2) const ;

double DL_g2_highscale(double z, double m2Q2, double m2mu2) const ;
double DL_ps2_highscale(double z, double m2Q2, double m2mu2) const ;

//==========================================================================================//
//                      High scale (Q^2 >> m^2) coefficient
//                      functions O(alpha_s^3)
//------------------------------------------------------------------------------------------//

Value C2_g3_highscale(double x, double m2Q2, double m2mu2, int nf) const ;
Value C2_ps3_highscale(double x, double m2Q2, double m2mu2, int nf) const ;

double CL_g3_highscale(double x, double m2Q2, double m2mu2, int nf) const ;
double CL_ps3_highscale(double x, double m2Q2, double m2mu2, int nf) const ;

double DL_g3_highscale(double z, double m2Q2, double m2mu2, int nf) const ;
double DL_ps3_highscale(double z, double m2Q2, double m2mu2, int nf) const ;

Value D2_g3_highscale(double x, double m2Q2, double m2mu2, int nf) const ;
Value D2_ps3_highscale(double x, double m2Q2, double m2mu2, int nf) const ;

//==========================================================================================//
//  High scale (Q^2 >> m^2) coefficient functions at
//  O(alpha_s^3) used in [arXiv:1205.5727] klmv = Kawamura,
//  Lo Presti, Moch, Vogt This functions uses the
//  approximation for aQqPS30 (that now is exactly known)
//  from Eq. ?? of [arXiv:1205.5727]. It is only used for
//  benchmark against the plots on the paper
//------------------------------------------------------------------------------------------//

// double
// C2_ps3_highscale_klmv_paper(double x, double m2Q2, double m2mu2, int nf, int v) const ;
// double
// D2_ps3_highscale_klmv_paper(double x, double m2Q2, double m2mu2, int nf, int v) const ;

};

#endif
