#include "adani/ThresholdCoefficientFunctions.h"
#include "adani/ExactCoefficientFunctions.h"
#include "adani/SpecialFunctions.h"
#include "adani/Constants.h"
#include "adani/SpecialFunctions.h"

#include <cmath>


//==========================================================================================//
//  Threshold limit (x->xmax) of the gluon coefficient function for F2 at O(alpha_s).
//  In order to pass to klmv normalization multiply mQ*4*M_PI*M_PI*x
//
//  Eq. (3.15) of Ref. [arXiv:1205.5727]
//------------------------------------------------------------------------------------------//

double C2_g1_threshold(double x, double mQ) {

    double xmax = 1. / (1. + 4 * mQ) ;

    if (x>=xmax || x<0) return 0;

    double beta = sqrt(1. - 4. * mQ * x / (1. - x)) ;
    double xi = 1. / mQ ;

    return xi / (4 * M_PI) * TR * beta / (1. + xi / 4) / x ;

}

//==========================================================================================//
//
//------------------------------------------------------------------------------------------//

double threshold_expansion_g2(double x, double mQ, double mMu) {

    double xmax = 1. / (1. + 4 * mQ) ;

    if(x>=xmax || x<0) return 0;

    double beta = sqrt(1. - 4 * mQ * x / (1. - x));

    double logb = log(beta) ;
    double log2b = logb * logb ;

    double C_log2b = 16 * CA ;

    double C_logb = 48 * CA * ln2 - 40 * CA + 8 * CA * log(mMu) ;

    double C_fracb = (2 * CF - CA) * M_PI * M_PI ;

    return (
        C_log2b * log2b + C_logb * logb + C_fracb / beta
    ) / (4. * M_PI);

}

//==========================================================================================//
//
//------------------------------------------------------------------------------------------//

double threshold_expansion_g2_const(double mQ, double mMu) {

    double xi = 1. / mQ ;

    return (
        c0(xi) + 36 * CA * ln2 * ln2 - 60 * CA * ln2
        + log(mMu) * (8 * CA * ln2 - c0_bar(xi))
    ) / (4. * M_PI);

}

//==========================================================================================//
//  Threshold limit (x->xmax) of the gluon coefficient function for F2 at O(alpha_s^2).
//  In order to pass to klmv normalization multiply mQ*M_PI*x and put mu^2=Q^2+4m^2
//
//  Eq. (3.16) of Ref. [arXiv:1205.5727]
//------------------------------------------------------------------------------------------//

double C2_g2_threshold(double x, double mQ, double mMu) {

    return C2_g1(x,mQ) * (
        threshold_expansion_g2(x, mQ, mMu)
        + threshold_expansion_g2_const(mQ, mMu)
    ) ;

}

//==========================================================================================//
//  Threshold limit (x->xmax) of the gluon coefficient function for FL at O(alpha_s^2).
//  In order to pass to klmv normalization multiply mQ*M_PI*x and put mu^2=Q^2+4m^2
//
//  Eq. (3.16) of Ref. [arXiv:1205.5727] with C20 -> CL0
//------------------------------------------------------------------------------------------//

double CL_g2_threshold(double x, double mQ, double mMu) {

    return CL_g1(x,mQ) * (
        threshold_expansion_g2(x, mQ, mMu)
        + threshold_expansion_g2_const(mQ, mMu)
    ) ;

}

//==========================================================================================//
//  beta independent term of the threshold limit (x->xmax) of the gluon coefficient function
//  for F2 at O(alpha_s^2).
//
//  Eq. (3.17) of Ref. [arXiv:1205.5727]
//------------------------------------------------------------------------------------------//

double C2_g2_threshold_const(double x, double mQ, double mMu) {

    return C2_g1(x, mQ) * threshold_expansion_g2_const(mQ, mMu) ;

}

//==========================================================================================//
//  beta independent term of the threshold limit (x->xmax) of the gluon coefficient function
//  for FL at O(alpha_s^2).
//
//  Eq. (3.17) of Ref. [arXiv:1205.5727] with C20 -> CL0
//------------------------------------------------------------------------------------------//

double CL_g2_threshold_const(double x, double mQ, double mMu) {

    return CL_g1(x,mQ) * threshold_expansion_g2_const(mQ, mMu) ;

}

//==========================================================================================//
//
//------------------------------------------------------------------------------------------//

double threshold_expansion_g3(double x, double mQ, double mMu, int nf) {

    double x_max = 1. / (1. + 4 * mQ);

    if(x>=x_max || x<0) return 0;

    double xi = 1. / mQ ;
    double beta = sqrt(1. - 4. * mQ * x / (1. - x));

    double Lm = log(mMu);
    double Lm2 = Lm * Lm;
    double l = log(beta);
    double l2 = l * l;
    double l3 = l2 * l;
    double l4 = l3 * l;

    double ln2_2 = ln2 * ln2 ;
    double ln2_3 = ln2_2 * ln2 ;

    double pi2 = M_PI * M_PI ;
    double pi4 = pi2 * pi2 ;

    double c_log4 = 128. * CA * CA ;

    double c_log3 = (
        (768. * ln2 - 6464. / 9.) * CA * CA
        + 128. / 9. * CA * nf
        + 128. * CA * CA * Lm
    ) ;

    double c_log2 = (
        (
            1728. * ln2_2 - 3232. * ln2
            - 208./3. * pi2 + 15520./9.
        ) * CA * CA
        + (64. * ln2 - 640. / 9.) * CA * nf
        + 16. * CA * c0(xi)
        + 32. * CA * (CF - CA / 2) * pi2 / beta
        - (
            (-512 * ln2 + 1136./3.) * CA * CA - 32./3. * CA * nf
            + 16 * CA * c0_bar(xi)
        ) * Lm + 32 * CA * CA * Lm2
    ) ;

    double c_log_const = (
        (
            1728. * ln2_3 - 4848 * ln2_2 + 15520./3. * ln2
            - 208 * pi2 * ln2 + 936 * zeta3 + 608./3. * pi2 - 88856./27.
        ) * CA * CA
        + (96. * ln2_2 - 640./3. * ln2 - 16./3. * pi2 + 4592./27.) * CA * nf
        - 32. * CF * (CF - CA / 2) * pi2 + (48. * ln2 - 40.) * CA * c0(xi)
    );

    double c_log_fracbeta = (
        (- 92./3. + 32. * ln2) * CA + 8./3. * nf
    ) * (CF - CA / 2) * pi2 ;

    double c_log_Lm = - (
        (- 672. * ln2_2 + 976 * ln2 + 104./3. * pi2 - 4160./9.) * CA * CA
        + (- 32. * ln2 + 320./9.) * CA * nf + (48. * ln2 - 40.) * CA * c0_bar(xi)
        - 8. * CA * c0(xi) - 16. * CA * (CF - CA/2) * pi2 / beta
    ) ;

    double c_log_Lm2 = (
        (64. * ln2 - 44./3.) * CA * CA
        + 8./3. * CA * nf - 8. * CA * c0_bar(xi)
    );

    double c_log = (
        c_log_const
        + c_log_fracbeta / beta
        + c_log_Lm * Lm
        + c_log_Lm2 * Lm2
    );

    double c_fracbeta = (
        (8. * ln2_2 - 68./3. * ln2 + 8./3. * pi2 - 658./9.) * CA
        + (8./3. * ln2 - 20./9.) * nf + 2 * c0(xi)
        + (26./3. * CA + 4./3. * nf - 2 * c0_bar(xi)) * Lm
    ) * (CF - CA/2) * pi2 ;

    double c_fracbeta2 = 4./3.* (CF - CA/2) * (CF - CA/2) * pi4;

    return (
        c_log4 * l4 + c_log3 * l3 + c_log2 * l2 + c_log * l
        + c_fracbeta / beta + c_fracbeta2 / beta / beta
    ) / (pi2 * 16.) ;

}

//==========================================================================================//
//
//------------------------------------------------------------------------------------------//

double threshold_expansion_g3_const(double mQ, double mMu) {

    double xi = 1. / mQ ;
    double Lm = log(mMu);

    double pi2 = M_PI * M_PI ;

    double c_const_sqrt = (
        c0(xi) + 36. * CA * ln2 * ln2 - 60. * CA * ln2
        + Lm * (8. * CA * ln2 - c0_bar(xi))
    );

    return c_const_sqrt * c_const_sqrt / (16. * pi2) ;

}

//==========================================================================================//
//  Threshold limit (x->xmax) of the gluon coefficient function for F2 at O(alpha_s^3).
//
//  Eq. (3.18) of Ref. [arXiv:1205.5727]
//------------------------------------------------------------------------------------------//

double C2_g3_threshold(double x, double mQ, double mMu, int nf) {

    return C2_g1(x,mQ) * (
        threshold_expansion_g3(x, mQ, mMu, nf)
        + threshold_expansion_g3_const(mQ, mMu)
    );

}

//==========================================================================================//
//  Threshold limit (x->xmax) of the gluon coefficient function for FL at O(alpha_s^3).
//
//  Eq. (3.18) of Ref. [arXiv:1205.5727] with C20 -> CL0
//------------------------------------------------------------------------------------------//

double CL_g3_threshold(double x, double mQ, double mMu, int nf) {

    return CL_g1(x,mQ) * (
        threshold_expansion_g3(x, mQ, mMu, nf)
        + threshold_expansion_g3_const(mQ, mMu)
    );

}

//==========================================================================================//
//  Approximation for the beta independent term of the threshold limit (x->xmax) of the
//  gluon coefficient function for F2 at O(alpha_s^3).
//
//  Eq. (3.19) of Ref. [arXiv:1205.5727]
//------------------------------------------------------------------------------------------//

double C2_g3_threshold_const(double x, double mQ, double mMu) {

    return C2_g1(x,mQ) * threshold_expansion_g3_const(mQ, mMu);

}

//==========================================================================================//
//  Approximation for the beta independent term of the threshold limit (x->xmax) of the
//  gluon coefficient function for FL at O(alpha_s^3).
//
//  Eq. (3.19) of Ref. [arXiv:1205.5727] with C20 -> CL0
//------------------------------------------------------------------------------------------//

double CL_g3_threshold_const(double x, double mQ, double mMu) {

    return CL_g1(x,mQ) * threshold_expansion_g3_const(mQ, mMu);

}

//==========================================================================================//
//  Function needed for the threshold limit.
//
//  Eq. (3.10) from Ref. [arXiv:1205.5727]
//------------------------------------------------------------------------------------------//

double c0(double xi) {

    double y = sqrt(1. + 4./xi ) ;

    double L1 = log(1. + xi/2 ) ;
    double L2 = log(2. + xi/2 ) ;
    double L3 = log( sqrt(xi) * (y - 1.) / 2) ;

    double xp2 = 2. + xi ;
    double xp4 = 4. + xi ;

    double Li_2 = Li2(- 2. / xp2);
    double pi2 = M_PI * M_PI ;

    double c_CA = (
        50. - pi2 + 12 * L3 / y + 4 * L3 * L3 + L1 * L1 + 6 * L2
        - 4. * L2 * L2 + 2 * Li_2 + 48. / xp2 - 4. * L2 / xp2 + 64. * L2 / xp2 / xp2
        - 128. * L2 /(xp2 * xp2 * xp4) - 160. / xp2 / xp4 - 64. * L2 / xp2 / xp4
        + 128. / (xp2 * xp4 * xp4) - 12. * (4. + zeta2) / xp4 - 8. * L3 * L3 / xp4
        + 64. / xp4 / xp4
    );

    double c_CF= (
        - 18. - 2./3. * pi2 - 24. * L3 / y - 8. * L3 * L3 + 2. * L1 * L1 - 6. * L2
        + 4. * Li_2 - 48. / xp2 + 8. * L2 / xp2 + 360. / xp2 / xp4 + 128. * L2 / xp2 / xp4
        - 544. / (xp2 * xp4 * xp4) + 48. * L3 * L3 / xp4 - 8. * L1 * L1 / xp4
        + (44. + 40. * zeta2) / xp4 - 120. * L2 / xp2 / xp2 + 256. * L2 / (xp2 * xp2 * xp4)
        - 16 * Li_2 / xp4 - 272 / xp4 / xp4
    ) ;

    return CA * c_CA + CF * c_CF ;

}

//==========================================================================================//
//  Function needed for the threshold limit.
//
//  Eq. (3.11) from Ref. [arXiv:1205.5727]
//------------------------------------------------------------------------------------------//


double c0_bar(double xi) {

    return 4 * CA * (2. + log(1. + xi/4) ) - 4./3. * TR ;

}
