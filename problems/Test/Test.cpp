﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <functional>

#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>
#include <sstream>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.Hi"
//#include "..\Common\TreeNode.Hi"
//#include "..\Common\ListNode.Hi"
using namespace std;



//////////////////////////////////////////////////////////////////////////
int calculate(string s)
{
	stack<int> nums;
	stack<char> op;
	int val = 0;

	s.append("+");
	for (auto c : s)
	{
		if (isspace(c)) continue;
		if (isdigit(c))
		{
			val = val * 10 + (c - '0');
			continue;
		}

		if (!nums.empty() && !op.empty() && (op.top() == '*' || op.top() == '/'))
		{
			val = (op.top() == '*') ? nums.top() * val: nums.top() / val;
			nums.pop();
			op.pop();
		}
		if (nums.empty() || op.empty() || c == '*' || c == '/')
		{
			nums.push(val);
			op.push(c);
		}
		else
		{
			nums.top() = (op.top() == '+') ? nums.top() + val : nums.top() - val;
			op.top() = c;
		}
		val = 0;
	}

	return nums.top();
}

//template<typename... Args>
//auto FunForward(Args... args)
//{
//	return calculate(args...);
//}


int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_begin = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		cout << endl << "/////////////////////////////" << endl;
		QueryPerformanceCounter(&nBeginTime);
	};

	auto f_time_end = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		QueryPerformanceCounter(&nEndTime);
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<string> TESTS;
	vector<int> ANSWERS;

	TESTS.push_back("3+2*2");
	ANSWERS.push_back(7);

	TESTS.push_back(" 3/2 ");
	ANSWERS.push_back(1);

	TESTS.push_back(" 3+5 / 2 ");
	ANSWERS.push_back(5);

	TESTS.push_back("  ");
	ANSWERS.push_back(0);

	TESTS.push_back("100000");
	ANSWERS.push_back(100000);

	TESTS.push_back("1-1+1");
	ANSWERS.push_back(1);

	TESTS.push_back("100000000/1/2/3/4/5/6/7/8/9/10");
	ANSWERS.push_back(27);

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = calculate(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		//solve(TESTS[i]);
		//cout << checkAnswer<vector<vector<char>>>(TESTS[i], ANSWERS[i]) << endl;

		f_time_end();
	}
}


//////////////////////////////////////////////////////////////////////////
// TreeNode
//int main()
//{
//	vector<TreeNode *> N;
//	vector<int> K;
//	vector<bool> A;
//
//	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
//	//K.push_back(3);
//	A.push_back(true);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,null,null,4,4"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		cout << N[i] << endl;
//		//DrawTreeNode(N[i]);
//
//		bool ans = isBalanced(N[i]);
//		cout << checkAnswer<bool>(ans, A[i]) << endl;
//		//DrawTreeNode(ans);
//
//	}
//}


//////////////////////////////////////////////////////////////////////////
// List Node
//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = StringToListNode("[4,7,5,3]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	for (auto i : lists)
//	{
//		cout << i << endl;
//		pHead = sortList(i);
//		cout << pHead << endl;
//		cout << endl;
//	}
//}


