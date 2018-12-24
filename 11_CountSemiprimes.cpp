# include <vector>
# include <algorithm>
# include <iterator>

vector<int> getVectorOfPrimes(int x)
{
	vector<int> primes;

	if (x>=2) primes.push_back(2);
	else return primes;

	for (int i=3; i<=x; i++)
	{
		bool primeFlag=true;
		for (auto k: primes)
			if (i%k ==0)
			{
				primeFlag=false;
				break;
			}

		if (primeFlag)	primes.push_back(i);
	}

	return primes;
}


vector<int> solution(int N, vector<int> &P, vector<int> &Q)
{
	vector<int> primes, productsOfPrimes, semiprimeCount;
	int product;

	primes=getVectorOfPrimes(N);


	for (size_t i=0; i<primes.size(); i++)
		for (size_t j=i; j<primes.size(); j++)
		{
			product=primes[i]*primes[j];
			if (product>N) break;
			else productsOfPrimes.push_back(product);
		}

	sort(productsOfPrimes.begin(),productsOfPrimes.end());

	for (size_t i=0; i<P.size(); i++)
	{
		int count{};
		int lowBound=P[i];
		int upperBound=Q[i];

		auto x=equal_range(productsOfPrimes.begin(),productsOfPrimes.end(),lowBound);
		auto y=equal_range(productsOfPrimes.begin(),productsOfPrimes.end(),upperBound);

		count=distance(x.first,y.second);

		semiprimeCount.push_back(count);
	}

	return semiprimeCount;
}

