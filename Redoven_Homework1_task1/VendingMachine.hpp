#include "drink.hpp"

class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);
    ~VendingMachine();

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;
    // Add whatever you deem needed here
    int get_number_of_items()const;
    Drink* get_items()const;
private:
    // Add whatever you deem needed here
    Drink* items;
    double money_in_machine;
    int number_of_items;
    Drink* Copy(const Drink* input,const int count_items_of_input);
    bool Same_name(const char* input1, const char* input2)const;
};