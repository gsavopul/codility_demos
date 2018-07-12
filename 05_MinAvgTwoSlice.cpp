int solution(vector<int> &A)
{
	int startPosition{0}, endPosition{1};
	int currentNumberOfElements{2};
	int currentSum = A[0]+A[1];
	int slicePosition{0};

	double currentAverage = static_cast<double>(currentSum) / currentNumberOfElements;
	double average{currentAverage};

	bool cascade{true};

	for (size_t i=2; i<A.size(); )
	{
		if (currentSum > currentNumberOfElements*A[i])
		{
			endPosition++;
			currentNumberOfElements++;
			currentSum+=A[i];
			currentAverage = static_cast<double>(currentSum) / currentNumberOfElements;

			if (average>currentAverage)
			{
				average=currentAverage;
				slicePosition=startPosition;
			}

			i++;
		}
		else if (endPosition-startPosition!=1)
		{
			startPosition++;
			currentNumberOfElements--;
			currentSum-=A[startPosition-1];
			currentAverage = static_cast<double>(currentSum) / currentNumberOfElements;

			if (average>currentAverage)
			{
				average=currentAverage;
				slicePosition=startPosition;
			}
			cascade=false;
		}
		else
		{
			startPosition++;
			endPosition++;
			currentNumberOfElements=2;
			currentSum = A[startPosition] + A[endPosition];
			currentAverage = static_cast<double>(currentSum) / currentNumberOfElements;

			if (average>currentAverage)
			{
				average=currentAverage;
				slicePosition=startPosition;
			}
			i++;
		}

		if (i==A.size() && cascade && startPosition<static_cast<int>(A.size()-2))
		{
			startPosition++;
			endPosition=startPosition+1;
			i=endPosition+1;

			currentNumberOfElements=2;
			currentSum = A[startPosition] + A[endPosition];
			currentAverage = static_cast<double>(currentSum) / currentNumberOfElements;

			if (average>currentAverage)
			{
				average=currentAverage;
				slicePosition=startPosition;
			}
			cascade=true;
		}

		continue;
	}

	return slicePosition;
}

