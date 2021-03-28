#include "VendingMachine.hpp"

VendingMachine::VendingMachine()
{
	this->money_in_machine = 0.0;
	this->number_of_items = 0;
	items = new Drink[0];
}

VendingMachine::VendingMachine(const VendingMachine& from)
{
	this->money_in_machine = from.get_income();
	this->items = Copy(from.get_items(), from.get_number_of_items());
	this->number_of_items = from.get_number_of_items();
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
	if (this != &from)
	{
		delete[] items;
		this->money_in_machine = from.get_income();
		this->number_of_items = from.get_number_of_items();
		this->items = Copy(from.get_items(), from.get_number_of_items());
	}
	return *this;
}

VendingMachine::~VendingMachine()
{
	delete[]items;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
	for (int i = 0; i < this->number_of_items; i++)
	{
			if (this->Same_name(this->items[i].get_name(), to_add.get_name()))
			{
				return false;
			}
	}
	Drink* newitems = new Drink[this->number_of_items + 1];
		for (int i = 0; i < this->number_of_items; i++)
		{
			newitems[i] = items[i];
		}
		newitems[this->number_of_items] = to_add;
		this->number_of_items++;
		delete[]items;
		items = newitems;
	return true;
}

int VendingMachine::buy_drink(const char* drink_name, const double money)
{
	for (int i = 0; i < this->number_of_items; i++)
	{
		if (this->Same_name(this->items[i].get_name(), drink_name) && money>= this->items[i].get_price())
		{
			for (int j = i; j < this->number_of_items - 1; j++)
			{
				this->items[j] = this->items[j + 1];
			}
			this->number_of_items--;
			this->money_in_machine += money;

			Drink* newitems = new Drink[this->number_of_items];
			for (int k = 0; k < this->number_of_items; k++)
			{
				newitems[k] = items[k];
			}
			delete[]items;
			items = newitems;
			return 0;
		}
		else if (this->Same_name(this->items[i].get_name(), drink_name) && money < this->items[i].get_price())
		{
			this->money_in_machine += money;
			return 1;
		}
	}
	return 2;
}

double VendingMachine::get_income() const
{
	return this->money_in_machine;
}

Drink* VendingMachine::Copy(const Drink* input,const int count_items_of_input)
{
	Drink* local = new Drink[count_items_of_input];
	for (int i = 0; i < count_items_of_input; i++)local[i] = input[i];
	return local;
}

int VendingMachine::get_number_of_items()const
{
	return this->number_of_items;
}

Drink* VendingMachine::get_items()const
{
	return this->items;
}

bool VendingMachine::Same_name(const char* input1, const char* input2)const
{
	int len_of_1 = 0, len_of_2 = 0;
	for (int j = 0; input1[j] != '\0'; j++)len_of_1 = j;
	for (int j = 0; input2[j] != '\0'; j++)len_of_2 = j;
	if (len_of_1 == len_of_2)
	{
		for (int j = 0; j <= len_of_1; j++)
		{
			if (input1[j] != input2[j])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}