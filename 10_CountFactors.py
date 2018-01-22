import math

def solution(N):

	a=int(math.sqrt(N))
	count=0

	while (a>=1):
		x=N//a
		if (x*a==N):
			if (x==a):
				count+=1
			else:
				count+=2
		a-=1

	return count

