int solution(string &S)
{
	bool valid=true;
	int maxNumberOfCharacters{-1}, numberOfCharacters{0}, numberOfLetters{0}, numberOfDigits{0};

	for (size_t j=0 ; j<S.size(); j++)
	{
		if (S[j]==' ')
		{
			if (numberOfCharacters>maxNumberOfCharacters && valid && numberOfLetters%2==0  && numberOfDigits%2==1)
				maxNumberOfCharacters=numberOfCharacters;
			numberOfCharacters=0;
			valid=true;
			numberOfLetters=0;
			numberOfCharacters=0;
			numberOfDigits=0;
		}
		else
		{
			if (!isalnum(S[j]))
				valid=false;

			numberOfCharacters++;
			if (isdigit(S[j]))
				numberOfDigits++;
			if (isalpha(S[j]))
				numberOfLetters++;
		}
	}

	if (numberOfCharacters>maxNumberOfCharacters && valid && numberOfLetters%2==0  && numberOfDigits%2==1)
		maxNumberOfCharacters=numberOfCharacters;

	return maxNumberOfCharacters;
}

