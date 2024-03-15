/*
 * =====================================================================================
 *
 *       Filename:  HighEnergyCoefficientFunctions.h
 *
 *    Description:  Header file for the
 * HighEnergyCoefficientFunctions.cc file.
 *
 *         Author:  L'allenamento si fa!
 *
 *  In this file there are the coefficient functions in the
 * high energy limit, i.e. x -> 0
 *
 * =====================================================================================
 */

#ifndef HighEnergy_h
#define HighEnergy_h

#include "adani/CoefficientFunction.h"

//==========================================================================================//
//                      Notation:
//      High energy: small x limit
//      High energy high scale: Q^2 >> m^2 limit of the
//      small x limit (or the opposite) Power terms: power
//      terms in the small x liimit, obtained via
//          C_powerterms = C_highenergy -
//          C_highenergy_highscale
//------------------------------------------------------------------------------------------//

class AbstractHighEnergyCoefficientFunction : public CoefficientFunction {
    public:
        AbstractHighEnergyCoefficientFunction(const int& order, const char& kind, const char& channel, const bool& NLL = true) ;
        ~AbstractHighEnergyCoefficientFunction() override {};

        // get methods
        bool GetNLL() const {return NLL_;};

        // set methods
        void SetNLL(const bool& NLL) {NLL_ = NLL ; } ;

        virtual Value fx(double x, double m2Q2, double m2mu2, int nf) const = 0;
        Value MuIndependentTerms(double x, double m2Q2, int nf) const {return fx(x, m2Q2, 1., nf);} ;
        Value MuDependentTerms(double x, double m2Q2, double m2mu2, int nf) const ;

    private:
        bool NLL_ ;

    //==========================================================================================//
    //                  Color factors O(alpha_s^3)
    //------------------------------------------------------------------------------------------//

    protected:
        double a_10(int nf) const;
        double a_11() const;
        double a_21(int nf) const;
};

class HighEnergyCoefficientFunction : public AbstractHighEnergyCoefficientFunction {

    public:
        HighEnergyCoefficientFunction(const int& order, const char& kind, const char& channel, const bool& NLL = true) : AbstractHighEnergyCoefficientFunction(order, kind, channel, NLL) {};
        ~HighEnergyCoefficientFunction() override {} ;

        Value fx(double x, double m2Q2, double m2mu2, int nf) const override ;

    private:

        //==========================================================================================//
        //                      High energy coefficient functions
        //                      O(alpha_s^2)
        //------------------------------------------------------------------------------------------//

        double C2_g2_highenergy(double x, double m2Q2, double m2mu2) const ;
        double C2_ps2_highenergy(double x, double m2Q2, double m2mu2) const ;
        double CL_g2_highenergy(double x, double m2Q2, double m2mu2) const ;
        double CL_ps2_highenergy(double x, double m2Q2, double m2mu2) const ;

        //==========================================================================================//
        //                      High energy coefficient functions
        //                      O(alpha_s^3) at leading log
        //------------------------------------------------------------------------------------------//

        double C2_g3_highenergyLL(double x, double m2Q2, double m2mu2) const ;
        double CL_g3_highenergyLL(double x, double m2Q2, double m2mu2) const ;
        double C2_ps3_highenergyLL(double x, double m2Q2, double m2mu2) const ;
        double CL_ps3_highenergyLL(double x, double m2Q2, double m2mu2) const ;

        Value C2_g3_highenergyNLL(double x, double m2Q2, double m2mu2, int nf) const ;
        Value CL_g3_highenergyNLL(double x, double m2Q2, double m2mu2, int nf) const ;

        //==========================================================================================//
        //                      High energy coefficient functions
        //                      O(alpha_s^3)
        //------------------------------------------------------------------------------------------//

        Value C2_g3_highenergy(double x, double m2Q2, double m2mu2, int nf) const ;
        Value C2_ps3_highenergy(double x, double m2Q2, double m2mu2, int nf) const ;
        Value CL_g3_highenergy(double x, double m2Q2, double m2mu2, int nf) const ;
        Value CL_ps3_highenergy(double x, double m2Q2, double m2mu2, int nf) const ;

};

class HighEnergyHighScaleCoefficientFunction : public AbstractHighEnergyCoefficientFunction {

    public:
        HighEnergyHighScaleCoefficientFunction(const int& order, const char& kind, const char& channel, const bool& NLL = true) : AbstractHighEnergyCoefficientFunction(order, kind, channel, NLL) {};
        ~HighEnergyHighScaleCoefficientFunction() override {} ;

        Value fx(double x, double m2Q2, double m2mu2, int nf) const override ;

    private:

        //==========================================================================================//
        //                      Q>>m limit of the high energy
        //                      coefficient functions O(alpha_s^2)
        //------------------------------------------------------------------------------------------//

        double C2_g2_highenergy_highscale(double x, double m2Q2, double m2mu2) const ;
        double C2_ps2_highenergy_highscale(double x, double m2Q2, double m2mu2) const ;
        double CL_g2_highenergy_highscale(double x, double m2Q2, double m2mu2) const ;
        double CL_ps2_highenergy_highscale(double x, double m2Q2, double m2mu2) const ;

        //==========================================================================================//
        //  Q>>m limit of the high energy coefficient functions
        //  O(alpha_s^3) at leading log
        //------------------------------------------------------------------------------------------//

        double C2_g3_highenergy_highscaleLL(double x, double m2Q2, double m2mu2) const;
        double CL_g3_highenergy_highscaleLL(double x, double m2Q2, double m2mu2) const;
        double C2_ps3_highenergy_highscaleLL(double x, double m2Q2, double m2mu2) const;
        double CL_ps3_highenergy_highscaleLL(double x, double m2Q2, double m2mu2) const;

        Value C2_g3_highenergy_highscaleNLL(
            double x, double m2Q2, double m2mu2, int nf
        ) const;
        // double C2_ps3_highenergy_highscaleNLL(double x, double
        // m2Q2, double m2mu2, int nf, int v);
        Value CL_g3_highenergy_highscaleNLL(
            double x, double m2Q2, double m2mu2, int nf
        ) const;
        // double CL_ps3_highenergy_highscaleNLL(double x, double
        // m2Q2, double m2mu2, int nf, int v);

        //==========================================================================================//
        //                  Q^2>>m^2 limit of the high energy
        //                  coefficient functions O(alpha_s^3)
        //------------------------------------------------------------------------------------------//

        Value
        C2_g3_highenergy_highscale(double x, double m2Q2, double m2mu2, int nf) const;
        Value
        C2_ps3_highenergy_highscale(double x, double m2Q2, double m2mu2, int nf) const;
        Value
        CL_g3_highenergy_highscale(double x, double m2Q2, double m2mu2, int nf) const;
        Value
        CL_ps3_highenergy_highscale(double x, double m2Q2, double m2mu2, int nf) const;

};

class PowerTermsCoefficientFunction : public AbstractHighEnergyCoefficientFunction {

    public:
        PowerTermsCoefficientFunction(const int& order, const char& kind, const char& channel, const bool& NLL = true);
        ~PowerTermsCoefficientFunction() override ;

        Value fx(double x, double m2Q2, double m2mu2, int nf) const ;

    private:

        HighEnergyCoefficientFunction *highenergy_ ;
        HighEnergyHighScaleCoefficientFunction *highenergyhighscale_ ;

};

#endif
