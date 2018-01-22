def solution(A, B, K):

	if (K==0):
		return 0
	elif (K==1):
		return (B-A+1)
	else:
		if (A%K==0):
			first=A
		else:
			first=A+K-A%K

		if (B%K ==0):
			last=B
		else:
			last=B-B%K

		count = 1 + (last-first)//K;
		return count

