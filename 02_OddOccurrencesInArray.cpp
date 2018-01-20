# include <algorithm>

int solution(vector<int> &A)
{
	vector<int> C;
	sort(A.begin(),A.end());
	unique_copy(A.begin(),A.end(),back_inserter(C));

	for (const int & occurrences :C)
	{
		auto x=equal_range(A.begin(),A.end(),occurrences);
		if (distance(x.first,x.second)%2==1)
			return occurrences;
	}

	return -1;
}

