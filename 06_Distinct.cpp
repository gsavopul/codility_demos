# include <algorithm>

int solution(vector<int> &A)
{
	sort(A.begin(),A.end());
	auto x=unique(A.begin(),A.end());

	return x-A.begin();
}
