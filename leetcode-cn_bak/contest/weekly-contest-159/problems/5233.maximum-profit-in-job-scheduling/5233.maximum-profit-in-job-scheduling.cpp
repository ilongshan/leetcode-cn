﻿// 5233.maximum-profit-in-job-scheduling.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
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

#include "../Common/ParameterType.h"
#include "../Common/Common.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
{
	return 0;
}

int test(vector<int> startTime, vector<int> endTime, vector<int> profit)
{
	return jobScheduling(startTime, endTime, profit);
}

#define TEST_FUNC test
int main()
{
	PerformanceTimer timer;
	ifstream f("tests.txt");
	TestCases test_cases(f);

	using func_t = function_type<function<decltype(TEST_FUNC)>>;
	while (!test_cases.empty())
	{
		timer.start();

		func_t::return_type ans = func_t::call(TEST_FUNC, test_cases);
		func_t::return_type answer = test_cases.get<func_t::return_type>();
		cout << checkAnswer<decltype(ans)>(ans, answer) << endl;

		timer.stop();
	}
}
