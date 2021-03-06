﻿// 217.ContainsDuplicate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

//bool containsDuplicate(vector<int>& nums) 
//{
//	map<int, int> a;
//	for (int i : nums)
//	{
//		a[i]++;
//		if (a[i] > 1) return true;
//	}
//	return false;
//}

bool containsDuplicate(vector<int>& nums)
{
	sort(nums.begin(), nums.end());

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i - 1] == nums[i]) return true;
	}

	return false;
}

void Init(vector<int>& nums)
{
	//int A[] = { 1,2 };
	//int A[] = { 1,2,3,4 };
	int A[] = { 1,2,3,4,5,6 };
	//int A[] = { 1,2,3,4,5,6,7 };
	nums.clear();
	for (int i : A)
	{
		nums.push_back(i);
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> nums;
	Init(nums);

	cout << containsDuplicate(nums) << endl;
}
