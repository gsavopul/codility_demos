# include <unordered_set>
# include <unordered_map>
# include <algorithm>

int solution(int M, vector<int> &A)
{
	int numberOfSlices{};
	int numberOfUniqueElements{};
	int restartIndex{};

	vector<int> B(A);
	sort(B.begin(),B.end());

	vector<int> C(B), D;
	C.erase(unique(C.begin(),C.end()),C.end());
	set_difference(B.begin(),B.end(),C.begin(),C.end(),back_inserter(D));
	D.erase(unique(D.begin(),D.end()),D.end());

	unordered_set<int> setOfMultiples(D.begin(),D.end());
	unordered_map<int,int> lastSeenPosition;
	for (size_t i=0; i<D.size(); i++)
		lastSeenPosition[D[i]]=-1;

	for (size_t i=0; i<A.size(); i++)
	{
		if (i==0)
		{
			numberOfUniqueElements++;
			numberOfSlices += numberOfUniqueElements;
			if (setOfMultiples.find(A[i]) != setOfMultiples.end())
				lastSeenPosition[A[i]]=0;
		}
		else
		{
			if (setOfMultiples.find(A[i]) == setOfMultiples.end())
			{
				numberOfUniqueElements++;
				numberOfSlices+=numberOfUniqueElements;
			}
			else
			{
				if (lastSeenPosition[A[i]]==-1)
				{
					numberOfUniqueElements++;
					numberOfSlices+=numberOfUniqueElements;
					lastSeenPosition[A[i]]=i;
				}
				else
				{
					if ( lastSeenPosition[A[i]] + 1 >  restartIndex )
						restartIndex=lastSeenPosition[A[i]]+1;

					numberOfUniqueElements=i-restartIndex+1;
					numberOfSlices+=numberOfUniqueElements;
					lastSeenPosition[A[i]]=i;
				}
			}
		}

		if (numberOfSlices >= 1E9)
			return 1000000000;
	}

	return numberOfSlices;
}

