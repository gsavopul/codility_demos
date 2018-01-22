def solution(X,Y,D):
	jumps = (Y-X)//D

	if ((Y-X)%D != 0):
		jumps+=1
		
	return jumps

