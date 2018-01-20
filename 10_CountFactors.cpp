# include <cmath>

int solution(int N)
{
	int a=sqrt(N);
	int count{};

	do
	{
		int x=N/a;
		if (x*a==N)
		{
			if (x==a)
				count++;
			else
				count+=2;
		}
		a--;
	} while (a>=1);
	return count;
}

