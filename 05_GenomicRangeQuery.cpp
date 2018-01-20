# include <algorithm>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
	vector<int> ans,A,C,G,T;

	for (size_t i=0; i<S.size(); i++)
	{
		if (S[i]=='A')	A.push_back(i);
		if (S[i]=='C')	C.push_back(i);
		if (S[i]=='G')	G.push_back(i);
		if (S[i]=='T')	T.push_back(i);
	}

	for (size_t i=0; i<P.size(); i++)
	{
		int p=P[i];
		int q=Q[i];
		if (any_of(A.begin(),A.end(),[p,q](int a){return p<=a && a<q+1;}))
			ans.push_back(1);
		else if (any_of(C.begin(),C.end(),[p,q](int a){return p<=a && a<q+1;}))
			ans.push_back(2);
		else if (any_of(G.begin(),G.end(),[p,q](int a){return p<=a && a<q+1;}))
			ans.push_back(3);
		else if (any_of(T.begin(),T.end(),[p,q](int a){return p<=a && a<q+1;}))
			ans.push_back(4);
	}
	return ans;
}

