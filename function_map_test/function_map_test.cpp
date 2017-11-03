// function_map_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "function_map_test.h"

const std::map<int, MemberFunction> TestClass::CallMap = {
	{ 1, &TestClass::m }
};

int main()
{
	TestClass t;
	while (true)
	{
		int a;
		std::cout << "num: ";
		std::cin >> a;

		std::string msg;
		std::cout << "msg: ";
		std::cin >> msg;

		t.caller(a, msg);
	}
	return 0;
}

