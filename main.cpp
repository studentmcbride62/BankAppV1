#include <iostream>

#include "BankAccount.h"

int main() {  // sandbox to play with objects
    std::cout << "\n-----------BankAccount Objects-------------\n";
    // static instantiation (compile time) - destructed when it goes out scope
    BankAccount customer1("Mick Mouse","1234567",2350.50);
    customer1.display();
    customer1.withdraw(500);
    customer1.display();
    // dynamic instantiation (run time) - destructed when we delete it in the program
    BankAccount* customer2 = new BankAccount("Don Duck","7654321",1250.75);
    customer2->display();
    delete customer2;


    //std::cout << "\n-----------CheckingAccount Objects-------------\n";


    return 0;
}
