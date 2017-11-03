#include <string>
#include <map>
#include <iostream>

class TestClass; // fwd declare
#define MEMBER_FUNCTION_DEFINE(name, stringVarName) void name(std::string s) // silly macro
typedef void (TestClass::*MemberFunction)(std::string); // typedef the function pointer(?)

class TestClass
{
public:
	void caller(int num, std::string s)
	{
		auto itr = CallMap.find(num);
		if (itr != CallMap.end())
		{
			MemberFunction func = itr->second;
			(this->*func)(s);
		}
		else
		{
			std::cerr << "Unknown num: " << num << std::endl;
		}
	}

private:
	MEMBER_FUNCTION_DEFINE(m)
	{
		std::cout << __func__ << ": " << s << std::endl;
	}

	static const std::map<int, MemberFunction> CallMap;
};