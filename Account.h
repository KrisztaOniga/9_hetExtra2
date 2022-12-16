//
// Created by Kriszta Oniga on 11/20/2022.
//

#ifndef INC_9_HETEXTRA2_ACCOUNT_H
#define INC_9_HETEXTRA2_ACCOUNT_H

#include <iostream>
using namespace std;
class Account {
public:
    Account(double balance=0);
    void deposit( double amount);
    bool withdraw(double amount);
    int getId() const;
    double getBalance() const;
    void print(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Account& account);
private:
    static int counter;
    int id; //generated field
    double balance;
};

#endif //INC_9_HETEXTRA2_ACCOUNT_H
