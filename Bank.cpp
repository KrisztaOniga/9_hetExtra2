//
// Created by Kriszta Oniga on 12/16/2022.
//

#include "Bank.h"
#include <fstream>
#include <sstream>

Bank::Bank(const string &name) {
    this->name = name;
}

int Bank::newCustomer(const string &firstName, const string &lastName) {
    Customer customer(firstName,lastName);
    customers.push_back(customer);
    return customer.getId();
}

bool Bank::deleteCustomer(int id) {
    int poz;
    bool ok = false;
    for (int i = 0; i < customers.size(); ++i) {
        if (customers[i].getId() == id) {
            poz = i;
            ok = true;
        }
    }
    customers.erase(customers.begin() + poz);
    return ok;
}

Customer &Bank::getCustomer(int id) {
   for(Customer customer : customers){
       if(customer.getId() == id){
           return customer;
       }
   }
}

void Bank::printCustomers(ostream &os) const {
    for(Customer customer : customers){
        os<<customer.getId()<< " " <<customer.getFirstName() << " "<<customer.getLastName()<<" " <<customer.getNumAccounts()<<endl;
    }
}

void Bank::printCustomersAndAccounts(ostream &os) const {
    for (Customer c: customers) {
        c.print(os);
        cout<<"Accounts: ";
        cout<<&c.getAccount(c.getId());
        cout<<endl;
    }
}

vector<int> Bank::loadCustomers(const string &filename) {
    vector<int> customerIDs;
    ifstream ifs(filename);
    if (!ifs) {
        cerr << "File open error" << endl;
        exit(1);
    }
    string line;
    getline(ifs, line);
    while (getline(ifs, line)) {
        string firstName, lastName;
        stringstream ss(line);
        getline(ss, firstName, ' ');
        getline(ss, lastName, ' ');
        Customer customer(firstName,lastName);
        customers.push_back(customer);
        customerIDs.push_back(customer.getId());
    }

    return customerIDs;
}
