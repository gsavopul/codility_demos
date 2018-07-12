# include <algorithm>

int solution(vector<int> &A)
{
	auto x=minmax_element(A.begin(),A.end());
	if (x.second>x.first)
		return (*x.second) - (*x.first);

	int maxProfit{}, start{};
	for (size_t i=1; i<A.size(); i++)
	{
		if (A[i]>A[start])
		{
			if (maxProfit<A[i]-A[start])
				maxProfit=A[i]-A[start];
		}
		else
			start=i;
	}
	return maxProfit;
}

