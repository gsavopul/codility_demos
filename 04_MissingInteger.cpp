# include <algorithm>

int solution(vector<int> &A)
{
	if (A.size() == 0)
		return 0;
	else if (A.size()==1)
	{
		if (A[0]==1) return 2;
		else return 1;
	}
	else
	{
		vector<int> C;
		sort(A.begin(),A.end());
		auto pos=find_if(A.begin(),A.end(),[](int a){return a>0;});

		if (pos !=A.end())
			unique_copy(pos,A.end(),inserter(C,C.begin()));
		else
			return 1;

		if (C[0]!=1) return 1;
		auto p=adjacent_find(C.begin(),C.end(),[](int a, int b){return b>a+1;});

		if (p!=C.end())
			return *p+1;
		else
			return C.size()+1;
	}
}

