# include <algorithm>

int solution(vector<int> &A)
{
	sort(A.begin(),A.end(),[](int a, int b){return abs(a)<abs(b);});

	int minimalSum={abs(2*A[0])}, currentSum{};

	for (size_t i=1; i<A.size(); i++)
	{
		currentSum=abs(A[i]+A[i-1]);
		if (currentSum<minimalSum)
			minimalSum=currentSum;
	}

	return minimalSum;
}

