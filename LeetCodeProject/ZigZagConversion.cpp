#include "stdafx.h"
#include "ZigZagConversion.h"


string ZigZagConversion::convert(string s, int numRows) 
{
	string converS;
	if (numRows <= 1 || s.empty())
	{
		return s;
	}
	else
	{
		int baselen = numRows * 2 - 2;
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < s.length(); j++)
			{
				if ((j % baselen == i) || (j % baselen == (baselen - i)))
				{
					converS.push_back(s[j]);
				}
			}
		}
	}
	return converS;
}

void ZigZagConversion::Main()
{
	string testA = "";

	std::cout << convert(testA, 3).c_str() << std::endl;
}