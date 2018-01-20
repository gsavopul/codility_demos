# include <stack>

int solution(vector<int> &H)
{
	int bricks{}, fall{}, dH{};
	stack<int> levels;

	levels.push(H[0]);

	for (size_t i=0; i<H.size()-1; i++)
	{
		dH=H[i+1]-H[i];
		if (dH>0)
			levels.push(dH);

		if (dH<0)
		{
			if (-dH<levels.top())
			{
				bricks++;
				fall=levels.top()+dH;
				levels.pop();
				levels.push(fall);
			}
			else if (-dH==levels.top())
			{
				bricks++;
				levels.pop();
			}
			else
			{
				while(-dH>levels.top())
				{
					bricks++;
					dH=levels.top()+dH;
					levels.pop();
				}
				fall=levels.top()+dH;
				bricks++;
				levels.pop();
				if (fall!=0) levels.push(fall);
			}
		}
	}
	return bricks+levels.size();
}
