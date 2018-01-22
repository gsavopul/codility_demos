def solution(N, M):
	
	i=1

	while (True):
		if (N>M):
			x=i*N//M
			if i*N-x*M ==0:
				return x
			else:
				i+=1
		else:
			x=i*M//N
			if i*M-x*N ==0:
				return i
			else:
				i+=1
	return 0


