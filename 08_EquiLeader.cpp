# include <algorithm>

int solution(vector<int> &A)
{
	if (A.size()==1) return 0;

	size_t cnt{};
	int dominator{}, dominatorCount{};
	int leftSize{}, rightSize=A.size(), leftDominator{}, rightDominator{};
	vector<int> B(A),C,D;

	sort(B.begin(),B.end());
	vector<int>::iterator pos=B.begin();

	while (pos!=B.end())
	{
		pos=adjacent_find(pos,B.end(),[&C](int a, int b){if (a==b) {C.push_back(a);}; return a==b;});
		if (pos!= B.end())
			++pos;
	}
	unique(C.begin(),C.end());

	for(size_t i=0; i<C.size(); i++)
	{
		cnt=count(A.begin(),A.end(),C[i]);
		if (2*cnt>A.size())
		{
			dominator=C[i];
			break;
		}
	}

	rightDominator=cnt;
	for(size_t i=0; i<A.size()-1; i++)
	{
		leftSize++;
		rightSize--;
		if (A[i]==dominator)
		{
			leftDominator++;
			rightDominator--;
		}

		if ((2*leftDominator>leftSize) && (2*rightDominator>rightSize))
			dominatorCount++;
	}

	return dominatorCount;
}

