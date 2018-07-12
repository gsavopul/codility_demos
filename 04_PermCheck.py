# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    pass

    if not A:
        return 0
    else:
        B=[i for i in range(1,len(A)+1)]
        C=sorted(A)
        if C != B:
            return 0
        else:
            return 1

