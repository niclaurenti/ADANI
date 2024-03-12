#ifndef CoeffFunc
#define CoeffFunc

#include "adani/SplittingFunctions.h"

class Value {
    public:
        Value(const double& central, const double& higher, const double& lower) ;


    private:
        double central;
        double higher;
        double lower;
};

class CoefficientFunction {

    public:
        CoefficientFunction(const int& order, const char& kind, const char& channel) ;
        // CoefficientFunction() : CoefficientFunction(1, '2', 'g') {} ;
        virtual ~CoefficientFunction() = 0 ;

        virtual double fx(const double x, const double m2Q2, const double m2mu2, const int nf) const = 0 ;
        virtual double MuIndependentTerms(const double x, const double m2Q2, const int nf) const {return fx(x, m2Q2, 1., nf);} ;
        virtual double MuDependentTerms(const double x, const double m2Q2, const double m2mu2, const int nf) const {
            return fx(x, m2Q2, m2mu2, nf) - fx(x, m2Q2, 1., nf);
        }

        // get methods
        int GetOrder() const { return order_; } ;
        char GetKind() const { return kind_; } ;
        char GetChannel() const { return channel_; } ;

        // set methods
        void SetOrder(const int& order) ;
        void SetKind(const char& kind) ;
        void SetChannel(const char& channel) ;

    private:
        int order_ ; // order = 1, 2, or 3
        char kind_ ; // kind_ = '2' for F2 and 'L' for FL
        char channel_ ; // channel_ = 'g' for Cg and 'q' for Cq

};

#endif
