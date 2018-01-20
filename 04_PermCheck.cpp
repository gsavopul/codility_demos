# include <numeric>
# include <algorithm>

int solution(vector<int> &A)
{
	if (A.size()==0)
		return 0;
	else
	{
		vector<int> B(A.size());
		iota(B.begin(),B.end(),1);
		sort(A.begin(),A.end());

		return is_permutation(A.begin(),A.end(),B.begin());
	}
}

