#include "stdafx.h"
#include "ReverseInteger.h"

int ReverseInteger::reverse(int x)
{
	bool bSign;
	int ReverseValue = 0, PositiveValue = abs(x), MultiTen = 10;
	if (x < 0)
		bSign = false;
	else
		bSign = true;
	do
	{
		if (ReverseValue > INT_MAX / 10)
			return 0;
		ReverseValue = ReverseValue*MultiTen + PositiveValue % MultiTen;
		PositiveValue = PositiveValue / 10;
	} while (PositiveValue > 0);
	if (ReverseValue < 0)
		return 0;
	if (!bSign)
		ReverseValue *= -1;
	return ReverseValue;
}

void ReverseInteger::Main()
{
	int testA = 1534236469;

	std::cout << reverse(testA) << std::endl;
}