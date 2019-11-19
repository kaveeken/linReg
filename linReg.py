import numpy as np
import math

def nelMeadInit(a,b):
    # xj = x0 + hj*ej
    # ej unit vector of j-th coord axis, hj step size
    # x0 non-zero: hj = 0.05, x0 == 0: hj = 0.00025
    ab = [[a,b]]
    if a == 0: ab.append([a * 0.00025, b])
    else: ab.append([a * 0.05, b])
    if b == 0: ab.append([a, b * 0.00025])
    else: ab.append([a, b * 0.05])
    return np.asarray(ab)

def objective(x,y,a,b):
    fx = a * x + b
    msd = np.sum(np.power(fx - y,2)) / len(x)
    return msd ** 0.5

def nelMeadStep(x,y,ab,tol,i=0,n=800):
    i += 1
    if i >= n:
        return 1, ab[np.argmin(err)]
    alpha = 1
    gamma = 2
    rho = 0.5
    sigma = 0.5
    err = []
    for entry in ab:
        err.append(objective(x,y,entry[0],entry[1]))
    if min(err) < tol:
        # termination
        return 0, ab[np.argmin(err)]
    excl = np.argmax(err)
    abCu = np.asarray([l for i, l in enumerate(ab) if i!=excl])
    errC = [l for i, l in enumerate(err) if i!=excl]
    # for 2D, centroid:
    coid = (abN[0] + abCu[1]) / 2

    # reflection:
    abRf = coid + alpha * (coid - ab[excl])
    erR = objective(x,y,abRf[0],abRf[1])
    # does this work?
    if  erR > max(errC):
        return nelMeadStep(x,y,np.append(abCu,abRf))

    elif erR < min(errC):
        # expansion
        abEx = coid + gamma * (abRf - coid)
        if objective(x,y,abEx[0],abEx[1]) < erR:
            return nelMeadStep(x,y,np.append(abCu,abEx))
        else: return nelMeadStep(x,y,np.append(abCu,abRf))

    elif erR >= max(errC):
        # contraction
        abCo = coid + rho * (ab[excl] - coid)
        if objective(x,y,abCo[0],abCo[1]) < max(err):
            return nelMeadStep(x,y,np.append(abCu,abCo))

        else:


def linReg(x,y,tol,n=800):
    # ax + b
    # first estimate
    # a1 = corr(x,y) * stdev(y) / stdev(x)
    num = np.sum((x - x.mean()) * (y - y.mean()))
    den = np.sum((x - x.mean()) ** 2)
    aEst = num / den
    bEst = y.mean() - a1 * x.mean()
    ab = nelMeadInit(aEst,bEst)
