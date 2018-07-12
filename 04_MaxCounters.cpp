# include <algorithm>
# include <unordered_set>

vector<int> solution(int N, vector<int> &A)
{
	vector<int> b(N,0);
	size_t local{}, mx{};
	size_t cnt=count(A.begin(),A.end(),N+1);

	if (cnt==0)
	{
		for (size_t i=0; i<A.size(); i++)
			b[A[i]-1]++;
		return b;
	}
	else if (cnt==A.size())
		return b;
	else
	{
		auto bg=find_if(A.begin(),A.end(),[N](int a){return a!=N+1;});
		auto nd=bg;

		while (nd!=A.end())
		{
			if (nd!=bg)
				bg=next(nd);
			nd=find_if(bg,A.end(),[N](int a){return a==N+1;});
			if (nd==A.end()) break;

			unordered_multiset<int> s(bg,nd);
			unordered_set<int> s2(bg,nd);
			local=0;

			if (s2.empty())
			{
				bg++;
				nd=bg;
			}
			else
			{
				for (int a:s2)
					if (s.count(a)>local) local=s.count(a);
				mx+=local;
			}
		}

		fill(b.begin(),b.end(),mx);
		for (size_t i=distance(A.begin(),bg); i!=A.size(); i++)
			b[A[i]-1]++;

		return b;
	}
}

