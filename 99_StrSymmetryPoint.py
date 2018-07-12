def solution(S):
	if (len(S)%2==0):
		return -1
	elif (len(S)==1):
		return 0
	else:
		S2=S[-1:-len(S)-1:-1]
		if (S == S2):
			return len(S)//2 
		else:
			return -1

