# include <algorithm>
# include <map>

int solution(int X, vector<int> &A)
{
	if (A.size() == 0)
		return 0;
	else if (A.size()==1)
	{
		if (A[0]==1)
			return 0;
		else
			return -1;
	}
	else
	{
		map<int,int> B;
		for (size_t i=0; i<A.size(); i++)
			B.insert(pair<const int,int>(A[i],i));

		if (static_cast<int>(B.size()) != X)
			return -1;
		else
			return max_element(B.begin(),B.end(),[](pair<const int, int> p1, pair<const int, int> p2){return p1.second<p2.second;})->second;
	}
}

