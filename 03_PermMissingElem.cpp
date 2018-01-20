# include <algorithm>

int solution(vector<int> &A)
{
	if (A.size()==0)
		return 1;
	else if (A.size()==1)
	{
		if (A[0]==1) return 2;
		else return 1;
	}
	else
	{
		sort(A.begin(),A.end());
		if (A[0]!=1) return 1;

		auto b = adjacent_find(A.begin(),A.end(),[](int a, int b){return b>a+1;});
		if (b==A.end())
			return A.size()+1;
		else
			return *b+1;
	}
}

