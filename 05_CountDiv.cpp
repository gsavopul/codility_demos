int solution(int A, int B, int K)
{
	if (K==0)
		return 0;
	else if (K==1)
		return (B-A+1);
	else
	{
		int first, last;
		if (A%K==0)
			first=A;
		else
			first=A+K-A%K;

		if (B%K ==0)
			last=B;
		else
			last=B-B%K;

		int count = 1 + (last-first)/K;
		return count;
	}
}

