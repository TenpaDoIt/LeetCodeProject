#pragma once

#include <stdlib.h>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ZigZagConversion
{
public:
	string convert(string s, int numRows);
	string convert2(string s, int numRows);
	void Main();
	~ZigZagConversion() {};
};