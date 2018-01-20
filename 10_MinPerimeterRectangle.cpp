# include <cmath>

int solution(int N)
{
	int side1=sqrt(N);
	int side2{};
	int minimalPerimeter{};

	do
	{
		side2=N/side1;
		if (side1*side2==N)
		{
			minimalPerimeter = 2*(side1+side2);
			break;
		}
		side1--;
	} while (side1>0);

	return minimalPerimeter;
}

