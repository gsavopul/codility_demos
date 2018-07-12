# include <cmath>
# include <algorithm>

int solution(vector<int> &A)
{
	size_t numberOfPeaks{};
	vector<int> peaks, blockSizes;
	vector<pair<int,char>> peaksAndBounds;

	for(size_t i=1; i<A.size()-1; i++)
		if (A[i]>A[i+1] && A[i]>A[i-1])
			peaks.push_back(i);

	if (peaks.size() == 0) return 0;
	else if (peaks.size() ==1) return 1;

	for (size_t i=1; i<=sqrt(A.size()); i++)
	{
		if (A.size()%i==0)
		{
			if (i>=A.size()/peaks.size())
				blockSizes.push_back(i);
			blockSizes.push_back(A.size()/i);
		}
	}
	sort(blockSizes.begin(),blockSizes.end());

	for (int currentBlockSize : blockSizes)
	{
		for (size_t i=0; i<=A.size(); i+=currentBlockSize)
			peaksAndBounds.push_back(make_pair(i,'b'));

		for (size_t i=0; i<peaks.size(); i++)
			peaksAndBounds.push_back(make_pair(peaks[i],'p'));

		stable_sort(peaksAndBounds.begin(),peaksAndBounds.end(),[](pair<int,char> a, pair<int,char> b){return a.first<b.first;});

		auto it2=adjacent_find(peaksAndBounds.begin(),peaksAndBounds.end(),[](pair<int,char> a, pair<int,char> b){return a.second=='b' && b.second=='b';});
		if (it2==peaksAndBounds.end())
		{
			numberOfPeaks = A.size()/currentBlockSize;
			break;
		}
		else
			peaksAndBounds.clear();
	}

	return numberOfPeaks;
}

