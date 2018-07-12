# include <stack>

int solution(vector<int> &A, vector<int> &B)
{
	stack<int> upstream, downstream;

	for(size_t i=0; i<A.size(); i++)
	{
		if (B[i]==1)
			downstream.push(i);
		else
		{
			if (downstream.size()==0)
				upstream.push(i);
			else
			{
				if (A[i]<A[downstream.top()])
					continue;
				else
				{
					while(A[i]>A[downstream.top()])
					{
						downstream.pop();
						if (downstream.size()==0) break;
					}
					if (downstream.size() ==0)
						upstream.push(i);
				}
			}
		}
	}

	return upstream.size() + downstream.size();
}

