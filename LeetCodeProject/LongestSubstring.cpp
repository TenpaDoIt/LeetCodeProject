
#include "stdafx.h"
#include "LongestSubstring.h"


int LongestSubstring::lengthOfLongestSubstring(string s) {
	map<char, int> maptable;
	int maxlength = 0, position = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if ((maptable[s[i]] != 0) || (s[i] == s[0]) && (i != 0))
			position = max(position, maptable[s[i]] + 1);
		maxlength = max(maxlength, i - position + 1);
		maptable[s[i]] = i;
	}
	return maxlength;

	/*int maxlength = 0;
	int RepeatCount = 0;
	for (int i = 0; i < s.length(); i++)
	{
	for (int j = i; j < s.length(); j++)
	{
	for (int k = i; k < j; k++)
	{
	//string MainS = s.substr(k, j -k);
	//string TestS = s.substr(k, 1);

	//cout << "Main String = " << MainS.c_str() << endl;
	//cout << "Test String = " << TestS.c_str() << endl;
	if (s.substr(k+1, j - k).find(s.substr(k, 1)) != string::npos)
	{
	RepeatCount = 2;
	//cout << "Find = " << s.substr(k + 1, j - k -1).find(s.substr(k, 1))<< endl << endl;
	}
	}
	if (RepeatCount < 2)
	{
	if (maxlength < s.substr(i, j - i+1).length())
	{
	maxlength = s.substr(i, j - i+1).length();
	//cout << "Max String = " << s.substr(i, j - i).c_str() << endl;
	}
	}
	RepeatCount = 0;
	}
	}*/

	return maxlength;
}

void LongestSubstring::Main() {
	string testA = "abcabcbb";
	string testB = "bbbbbb";
	string testC = "pwwkew";
	string testD = "aab";
	string testE = "dvdf";
	string testF = "au";
	string testG = "abba";
	string testH = "uqinntq";
	string testI = "vbxpvwkkteaiob";

	std::cout << lengthOfLongestSubstring(testA) << std::endl;
	std::cout << lengthOfLongestSubstring(testB) << std::endl;
	std::cout << lengthOfLongestSubstring(testC) << std::endl;
	std::cout << lengthOfLongestSubstring(testD) << std::endl;
	std::cout << lengthOfLongestSubstring(testE) << std::endl;
	std::cout << lengthOfLongestSubstring(testF) << std::endl;

	std::cout << lengthOfLongestSubstring(testG) << std::endl;
	std::cout << lengthOfLongestSubstring(testH) << std::endl;

	std::cout << lengthOfLongestSubstring(testI) << std::endl;
}