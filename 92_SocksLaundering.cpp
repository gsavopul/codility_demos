# include <unordered_set>
# include <algorithm>

int solution(int K, vector<int> &C, vector<int> &D)
{
	int numberOfPairs{}, cnt{}, pairedCD{}, pairedY{};
	vector<int> remainingClean, remainingDirty;

	for ( auto s: unordered_set<int>(C.begin(), C.end()) )
	{
		cnt=count(C.begin(),C.end(),s);
		numberOfPairs+=cnt/2;
		if (cnt%2 != 0) remainingClean.push_back(s);
	}

	for (auto s: unordered_set<int>(remainingClean.begin(),remainingClean.end()) )
		if (find(D.begin(),D.end(),s) != D.end()) pairedCD++;

	if (pairedCD>=K)
		return K+numberOfPairs;
	else
	{
		numberOfPairs+=pairedCD;
		K-=pairedCD;
	}

	sort(D.begin(),D.end());
	sort(remainingClean.begin(),remainingClean.end());
	set_difference(D.begin(),D.end(),remainingClean.begin(),remainingClean.end(),back_inserter(remainingDirty));

	for (auto s: unordered_set<int>(remainingDirty.begin(),remainingDirty.end()) )
	{
		cnt=count(remainingDirty.begin(),remainingDirty.end(),s);
		pairedY+=cnt/2;
	}

	return numberOfPairs + min(K/2,pairedY);
}

