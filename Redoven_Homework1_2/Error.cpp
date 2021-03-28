#include "Error.hpp"

bool Error::hasMessage() const
{
	if (message==nullptr)return false;
	return true;
}

const char* Error::getMessage() const
{
	return this->message;
}

ErrorType Error::getType() const
{
	return this->type;
}

 Error Error::newNone()
{
	 Error local;
	 local.set_type(ErrorType::None);
	 return local;
}

 Error Error::newBuildFailed(const char* message)
 {
	 Error local;
	 local.set_message(message);
	 local.set_type(ErrorType::BuildFailed);
	 return local;
 }

 Error Error::newWarning(const char* message)
 {
	 Error local;
	 local.set_message(message);
	 local.set_type(ErrorType::Warning);
	 return local;
 }

 Error Error::newFailedAssertion(const char* message)
 {
	 Error local;
	 local.set_message(message);
	 local.set_type(ErrorType::FailedAssertion);
	 return local;
 }

 Error::Error()
 {
	 this->message = nullptr;
	 this->type = ErrorType::None;
 }

 Error::~Error()
 {
	 delete[]message;
 }

 Error::Error(Error const& input)
 {
	 type = input.getType();
	 if (input.getMessage())
	 {
		 message = Copy(input.getMessage());
	 }
	 else
	 {
		 message = nullptr;
	 }
 }

 Error& Error::operator=(Error const& input)
 {
	 if (this != &input)
	 {
		 type = input.getType();
		 if (input.getMessage())
		 {
			 delete[]message;
			 message = Copy(input.getMessage());
		 }
		 else
		 {
			 message = nullptr;
		 }
	 }
	 return *this;
 }

 void Error::set_type(const ErrorType input)
 {
	 this->type = input;
 }

 void Error::set_message(const char* message)
 {
	 this->message = Copy(message);
 }

 char* Error::Copy(const char* message)
 {
	 int size = Lengthof(message);
	 char* local = new char[size + 1];
	 for (int i = 0; i < size; i++)local[i] = message[i];
	 local[size] = '\0';
	 return local;
 }

 int Error::Lengthof(const char* message)
 {
	 int result = 0;
	 for (int i = 0; message[i] != '\0'; i++)result++;
	 return result;
 }
