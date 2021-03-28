#include "drink.hpp"

Drink::~Drink()
{
	delete[]name;
}
Drink::Drink()
{
	this->name = new char[1]{ '\0' };
	this->calories = 0;
	this->quantity = 0.0;
	this->price = 0.0;
}
Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price)
{
	this->name = Copy(init_name);
	this->calories = init_calories;
	this->quantity = init_quantity;
	this->price = init_price;
}
Drink::Drink(const Drink& input)
{
	//delete[]name;
	//this->name = Copy(input.get_name());
	this->name = new char[1]{ '\0' };
	set_name(input.get_name());
	this->calories = input.get_calories();
	this->quantity = input.get_quantity();
	this->price = input.get_price();
}
Drink& Drink::operator=(const Drink& input)
{
	if (this != &input)
	{
		set_name(input.get_name());
		this->calories = input.get_calories();
		this->quantity = input.get_quantity();
		this->price = input.get_price();
	}
	return *this;
}
const char* Drink::get_name() const
{
	return this->name;
}
int Drink::get_calories() const
{
	return this->calories;
}
double Drink::get_quantity() const
{
	return this->quantity;
}
double Drink::get_price() const
{
	return this->price;
}
void Drink::set_name(const char* new_name)
{
	delete[]name;
	this->name = Copy(new_name);
}
int Drink::GetLengthOf(const char* input)const
{
	int result = 0;
	for (int i = 0; input[i] != '\0'; i++)result++;
	return result;
}
char* Drink::Copy(const char* input)const
{
	int size = GetLengthOf(input);
	char* local = new char[size + 1];
	for (int i = 0; i < size; i++)local[i] = input[i];
	local[size] = '\0';
	return local;
}