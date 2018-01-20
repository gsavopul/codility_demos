# include <algorithm>

int solution(vector<int> &A)
{
	sort(A.begin(),A.end(),greater<int>());

	int p1=A[0]*A[1]*A[2];
	int p2=A[0]*A[A.size()-2]*A[A.size()-1];

	if (p1>p2)
		return p1;
	else
		return p2;
}
