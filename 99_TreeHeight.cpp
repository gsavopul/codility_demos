int countNodes(tree *T)
{
	int count{1}, leftCount{}, rightCount{};

	if(T->l != nullptr) 
		leftCount += countNodes(T->l);

	if (T->r != nullptr)
		rightCount += countNodes(T->r);

	return count+std::max(rightCount,leftCount);
}



int solution(tree * T)
{
	int count{};

	if (T != nullptr)
		count = countNodes(T);
	else
		return -1;

	return count-1;
}

