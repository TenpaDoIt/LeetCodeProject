/*
LeetCode 5 Questions :

*/
#include "stdafx.h"
#include "LongestPalindromicSubstring.h"


string LongestPalindromicSubstring::longestPalindrome(string s) 
{
	int sStart = 0, sEnd = 0, j, maxlength = 0, CheckNumber = 0;
	int EndPos = s.length() - 1;
	int i = 0;
	//for (int i = 0; i < EndPos; i++)
	while (i <= EndPos - maxlength+1)
	{
		j = EndPos;
		while ((j - i + 1) > maxlength)
		{
			if (s[j] == s[i])
			{
				bool bSame = true;
				CheckNumber = (j - i) / 2;
				for (int k = 0; k < CheckNumber; k++)
				{
					if (s[i + k] != s[j - k])
					{
						bSame = false;
					}
				}
				if (bSame)
				{
					sStart = i;
					sEnd = j;
					maxlength = sEnd - sStart + 1;
					break;
				}
			}
			j--;
		}
		if (i + maxlength - 1 > EndPos)
		{
			break;
		}
		i++;
	}
	return s.substr(sStart, sEnd - sStart+1);
}

string LongestPalindromicSubstring::longestPalindrome2(string s)
{
	int sStart = 0, sEnd = 0, j, maxlength = 0, pivot1, pivot2, distance;
	int EndPos = s.length() - 1;
	int i = 1;
	
	while (i <= EndPos - maxlength/2)
	{
		distance = 0;
		do
		{
			if (s[i+distance] == s[i-1-distance])
			{
				if (2 * (distance + 1) > maxlength)
				{
					sStart = i - 1 - distance;
					sEnd = i + distance;
					maxlength = sEnd - sStart + 1;
				}
				distance++;
			}
			else
			{
				break;
			}
		} while ((i - 1 - distance) >= 0 && (i + distance) <= EndPos);
		distance = 1;
		do
		{
			if (s[i - distance] == s[i + distance])
			{
				if (2 * distance + 1 > maxlength)
				{
					sStart = i - distance;
					sEnd = i + distance;
					maxlength = sEnd - sStart + 1;
				}
				distance++;
			}
			else
			{
				break;
			}
		} while ((i - distance) >= 0 && (i + distance) <= EndPos);
		i++;
	}
	return s.substr(sStart, sEnd - sStart + 1);
}

void LongestPalindromicSubstring::Main() {
	string testA = "babadada";

	std::cout << longestPalindrome2(testA).c_str() << std::endl;
}