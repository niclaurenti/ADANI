import adani as ad
import oldadani as oldad
import numpy as np

def test_mudependent_terms():
    for order in [2, 3]:
        for channel in ['g', 'q']:
            for kind in ['2', 'L']:
                for dim in [100, 1000]:
                    for MCcalls in [10000, 20000]:
                        for mf in [0, 1]:
                            for abserr in [1e-2, 1e-3]:
                                relerr = abserr
                                massive = ad.ExactCoefficientFunction(order, kind, channel, abserr, relerr, dim, mf, MCcalls)
                                app = ad.ApproximateCoefficientFunction(order, kind, channel,True, False, True, abserr, relerr, dim, mf, MCcalls)
                                x = np.geomspace(1e-5, 1., 10, endpoint=True)
                                for xi in np.geomspace(1e-2, 1e4, 4, endpoint=True):
                                    for nf in range(1, 6 + 1):
                                        res1 = [massive.MuDependentTerms(x_, 1/xi, 1/xi, nf) for x_ in x]
                                        res2 = [app.MuDependentTerms(x_, 1/xi, 1/xi, nf) for x_ in x]
                                        np.testing.assert_allclose(res1, res2, rtol=1e-7)
                                del massive
                                del app

def test_C30_oldversion():
    for channel in ['g', 'q']:
        for kind in ['2', 'L']:
            exact = True if channel == 'q' else False
            hs_appr = True if channel == 'g' else False
            app = ad.ApproximateCoefficientFunction(3, kind, channel,True, exact, hs_appr)
            for xi in np.geomspace(1e-2, 1e2, 10):
                m2Q2 = 1/xi
                for x in np.geomspace(1e-5, 1, 10):
                    for nf in range(1, 6 + 1):
                        for v in [0, 1, -1]:
                            if kind == '2':
                                if channel == 'g':
                                    res_old = oldad.C2_g3_approximation(x, m2Q2, 1., nf, v)
                                if channel == 'q':
                                    res_old = oldad.C2_ps3_approximation(x, m2Q2, 1., nf, v)
                            if kind == 'L':
                                if channel == 'g':
                                    res_old = oldad.CL_g3_approximation(x, m2Q2, 1., nf, v)
                                if channel == 'q':
                                    res_old = oldad.CL_ps3_approximation(x, m2Q2, 1., nf, v)
                            tmp = app.MuIndependentTermsBand(x, m2Q2, nf)
                            if v == 0:
                                res_new = tmp.GetCentral()
                            if v == -1:
                                res_new = tmp.GetLower()
                            if v == 1:
                                res_new = tmp.GetHigher()
                            np.testing.assert_allclose(res_old, res_new, rtol=1e-7)

def test_mudep_oldversion():
    for channel in ['g', 'q']:
        for kind in ['2', 'L']:
            exact = True if channel == 'q' else False
            hs_appr = True if channel == 'g' else False
            for mf in [0]:
                app = ad.ApproximateCoefficientFunction(3, kind, channel,True, exact, hs_appr, 1e-3, 1e-3, 1000, mf, 25000)
                for xi in np.geomspace(1e-2, 1e2, 10):
                    m2Q2 = 1/xi
                    xmax = 1/(1 + 4*m2Q2)
                    Lmu = -np.log(m2Q2)
                    for x in np.geomspace(1e-5, 1, 10):
                        for nf in range(1, 6 + 1):
                            if kind == '2':
                                if channel == 'g':
                                    res_old = oldad.C2_g31(x, m2Q2, nf) * Lmu + oldad.C2_g32(x, m2Q2, nf, mf) * Lmu**2
                                if channel == 'q':
                                    res_old = oldad.C2_ps31(x, m2Q2, nf) * Lmu + oldad.C2_ps32(x, m2Q2, nf) * Lmu**2
                            if kind == 'L':
                                if channel == 'g':
                                    res_old = oldad.CL_g31(x, m2Q2, nf) * Lmu + oldad.CL_g32(x, m2Q2, nf, mf) * Lmu**2
                                if channel == 'q':
                                    res_old = oldad.CL_ps31(x, m2Q2, nf) * Lmu + oldad.CL_ps32(x, m2Q2, nf) * Lmu**2
                            if x > xmax:
                                res_old = 0.
                            res_new = app.MuDependentTerms(x, m2Q2, m2Q2, nf)
                            np.testing.assert_allclose(res_old, res_new, rtol=1e-7)
            del app
