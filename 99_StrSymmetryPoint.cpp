# include <algorithm>

int solution(string &S)
{
	if (S.length()%2==0)
		return -1;
	else if (S.length()==1)
		return 0;
	else
	{
		string s2=S;
		reverse(s2.begin(),s2.end());
		if (s2==S)
			return s2.length()/2;
		else
			return -1;
	}
}
