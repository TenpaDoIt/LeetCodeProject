#include "stdafx.h"
#include "IntegertoRoman.h"


string IntegertoRoman::intToRoman(int num)
{
	int ReverseValue, Digit[4] = { 0 }, i = 0;
	string RomanN;
	int position = 0;
	do
	{
		Digit[i] = Digit[i] + num % 10;
		num /= 10;
		i++;
	} while (num != 0);
	for (int j = i - 1; j >= 0; j--)
	{
		if (j == 3)
		{
			for (int k = 0; k < Digit[j]; k++)
			{
				RomanN.push_back('M');
				position++;
			}
		}
		else if (j == 2)
		{
			if (Digit[j] >= 4)
			{
				RomanN.push_back('D');
				if (Digit[j] > 5)
					Digit[j] -= 5;
				position++;
			}
			if (Digit[j] == 4)
			{
				RomanN.insert(position-1, "C");
				position++;
			}
			else
			{
				for (int k = 0; k < Digit[j]; k++)
				{
					RomanN.push_back('C');
					position++;
				}
			}
		}
		else if (j == 1)
		{
			if (Digit[j] >= 4)
			{
				RomanN.push_back('L');
				if (Digit[j] > 5)
					Digit[j] -= 5;
				position++;
			}
			if (Digit[j] == 4)
			{
				RomanN.insert(position-1, "X");
				position++;
			}
			else
			{
				for (int k = 0; k < Digit[j]; k++)
				{
					RomanN.push_back('X');
					position++;
				}
			}
		}
		else
		{
			if (Digit[j] >= 4)
			{
				RomanN.push_back('V');
				if (Digit[j] > 5)
					Digit[j] -= 5;
				position++;
			}
			if (Digit[j] == 4)
			{
				RomanN.insert(position-1, "I");
				position++;
			}
			else
			{
				for (int k = 0; k < Digit[j]; k++)
				{
					RomanN.push_back('I');
					position++;
				}
			}
		}
	}
	return RomanN;
}

void IntegertoRoman::Main()
{
	int testA = 4;

	std::cout << intToRoman(testA) << std::endl;
}