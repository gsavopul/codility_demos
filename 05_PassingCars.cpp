int solution(vector<int> &A)
{
	int total=0;
	vector<int> b;

	for (size_t i=0; i<A.size(); i++)
		if (A[i]==0) b.push_back(i);

	for (size_t j=0; j<b.size(); j++)
		total+=(A.size()-b[j]-1)-(b.size()-j-1);

	if (total<0 || total>1000000000)
		return -1;
	else
		return total;
}

