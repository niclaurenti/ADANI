/*
 * =====================================================================================
 *
 *       Filename:  SplittingFunctions.h
 *
 *    Description:  Header file for the
 * SplittingFunctions.cc file.
 *
 *         Author:  A livello di servilismo come siamo
 * messi?
 *
 *  In this file there are the splitting functions.
 *
 * =====================================================================================
 */

#ifndef Split
#define Split

class AbstractSplittingFunction {
    public:
        AbstractSplittingFunction() {mult_factor_ = 1.;} ;
        ~AbstractSplittingFunction() {};

        virtual double Regular(const double x, const int nf) const = 0;
        virtual double Singular(const double x, const int nf) const = 0;
        virtual double Local(const int nf) const = 0;
        virtual double SingularIntegrated(const double x, const int nf) const = 0;

        double GetMultFact() const {return mult_factor_;};
        void SetMultFact(const double& mult_factor) {mult_factor_ = mult_factor;};

    private:
        double mult_factor_;
};

class SplittingFunction : public AbstractSplittingFunction{
    public:
        SplittingFunction(const int& order, const char& entry1, const char& entry2) ;
        ~SplittingFunction() {} ;

        double Regular(const double x, const int nf) const ;
        double Singular(const double x, const int nf) const ;
        double Local(const int nf) const ;
        double SingularIntegrated(const double x, const int nf) const;

        SplittingFunction operator*(const double& rhs) const;
        friend SplittingFunction operator*(const double& lhs, const SplittingFunction& rhs);

        SplittingFunction operator/(const double& rhs) const;

        void SetFunctions() ;

        // get methods
        double GetOrder() const {return order_ ;} ;
        char GetEntry1() const {return entry1_;} ;
        char GetEntry2() const {return entry2_;} ;

    private:
        int order_;
        char entry1_;
        char entry2_;

        double (SplittingFunction::*reg_)(double, int) const;
        double (SplittingFunction::*sing_)(double, int) const;
        double (SplittingFunction::*sing_int_)(double, int) const;
        double (SplittingFunction::*loc_)(int) const;

        //==========================================================================================//
        //                      Splitting functions O(alpha_s)
        //                      without color factors
        //------------------------------------------------------------------------------------------//

        double pgq(const double x) const ;
        double pqg(const double x) const ;
        double pggreg(const double x) const ;
        double pggsing(const double x) const ;

        //==========================================================================================//
        //                      Splitting functions O(alpha_s)
        //------------------------------------------------------------------------------------------//

        double Pgq0(const double x) const ;
        double Pqg0(const double x, const int nf) const ;

        double Pgg0reg(const double x) const ;
        double Pgg0loc(const int nf) const ;
        double Pgg0sing(const double x) const ;
        double Pgg0sing_integrated(const double x) const;

        double Pqq0reg(const double x) const ;
        double Pqq0loc() const ;
        double Pqq0sing(const double x) const ;
        double Pqq0sing_integrated(const double x) const;

        //==========================================================================================//
        //                      Splitting functions O(alpha_s^2)
        //------------------------------------------------------------------------------------------//

        double Pgq1(const double x, const int nf) const ;

        double Pgg1reg(const double x, const int nf) const ;
        double Pgg1sing(const double x, const int nf) const ;
        double Pgg1sing_integrated(const double x, const int nf) const ;
        double Pgg1loc(const int nf) const ;

        double ZeroFunction_x_nf(double x, int nf) const {return 0.;};
        double ZeroFunction_nf(int nf) const {return 0.;};

};

class ConvolutedSplittingFunctions : public AbstractSplittingFunction {
    public:
        ConvolutedSplittingFunctions(const int& order, const char& entry1, const char& entry2, const char& entry3, const char& entry4);
        ~ConvolutedSplittingFunctions() {};

        char GetEntry3() const {return entry3_;} ;

        double Regular(const double x, const int nf) const ;

        double Singular(const double x, const int nf) const override {return 0.;} ;
        double Local(const int nf) const override {return 0.;} ;
        double SingularIntegrated(const double x, const int nf) const override {return 0.;};

        ConvolutedSplittingFunctions operator*(const double& rhs) const;
        friend ConvolutedSplittingFunctions operator*(const double& lhs, const ConvolutedSplittingFunctions& rhs);

        ConvolutedSplittingFunctions operator/(const double& rhs) const;

        void SetFunctions() ;

        // get methods
        double GetOrder() const {return order_ ;} ;
        char GetEntry1() const {return entry1_;} ;
        char GetEntry2() const {return entry2_;} ;
        char GetEntry3() const {return entry3_;} ;

    private:
        int order_;
        char entry1_;
        char entry2_;
        char entry3_;
        char entry4_;

        double (ConvolutedSplittingFunctions::*reg_)(double, int) const;

        //==========================================================================================//
        //  Convolution between the splitting functions Pgg0/Pqq0
        //  and Pgq0
        //------------------------------------------------------------------------------------------//

        double Pgg0_x_Pgq0(const double x, const int nf) const ;
        double Pqq0_x_Pgq0(const double x) const ;

        //==========================================================================================//
        //  Convolution between the splitting functions Pgq0 and Pqg0
        //------------------------------------------------------------------------------------------//

        double Pgq0_x_Pqg0(const double x, const int nf) const ;

        double ZeroFunction_x_nf(double x, int nf) const {return 0.;};
        double ZeroFunction_nf(int nf) const {return 0.;};
};

class Delta : public AbstractSplittingFunction {
    public:
        Delta() : AbstractSplittingFunction() {};
        ~Delta() {} ;

        double Regular(const double x, const int nf) const {return 0.;};
        double Singular(const double x, const int nf) const {return 0.;};
        double Local(const int nf) const {return GetMultFact() * 1.;};
        double SingularIntegrated(const double x, const int nf) const {return 0.;};

        Delta operator*(const double& rhs) const;
        friend Delta operator*(const double& lhs, const Delta& rhs);

        Delta operator/(const double& rhs) const;
};

#endif
