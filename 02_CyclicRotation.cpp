# include <algorithm>

vector<int> solution(vector<int> &A, int K)
{
	if (A.size() == 0)
		return A;

	vector<int> rotatedMatrix(A);

	if (K>0)
	{
		if (K >= static_cast<int>(A.size()))
			K=K%A.size();
		rotate(rotatedMatrix.rbegin(), rotatedMatrix.rbegin()+K, rotatedMatrix.rend());
	}
	else
	{
		K=-K;
		if (K >= static_cast<int>(A.size()))
			K=K%A.size();
		rotate(rotatedMatrix.begin(), rotatedMatrix.begin()+K, rotatedMatrix.end());
	}

	return rotatedMatrix;
}
