#pragma once

#include <stdlib.h>
#include <iterator>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class LongestPalindromicSubstring
{
public:
	string longestPalindrome(string s);
	string longestPalindrome2(string s);
	void Main();
	~LongestPalindromicSubstring() {};
};