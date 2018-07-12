# include <algorithm>

int solution(vector<int> &A, vector<int> &B, vector<int> &C)
{
	vector<pair<int,int>> D;
	for (size_t i=0; i<C.size(); i++)
		D.push_back(make_pair(C[i],i));

	stable_sort(D.begin(),D.end(),[](pair<int,int> a, pair<int,int> b){return a.first<b.first;});
	D.erase( unique(D.begin(),D.end(),[](pair<int,int> a, pair<int,int> b){return a.first==b.first;}), D.end() );

	vector<int> E;
	for (auto x: D)
		E.push_back(x.second);

	sort(E.begin(),E.end());

	vector<int> F;
	D.clear();
	for (size_t i=0; i<A.size(); i++)
		if (A[i]!=B[i])
			D.push_back(make_pair(A[i],B[i]));
		else
			F.push_back(A[i]);

	sort(D.begin(),D.end(),[](pair<int,int> a, pair<int,int> b){return a.first<b.first;});
	D.erase( unique(D.begin(),D.end(),[](pair<int,int> a, pair<int,int> b){return a.first==b.first && a.second==b.second;}), D.end() );

	sort(F.begin(),F.end());
	F.erase( unique(F.begin(),F.end()), F.end());

	for (auto x:E)
	{
		auto val=C[x];
		if ( !F.empty() && binary_search(F.begin(),F.end(),val) )
			F.erase(lower_bound(F.begin(),F.end(),val));

		if (!D.empty())
			D.erase( partition(D.begin(),D.end(),[val](pair<int,int> a){return !(a.first<=val && val<=a.second);}), D.end());

		if (F.empty() && D.empty()) return x+1;
	}

	return -1;
}

