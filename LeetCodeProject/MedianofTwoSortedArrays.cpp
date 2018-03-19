/*
LeetCode 4 Questions :

*/

#include "stdafx.h"
#include "MedianofTwoSortedArrays.h"

float MedianTwoSortedArrays::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	float totalNum = nums1.size() + nums2.size();
	int target = ceil(totalNum / 2);
	int GetTarget1 = -1, GetTarget2 = -1;
	float Low1 = 0, Hi1 = nums1.size() - 1, Low2 = 0, Hi2 = nums2.size() - 1;
	int CurrentPos1 = 0, CurrentPos2 = 0;
	int countNum;
	int Answer = -1;
	int prePos1 = -1, prePos2 = -1;
	if (nums1.empty() || nums2.empty())
	{
		if (nums1.empty())
		{
			if ((int)totalNum % 2 == 1)
			{
				return nums2[target - 1];
			}
			return float(nums2[target - 1] + nums2[target]) / 2;
		}
		else
		{
			if ((int)totalNum % 2 == 1)
			{
				return nums1[target - 1];
			}
			return float(nums1[target - 1] + nums1[target]) / 2;
		}
	}

	do
	{
		do
		{
			if (CurrentPos2 < nums2.size() - 1)
			{
				if (nums1[CurrentPos1] >= nums2[CurrentPos2])
				{ 
					if (nums1[CurrentPos1] < nums2[CurrentPos2 + 1])
					{
						countNum = CurrentPos1 + CurrentPos2 + 2;
						if (countNum == target)
						{
							GetTarget1 = nums1[CurrentPos1];
							if (CurrentPos1 < nums1.size() - 1)
							{
								if (nums1[CurrentPos1 + 1] <= nums2[CurrentPos2 + 1])
								{
									GetTarget2 = nums1[CurrentPos1 + 1];
								}
								else
								{
									GetTarget2 = nums2[CurrentPos2 + 1];
								}
							}
						}
						else if (countNum > target)
						{
							GetTarget1 = nums2[target - CurrentPos1 - 1];
							GetTarget2 = nums1[CurrentPos1];
							Hi1 = CurrentPos1;
						}
						else
						{
							Low2 = CurrentPos2;
						}
					}
					else
					{
						countNum = CurrentPos1 + CurrentPos2 + 2;
						if (countNum == target)
						{
							GetTarget1 = nums1[CurrentPos1];
							GetTarget2 = nums2[CurrentPos2 + 1];
						}
						
					}
				}
				else 
				{
					if (CurrentPos1 == nums1.size() - 1 && CurrentPos2 == 0)
					{
						countNum = CurrentPos1 + 1;
						if (countNum == target)
						{
							GetTarget1 = nums1[CurrentPos1];
							GetTarget2 = nums2[CurrentPos2];
						
						}
						else if (countNum > target)
						{
							GetTarget1 = nums2[target - CurrentPos1 - 1];
							GetTarget2 = nums1[CurrentPos1];
							Hi1 = CurrentPos1;
						}
						else
						{
							Low2 = CurrentPos2;
						}
					}
					Low1 = CurrentPos1;
				}
				prePos2 = CurrentPos2;
			}
			else
			{
				if (nums1[CurrentPos1] >= nums2[CurrentPos2])
				{
					countNum = CurrentPos1 + CurrentPos2 + 2;
					if (countNum == target)
					{
						GetTarget1 = nums1[CurrentPos1];
						GetTarget2 = nums1[CurrentPos1 + 1];
					}
					else if (countNum > target)
					{
						GetTarget1 = nums2[target - CurrentPos1 - 1];
						if (target - CurrentPos1 <= nums2.size() - 1)
						{
							GetTarget2 = nums2[target - CurrentPos1];
						}
						else
						{
							GetTarget2 = nums1[target - CurrentPos2 - 1];
						}
						Hi1 = CurrentPos1;
					}
					else
					{
						Low1 = CurrentPos1;
					}
				}
				else
				{
					countNum = CurrentPos1 + CurrentPos2 + 1;
					if (countNum == target)
					{
						GetTarget1 = nums2[target - CurrentPos1 -1];
						GetTarget2 = nums2[target - CurrentPos1];
					}
					else if (countNum > target)
					{
						GetTarget1 = nums1[CurrentPos1];
						if (target - CurrentPos1 < nums2.size() - 1)
						{
							GetTarget2 = nums2[target - CurrentPos1];
						}
						else
						{
							GetTarget2 = nums2[target - CurrentPos1 - 1];
						}
					}
					else
					{

						Low1 = CurrentPos1;
					}
				}
				prePos2 = CurrentPos2;
			}
			CurrentPos2 = ceil((Low2 + Hi2) / 2);
		} while (prePos2 != CurrentPos2);
		Low2 = 0;
		Hi2 = nums2.size() - 1;
		prePos2 = -1;
		prePos1 = CurrentPos1;
		CurrentPos2 = 0;
		CurrentPos1 = ceil((Low1 + Hi1) / 2);
	} while (prePos1 != CurrentPos1);
	if ((int)totalNum % 2 ==1)
	{
		return GetTarget1;
	}
	else
	{
		return float(GetTarget1 + GetTarget2) / 2;
	}
	
}

int MedianTwoSortedArrays::Main()
{
	vector<int> nums1 = { 100000};
	vector<int> nums2 = { 100001};

	float Answer = findMedianSortedArrays(nums1, nums2);
	std::cout << Answer << endl;
	system("pause");
	return 0;
}