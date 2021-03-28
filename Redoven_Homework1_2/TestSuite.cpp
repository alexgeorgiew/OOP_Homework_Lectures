#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name)
{
	this->name = name;
}

void TestSuite::add(const TestCase& input)
{
	this->testcases.push_back(input);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
	std::vector<TestCase>result;
	for (int i = 0; i < this->testcases.size(); i++)
	{
		if (testcases[i].isPassing())
		{
			result.push_back(testcases[i]);
		}
	}
	return result;
}

std::vector<TestCase> TestSuite::filterFailing() const
{
	std::vector<TestCase>result;
	for (int i = 0; i < this->testcases.size(); i++)
	{
		if (!testcases[i].isPassing())
		{
			result.push_back(testcases[i]);
		}
	}
	return result;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType input) const
{
	std::vector<TestCase>result;
	for (int i = 0; i < this->testcases.size(); i++)
	{
		if (testcases[i].getErrorType()==input)
		{
			result.push_back(testcases[i]);
		}
	}
	return result;
}

void TestSuite::removeByErrorType(ErrorType input)
{
	for (int i = 0; i < this->testcases.size(); i++)
	{
		if (testcases[i].getErrorType() == input)
		{
			this->testcases.erase(testcases.begin() + i);
		}
	}
	
}

std::string TestSuite::getName() const
{
	return this->name;
}

void TestSuite::setName(const std::string& input)
{
	this->name = input;
}