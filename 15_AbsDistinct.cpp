# include <algorithm>

int solution(vector<int> &A)
{
	vector<int> B;
	unique_copy(A.begin(),A.end(),back_inserter(B));

	for(auto &i:B)
		if (i<0) i=-i;

	sort(B.begin(),B.end());
	auto pos=unique(B.begin(),B.end());

	return distance(B.begin(),pos);
}

