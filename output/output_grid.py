import adani
from multiprocessing import Pool
import yaml
import numpy as np
import time

with open("runcard.yaml", 'r') as stream:
    try:
        runcard=yaml.safe_load(stream)
    except yaml.YAMLError as exc:
        print(exc)

m = runcard["m"]
nf = runcard["nf"]
calls = runcard["calls"]
mufrac = runcard["mufrac"]

def function_to_exe_in_parallel(pair):
    x, q = pair
    mu = mufrac * q
    mQ = m**2 / q**2
    mMu = m**2 / mu**2
    if runcard["channel"] == "2g":
        return adani.C2m_g3_approximation(x, mQ, mMu, nf, 1, calls)
    elif runcard["channel"] == "2q":
        return adani.C2m_ps3_approximation(x, mQ, mMu, nf)
    elif runcard["channel"] == "Lg":
        return adani.CLm_g3_approximation(x, mQ, mMu, nf, 1, calls)
    elif runcard["channel"] == "Lq":
        return adani.CLm_ps3_approximation(x, mQ, mMu, nf)
    else:
        raise ValueError("Set channel to one of these: 2g 2q Lg Lq")


def run(n_threads, x_grid, Q_grid):
    grid = []
    for q in Q_grid:
        for x in x_grid:
            grid.append((x, q))
    args = (function_to_exe_in_parallel, grid)
    with Pool(n_threads) as pool:
        result = pool.map(*args)
    return result

if __name__ == "__main__":
    xfname = "x.txt"
    xlines = [l.strip() for l in open(xfname)]
    xdata = np.array([ l.split() for l in xlines ])
    x_grid = np.array([float(i) for i in (xdata[0,:])])
    Qfname = "Q.txt"
    Qlines = [l.strip() for l in open(Qfname)]
    Qdata = np.array([ l.split() for l in Qlines ])
    Q_grid = np.array([float(i) for i in (Qdata[0,:])])

    x_grid = np.linspace(0.1, 1., 10)
    Q_grid = np.linspace(10, 200, 20)

    print(f"Computation of the grid for the coefficient function C{runcard['channel']} for m = {m} GeV, nf = {nf}, and µ/Q = {mufrac}")
    print(f"Size of the grid (x,Q) = ({len(x_grid)},{len(Q_grid)})")

    start = time.perf_counter()
    res_vec=np.array(run(runcard["n_threads"], x_grid, Q_grid))
    print("total running time: ", time.perf_counter() - start)

    res_mat = res_vec.reshape(len(Q_grid), len(x_grid))

    print("Saving grid in ", runcard["output_file"])
    with open(runcard["output_file"], 'w') as f:
        for row in res_mat:
            print(*row, file=f)
