int solution(int K, vector<int> &A)
{
	int numberOfRopes{}, sum{};

	for (size_t i=0; i<A.size(); i++)
	{
		sum+=A[i];
		if (sum>=K)
		{
			sum=0;
			numberOfRopes++;
		}
	}

	return numberOfRopes;
}
