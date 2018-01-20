# include <stack>

int solution(string &S)
{
	stack<char> a;
	for (size_t i=0; i<S.size(); i++)
	{
		if (S[i]=='(')
			a.push(S[i]);
		else
		{
			if (a.size()==0) return 0;
			else a.pop();
		}
	}

	if (a.size()==0)
		return 1;
	else
		return 0;
}

