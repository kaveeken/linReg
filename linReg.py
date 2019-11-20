import numpy as np
from matplotlib import pyplot as plt
import math

def nelMeadInit(a,b):
    # xj = x0 + hj*ej
    # ej unit vector of j-th coord axis, hj step size
    # x0 non-zero: hj = 0.05, x0 == 0: hj = 0.00025
    ab = [[a,b]]
    if a == 0: ab.append([a + a * 0.025, b])
    else: ab.append([a + a * 1, b])
    if b == 0: ab.append([a, b + b * 0.025])
    else: ab.append([a, b + b * 1])
    return np.asarray(ab)

def objective(x,y,a,b):
    fx = a * x + b
    msd = np.sum(np.power(fx - y,2)) / len(x)
    return msd ** 0.5

def nelMead(x,y,ab,i=0,n=800):
#    print(ab,type(ab))
    i += 1
    if i % 100 == 0:
        print(i)
    alpha = 0.6
    gamma = 1.2
    rho = 0.5
    sigma = 0.5
    err = []
    #print(ab[0])
    #print('wut')
    err.append(objective(x,y,ab[0,0],ab[0,1]))
    err.append(objective(x,y,ab[1,0],ab[1,1]))
    err.append(objective(x,y,ab[2,0],ab[2,1]))
    #for entry in ab:
    #    print(entry)
    #    err.append(objective(x,y,entry[0],entry[1]))
    # success termination
    # failure termination
    if math.isclose(ab[0,0],ab[1,0], abs_tol=0.000001) and \
       math.isclose(ab[0,0],ab[2,0], abs_tol=0.000001) and \
       math.isclose(ab[0,1],ab[1,1], abs_tol=0.000001) and \
       math.isclose(ab[0,1],ab[2,1], abs_tol=0.000001):
#        print(ab)
        print('convergence')
        return 0, ab[0]
    if i >= n:
        print('fail')
#        print(err)
        return 1, ab[np.argmin(err)]
    excl = np.argmax(err)
    abCu = np.asarray([l for i, l in enumerate(ab) if i!=excl])
    errC = [l for i, l in enumerate(err) if i!=excl]
    # for 2D, centroid:
    coid = (abCu[0] + abCu[1]) / 2

    # reflection:
    abRf = coid + alpha * (coid - ab[excl])
    erR = objective(x,y,abRf[0],abRf[1])
    #print(abCu[:])
    #jprint(abRf)
    #print(np.append(abCu,[abRf],axis=0))
    # does this work?
    if  erR > max(errC):
 #       print("reflected")
        return nelMead(x,y,np.append(abCu,[abRf],axis=0),i=i,n=n)

    elif erR < min(errC):
        # expansion
        abEx = coid + gamma * (abRf - coid)
        if objective(x,y,abEx[0],abEx[1]) < erR:
 #           print("expanded")
            return nelMead(x,y,np.append(abCu,[abEx],axis=0),i=i,n=n)
        else:
 #           print("reflected")
            return nelMead(x,y,np.append(abCu,[abRf],axis=0),i=i,n=n)

    elif erR >= max(errC):
        # contraction
        abCo = coid + rho * (ab[excl] - coid)
        if objective(x,y,abCo[0],abCo[1]) < max(err):
 #           print("contracted")
            return nelMead(x,y,np.append(abCu,[abCo],axis=0),i=i,n=n)

    else:
 #       print("shrinked")
        best = abCu[np.argmin(errC)]
        second = abCu[np.argmax(errC)]
        abShlst = [best,\
                   best + sigma * (second - best),\
                   best + sigma * (ab[excl] - best)]
        abSh = np.asarray(abShlst)
        #print(abSh)
#        abSh = np.append(best, \
#                         best + sigma * (second - best),\
#                         best + sigma * (ab[excl] - best),\
#                         axis = 0)
        return nelMead(x,y,abSh,i=i,n=n)

def linReg(x,y,n=800):
    # ax + b
    # first estimate
    # a1 = corr(x,y) * stdev(y) / stdev(x)
    num = np.sum((x - x.mean()) * (y - y.mean()))
    den = np.sum((x - x.mean()) ** 2)
    aEst = num / den
    bEst = y.mean() - aEst * x.mean()
    ab = nelMeadInit(0.9 * aEst, 0.8 * bEst)
    success, vector = nelMead(x,y,ab)
    return success, vector

xx = np.linspace(0,100,100)
delta = np.random.uniform(-10,10,xx.size)
yy = 4 * xx + 3 + delta

success, vector = linReg(xx,yy)
print()
print(success,vector,objective(xx,yy,vector[0],vector[1]))
yFit =  vector[0] * xx + vector[1]
num = np.sum((xx - xx.mean()) * (yy - yy.mean()))
den = np.sum((xx - xx.mean()) ** 2)
aEst = num / den
bEst = yy.mean() - aEst * xx.mean()
yEst = aEst * xx + bEst
ab = nelMeadInit(aEst,bEst)
yPerf = 4 * xx + 3
print('initial estimate',aEst,bEst)
print('obj',objective(xx,yy,aEst,bEst))
print('shifted estimate',aEst*0.9,bEst*0.8)
print('obj',objective(xx,yy,aEst*0.9,bEst*0.8))
print('undisturbed function',4,3)
print('obj',objective(xx,yy,4,3))
plt.plot(xx,yy,label="\'data\'")
plt.plot(xx,yFit,label="fit")
plt.plot(xx,yEst,label="initial guess",linestyle='dashed')
plt.legend()
plt.savefig("test.png")
