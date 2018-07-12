# include <numeric>
# include <algorithm>

int solution(vector<int> &A)
{
	vector<int> B;
	int sum, currentSum{}, blockOfPossitives{}, blockOfNegatives{};
	size_t numberOfNegatives{};

	numberOfNegatives=count_if(A.begin(),A.end(),[](int a){return a<0;});

	if (numberOfNegatives==0)
		return accumulate(A.begin(),A.end(),0);
	else if (numberOfNegatives==A.size())
		return *max_element(A.begin(),A.end());

	for (size_t i=0; i<A.size(); i++)
	{
		if (A[i]<0)
		{
			if (blockOfPossitives != 0)
				B.push_back(blockOfPossitives);
			blockOfNegatives+=A[i];
			blockOfPossitives=0;
		}
		else
		{
			if (blockOfNegatives != 0)
				B.push_back(blockOfNegatives);
			blockOfPossitives+=A[i];
			blockOfNegatives=0;
		}
	}
	if (blockOfPossitives != 0)
		B.push_back(blockOfPossitives);
	if (blockOfNegatives != 0)
		B.push_back(blockOfNegatives);

	sum=*max_element(B.begin(),B.end());

	for (size_t i=0; i<B.size()-1; i++)
	{
		currentSum=B[i];
		if (currentSum>sum)
			sum=currentSum;
		for (size_t j=i+1; j<B.size(); j++)
		{
			currentSum+=B[j];
			if (currentSum>sum)
				sum=currentSum;
		}
	}

	return sum;
}

