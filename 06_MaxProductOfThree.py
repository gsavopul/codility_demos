def solution(A):

	A.sort(reverse=True)

	p1=A[0]*A[1]*A[2];
	p2=A[0]*A[-2]*A[-1];

	if (p1>p2):
		return p1
	else:
		return p2
