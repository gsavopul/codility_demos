# include <string>
# include <bitset>
# include <algorithm>

int solution(int N)
{
	string::size_type idx1, idx2;
	int longestStreakOfZeroes{};
	string representNumber, numberString;

	representNumber = bitset<64>(N).to_string();

	idx1=representNumber.find_first_of("1");
	idx2=representNumber.find_last_of("1");

	if (idx1!=string::npos && idx2!=string::npos && idx1!=idx2)
		numberString=representNumber.substr(idx1,idx2-idx1+1);
	else
		return 0;

	longestStreakOfZeroes = numberString.size()-2;
	while (longestStreakOfZeroes > 0)
	{
		auto thisToken=search_n(numberString.begin(), numberString.end(), longestStreakOfZeroes, '0');
		if (thisToken != numberString.end())
		{
			return longestStreakOfZeroes;
		}
		else
			longestStreakOfZeroes--;
	}

	return 0;
}

