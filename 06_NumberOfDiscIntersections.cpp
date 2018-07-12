# include <algorithm>

int solution(vector<int> &A)
{
	int cnt{}, cnt_left{}, cnt_right{};

	if (A.size() < 2) return 0;

	vector<long> B, C;
	for (size_t i=0; i<A.size(); i++)
	{
		B.push_back(i-A[i]);
		C.push_back(i+A[i]);
	}

	vector<pair<long,string>> D(2*A.size());

	for (size_t i=0;i<B.size(); i++)
		D[i]=make_pair(B[i],"left");

	for (size_t i=0;i<C.size(); i++)
		D[A.size()+i] = make_pair(C[i],"right");

	stable_sort(D.begin(),D.end(),[](pair<long,string> a, pair<long,string> b){return a.first<b.first;});

	for (size_t i=0;i<D.size()-1; i++)
	{
		if (D[i].second == "left")
			cnt_left++;
		else
		{
			cnt+=cnt_left-1-cnt_right;
			cnt_right++;
			if (cnt>10000000)
				return -1;
		}
	}

	return cnt;
}

