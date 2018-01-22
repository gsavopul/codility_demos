def solution(K, A):

	numberOfRopes=0
	sm=0;

	for i in A:
		sm+=i
		if (sm>=K):
			sm=0
			numberOfRopes+=1

	return numberOfRopes
