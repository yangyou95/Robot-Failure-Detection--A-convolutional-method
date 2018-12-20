import numpy as np

def nonlin(x , deriv = False):
    if(deriv == True):
        return x*(1-x)
    return 1/(1+np.exp(-x))

#input data
X = np.array([[0,0,1],
              [0,1,1],
              [1,0,1],
              [1,1,1],
              ])
# test data
X_t = np.array([[0,1,1],
              [1,0,0],
              [1,1,1],
              [0,0,1]])
#output label
y = np.array([[0,1,0,1]]).T
#random
np.random.seed(1)
#weights
# w = 2*np.random.random((3,1)) - 1
#add a hidden layer and 2 full-connections
w1 =  2*np.random.random((3,2)) - 1
w2 =  2*np.random.random((2,1)) - 1

for i in range(1000):
    l0 = X
    l1 = nonlin(np.dot(l0,w1))
    l2 = nonlin(np.dot(l1,w2))
    l2_error = y - l2
    l2_delta = l2_error*nonlin(l2,True)

    l1_error = l2_delta.dot(w2.T)
    l1_delta = l1_error*nonlin(l1,True)

    #update w
    w1 += np.dot(l0.T,l1_delta)
    w2 += np.dot(l1.T,l2_delta)


test_l1 = nonlin(np.dot(X_t,w1))

test_l2 = nonlin(np.dot(test_l1,w2))
print(test_l2)