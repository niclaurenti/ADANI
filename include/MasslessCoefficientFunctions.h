/*
 * =====================================================================================
 *
 *       Filename:  MasslessCoefficientFunctions.h
 *
 *    Description:  Header file for the MasslessCoefficientFunctions.cc file.
 *
 *         Author:  LeBron James
 *   Organization:  Los Angeles Lakers (at the time of writing)
 *
 *  In this file there are the exact heavy coefficient functions
 *
 * =====================================================================================
 */
#ifndef Massless_h
#define Massless_h

//==========================================================================================//
//                      MAssless coefficient funtions O(alpha_s)
//------------------------------------------------------------------------------------------//

double C2_g1(double x, int nf);
double CL_g1(double x, int nf);

//==========================================================================================//
//                      Massless coefficient funtions O(alpha_s^2)
//------------------------------------------------------------------------------------------//

double C2_g2(double x, int nf);
double C2_ps2(double x, int nf);

double CL_g2(double x, int nf);
double CL_ps2(double x, int nf);

//==========================================================================================//
//                      Massless coefficient funtions O(alpha_s^3)
//------------------------------------------------------------------------------------------//

double C2_g3(double x, int nf);
double C2_ps3(double x, int nf);

double CL_g3(double x, int nf);
double CL_ps3(double x, int nf);


#endif
