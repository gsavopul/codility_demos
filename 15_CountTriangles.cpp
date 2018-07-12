# include <unordered_set>
# include <algorithm>

int solution(vector<int> &A)
{
	int cnt{};

	sort(A.begin(),A.end());

	if (A.size() < 3)
		return 0;

	while (A[A.size()-1]-A[A.size()-2]>A[A.size()-3])
		A.pop_back();

	unordered_set<int> B(A.begin(),A.end());
	if (B.size()==1)
		return (A.size()*(A.size()-1)*(A.size()-2)/6);

	for (auto it1=A.begin(); it1 != prev(prev(A.end())) ; ++it1)
		for (auto it2=next(it1); it2 != prev(A.end()); ++it2)
		{
			auto lowIterator = lower_bound(next(it2),A.end(),abs(*it1 - *it2 + 1));
			auto highIterator = upper_bound(next(it2),A.end(),*it1 + *it2 - 1);
			cnt += distance(lowIterator,highIterator);
		}

	return cnt;
}

