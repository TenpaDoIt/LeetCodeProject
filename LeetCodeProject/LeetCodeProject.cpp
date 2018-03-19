// LeetCodeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AddTwoNumbers.h"
#include "LongestSubstring.h"
#include "MedianofTwoSortedArrays.h"
#include "LongestPalindromicSubstring.h"
#include "ZigZagConversion.h"
#include "ReverseInteger.h"
#include "IntegertoRoman.h"
#include "LRUCache.h"

int main()
{
	AddTwoNumbers AddTwoNumbers;
	LongestSubstring LongestSubstring;
	MedianTwoSortedArrays MedianTwoSortedArrays;
	LongestPalindromicSubstring LongestPalindromicSubstring;
	ZigZagConversion ZigZagConversion;
	ReverseInteger ReverseInteger;
	IntegertoRoman IntegertoRoman;
	LRUCache obj(1);
	
	int MaxLength = 0;
	bool TestCaseNow = false;

	if (TestCaseNow)
	{
		// Case I : Add Two Numbers
		AddTwoNumbers.Main();
		AddTwoNumbers.~AddTwoNumbers();
		// Case II : Longest Substring
		LongestSubstring.Main();
		LongestSubstring.~LongestSubstring();
		// Case III : 
		MedianTwoSortedArrays.Main();
		MedianTwoSortedArrays.~MedianTwoSortedArrays();
		// Case IV :
		LongestPalindromicSubstring.Main();
		LongestPalindromicSubstring.~LongestPalindromicSubstring();
		// Case V :
		ZigZagConversion.Main();
		ZigZagConversion.~ZigZagConversion();
		// Case VI;
		ReverseInteger.Main();
		ReverseInteger.~ReverseInteger();
		// Case VII:
		IntegertoRoman.Main();
		IntegertoRoman.~IntegertoRoman();
	}

	obj.put2(2, 1);
	//obj.put2(2, 2);
	cout << obj.get2(2) << endl;
	obj.put2(3, 2);
	//obj.put2(4, 1);
	cout << obj.get2(2) << endl;
	cout << obj.get2(3) << endl;



	/*obj.put2(1, 1);
	obj.put2(2, 2);
	cout << obj.get2(1) << endl;
	obj.put2(3, 3);
	//obj.put2(4, 1);
	cout << obj.get2(2) << endl;
	obj.put2(4, 4);
	//obj.put2(1, 2);
	cout << obj.get2(1) << endl;
	cout << obj.get2(3) << endl;
	cout << obj.get2(4) << endl;*/

	/*cout << obj.get2(2) << endl;
	obj.put2(2, 6);
	cout << obj.get2(1) << endl;
	obj.put2(1, 5);
	obj.put2(1, 2);
	cout << obj.get2(1) << endl;
	cout << obj.get2(2) << endl;*/

	/*obj.put2(1, 1);
	obj.put2(2, 2);
	obj.put2(3, 3);
	obj.put2(4, 4);
	cout << obj.get2(4) << endl;
	cout << obj.get2(3) << endl;
	cout << obj.get2(2) << endl;
	cout << obj.get2(1) << endl;
	obj.put2(5, 5);
	cout << obj.get2(1) << endl;
	cout << obj.get2(2) << endl;
	cout << obj.get2(3) << endl;
	cout << obj.get2(4) << endl;
	cout << obj.get2(5) << endl;*/

	system("PAUSE");
    return 0;
}

