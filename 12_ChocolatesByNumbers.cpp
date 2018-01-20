# include <cmath>

int solution(int N, int M)
{
	long int i{1};

	while (1)
	{
		if (N>M)
			if (fmod(i*N,M)==0)
				return i*N/M;
			else
				i++;
		else
			if (fmod(i*M,N)==0)
				return i;
			else
				i++;
	}
	return 0;
}

