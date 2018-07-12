# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    pass
    total=0
    b=[]

    for i in range(len(A)):
	    if (A[i]==0):
		    b.append(i);

    for j in range(len(b)):
	    total+=(len(A)-b[j]-1)-(len(b)-j-1);

    if (total<0 or total>1000000000):
	    return -1
    else:
	    return total

