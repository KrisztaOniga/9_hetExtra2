//
// Created by Kriszta Oniga on 12/16/2022.
//

#ifndef INC_9_HETEXTRA2_BANK_H
#define INC_9_HETEXTRA2_BANK_H
#include "Customer.h"

class Bank {
public:
    Bank(const string &);

//returns the ID of the new Customer
    int newCustomer(const string &firstName, const string &lastName);

    bool deleteCustomer(int id);

    Customer &getCustomer(int id);

//Convenience functions
    void printCustomers(ostream &os = cout) const;

    void printCustomersAndAccounts(ostream &os = cout) const;

//LOAD customers, returns their IDs
    vector<int> loadCustomers(const string &filename);

private:
    vector <Customer> customers;
    string name;
};


#endif //INC_9_HETEXTRA2_BANK_H
