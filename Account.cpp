//
// Created by Kriszta Oniga on 11/20/2022.
//

#include "Account.h"
int Account::counter{0};

Account::Account(double balance) {
    this->balance = balance;
    this->id = ++counter;
}

void Account::deposit(double amount) {
    if(amount>0)
    {
        balance += amount;
    }

}

bool Account::withdraw(double amount) {
    if(amount <= balance){
        balance-=amount;
        return true;
    }
    return false;
}

int Account::getId() const {
    return this->id;
}

double Account::getBalance() const {
    return this->balance;
}

void Account::print(ostream &os) const {
    cout<<"ID: " <<this->getId() <<" Balance: "<< this->getBalance()<<endl;
}

ostream &operator<<(ostream &os, const Account &account) {
    os<<account.getId() << " " << account.getBalance()<<endl;
    return os;
}
