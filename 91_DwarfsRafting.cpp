# include <sstream>
# include <vector>

int solution(int N, string &S, string &T)
{
	vector<string> a;
	vector<int> available(4,N*N/4), occupied(4,0);

	int numberOfDwarfs{}, numberOfPairs{}, difference{};
	int row{}, col{};
	int separator=N/2;

	istringstream si(S);
	string x;
	do
	{
		si>>x;
		if (!x.empty())
		{
			col=x[x.size()-1]-'A'+1;
			row=stoi(x);

			if (row<=separator && col<=separator)
				--available[0];
			if (row<=separator && col>separator)
				--available[1];
			if (row>separator && col<=separator)
				--available[2];
			if (row>separator && col>separator)
				--available[3];
		}
	} while(si.good());

	x.clear();
	si.str(T);
	si.clear();
	do
	{
		si>>x;
		if (!x.empty())
		{
			col=x[x.size()-1]-'A'+1;
			row=stoi(x);

			if (row<=separator && col<=separator)
			{
				--available[0];
				++occupied[0];
			}
			if (row<=separator && col>separator)
			{
				--available[1];
				++occupied[1];
			}
			if (row>separator && col<=separator)
			{
				--available[2];
				++occupied[2];
			}
			if (row>separator && col>separator)
			{
				--available[3];
				++occupied[3];
			}
		}
	} while(si.good());

	if (occupied[0]-occupied[3]>0)
	{
		difference=occupied[0]-occupied[3];
		if (difference>available[3])
			return -1;
		else
		{
			available[3]-=difference;
			numberOfDwarfs+=difference;
		}
	}
	else if (occupied[3]-occupied[0]>0)
	{
		difference=occupied[3]-occupied[0];
		if (difference>available[0])
			return -1;
		else
		{
			available[0]-=difference;
			numberOfDwarfs+=difference;
		}
	}

	if (occupied[1]-occupied[2]>0)
	{
		difference=occupied[1]-occupied[2];
		if (difference>available[2])
			return -1;
		else
		{
			available[2]-=difference;
			numberOfDwarfs+=difference;
		}
	}
	else if (occupied[2]-occupied[1]>0)
	{
		difference=occupied[2]-occupied[1];
		if (difference>available[1])
			return -1;
		else
		{
			available[1]-=difference;
			numberOfDwarfs+=difference;
		}
	}

	numberOfPairs = min(available[0],available[3]) + min(available[1],available[2]);
	numberOfDwarfs+=2*numberOfPairs;

	return numberOfDwarfs;
}

