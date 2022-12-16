//
// Created by Kriszta Oniga on 11/20/2022.
//

#include "Customer.h"

int Customer::counter{0};

Customer::Customer(const string &firstName, const string &lastName) {
  this->firstName = firstName;
  this->lastName = lastName;
  this->id = ++counter;
  this->accounts = *new vector<Account>;
}

const string &Customer::getFirstName() const {
    return this->firstName;
}

void Customer::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

const string &Customer::getLastName() const {
    return this->lastName;
}

Customer::Customer(const vector<Account> &accounts) {
    this->accounts = accounts;
}

void Customer::setLastName(const string &lastName) {
    this->lastName = lastName;
}

Account &Customer::getAccount(int id) {
    for(Account a: accounts){
        if(a.getId() == id){
            return a;
        }
    }
}

int Customer::newAccount(double balance) {
    accounts.push_back(balance);
    return id;
}

bool Customer::deleteAccount(int id) {
    int poz;
    bool ok = false;
    for (int i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getId() == id) {
            poz = i;
            ok = true;
        }
    }
    accounts.erase(accounts.begin() + poz);
    return ok;
}

int Customer::getNumAccounts() const {
    accounts.size();
}

void Customer::print(ostream &os) const {
    cout<<this->getId()<<" "<<this->getFirstName()<<" "<<this->getLastName()<<endl;
    for (int i = 0; i < this->accounts.size(); ++i) {
        os<<"\tAccount Id: "<< accounts[i].getId()<<" balance: "<<accounts[i].getBalance()<<endl;
    }
}

ostream &operator<<(ostream &os, const Customer &customer) {
    customer.print(os);
    return os;
}

Account &Customer::operator[](int index) {
    return this->accounts[index];
}

const Account &Customer::operator[](int index) const {
    return this->accounts[index];
}

