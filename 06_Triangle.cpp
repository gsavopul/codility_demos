# include <algorithm>

int solution(vector<int> &A)
{
	vector<int> B;

	copy_if(A.begin(),A.end(),back_inserter(B),[](int a){return a>0;});
	sort(B.begin(),B.end());

	if (B.size() < 3)
		return 0;

	for (size_t i=0; i<B.size()-2; i++)
		for (size_t j=i+1; j<B.size()-1; j++)
			for (size_t k=j+1; k<B.size(); k++)
			{
				if (B[i]<B[k]-B[j]) break;
				else if ( (B[i]>B[k]-B[j]) && (B[j]>B[k]-B[i]) && (B[k]>B[j]-B[i]) )
					return 1;
			}

	return 0;
}

