#ifndef BANKAPPV1_CHECKINGACCOUNT_H
#define BANKAPPV1_CHECKINGACCOUNT_H
#include <iostream>
#include <ostream>

#include "BankAccount.h"

class CheckingAccount:public BankAccount {
private:
    double m_overdraftLimit;
public:
    CheckingAccount(const std::string &accHolder, const std::string &accNum, const double balance, double overdraftLimit):BankAccount(accHolder, accNum, balance) {
        m_overdraftLimit = overdraftLimit;
    }
    ~CheckingAccount() {

    }
    bool withdraw(double amount) { // override base class withdraw method - form of polymorphism
        if (amount <= m_balance + m_overdraftLimit) {
            if (amount > m_balance) {
                m_overdraftLimit += (m_balance - amount);
            }
            m_balance -= amount;
            return true;
        }
        else {
            return false;
        }
    }
    void display() {
        BankAccount::display();
        std::cout << "Overdraft Limit: " << m_overdraftLimit << std::endl;
    }
};

#endif //BANKAPPV1_CHECKINGACCOUNT_H
