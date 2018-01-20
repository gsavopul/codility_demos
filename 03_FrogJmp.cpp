int solution(int X, int Y, int D)
{
	int jumps = (Y-X)/D;

	if ((Y-X)%D != 0)
		jumps++;

	return jumps;
}
