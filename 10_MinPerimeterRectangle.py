import math

def solution(N):
	
	side1=int(math.sqrt(N))
	side2=0
	minimalPerimeter=0

	while(side1>0):
		side2=N//side1
		if (side1*side2==N):	
			minimalPerimeter = 2*(side1+side2)
			break
		side1-=1

	return minimalPerimeter

