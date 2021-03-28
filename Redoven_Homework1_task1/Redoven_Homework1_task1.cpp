

#include <iostream>
#include "VendingMachine.hpp"

int main()
{
    
    VendingMachine v1;
    Drink d1("Rakia", 1000, 1, 2);
    Drink d2("Vodka", 0, 2, 1);
    Drink d3("Fanta", 0, 2, 1);
    v1.add_drink(d1);
     v1.add_drink(d2);
     v1.add_drink(d3);
     v1.buy_drink("Rakia", 3);
     std::cout << v1.get_items()[0].get_name();
     VendingMachine v2;
     v2 = v1;
     v2.buy_drink("Vodka", 3);
     std::cout << v2.get_number_of_items();
     std::cout << v2.get_items()[0].get_name();
 
   
    
}


