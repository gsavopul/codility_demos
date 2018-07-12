# include <numeric>

int solution(vector<int> &A)
{
	int sum1, sum2, differences{};

	for(size_t i=1; i < A.size() ;i++)
	{
		if (i==1)
		{
			sum1=A[0];
			sum2=accumulate(next(A.begin()),A.end(),0);
			differences=abs(sum2-sum1);
		}
		else
		{
			sum1+=A[i-1];
			sum2-=A[i-1];
			if (differences > abs(sum2-sum1))
				differences=abs(sum2-sum1);
		}
	}

	return differences;
}
