/*
 * =====================================================================================
 *
 *       Filename:  MatchingConditions.h
 *
 *    Description:  Header file for the
 * MatchingConditions.cc file.
 *
 *         Author:  Vamo!!
 *
 *  In this file there are the matching conditions.
 *
 * =====================================================================================
 */

#ifndef Match_h
#define Match_h

//==========================================================================================//
//  Matching conditions O(alpha_s)
//------------------------------------------------------------------------------------------//

double K_Qg1(double x, double m2mu2);
double K_gg1_local(double m2mu2);

//==========================================================================================//
//  Matching conditions O(alpha_s^2)
//------------------------------------------------------------------------------------------//

double K_Qg2(double x, double m2mu2);

//==========================================================================================//
//  Matching conditions O(alpha_s^3)
//------------------------------------------------------------------------------------------//

double a_Qg_30(double x, int v, int damp=0, double m2Q2=0.);

double a_Qq_PS_30(double x, int v = 0);

#endif
