#include "TestCase.hpp"

TestCase::TestCase(const std::string& name, const Error& error)
{
	this->name = name;
	this->error = error;
}
std::string TestCase::getName() const
{
	return this->name;
}
bool TestCase::isPassing() const
{
	if (this->error.getType() == ErrorType::None || this->error.getType() == ErrorType::Warning)return true;
	return false;
}   
bool TestCase::hasError() const
{
	if (this->error.getType() == ErrorType::None)return false;
	return true;
}
ErrorType TestCase::getErrorType() const
{
	return this->error.getType();
}
std::string TestCase::getErrorMessage() const
{
	if (this->error.hasMessage())
	{
		return this->error.getMessage();
	}
	return "";
}

