#include <iostream>
#include "Account.h"
#include "Customer.h"
#include "Bank.h"
int main() {

//    Account account1(0);
//    account1.deposit(1000);
//    account1.print(cout);
//    bool result = account1.withdraw(500);
//    if (!result) {
//        cout<<"You don't have sufficient founds for this withdraw"<<endl;
//    }
//    account1.print(cout);
//    bool result2 = account1.withdraw(1000);
//    if (!result2) {
//        cout<<"You don't have sufficient founds for this withdraw"<<endl;
//    }
//    account1.print(cout);

    Customer customer1("Antal", "Janos");
    customer1.newAccount(0);
    customer1.newAccount(1000);

    cout<<customer1;

    Bank bank1 = Bank("OTP");
    vector<int> IDS = bank1.loadCustomers("customers.txt");
    bank1.printCustomers();
    for (int i = 0; i < IDS.size(); ++i) {
        cout<<IDS[i]<< " ";
    }

    cout<<endl;

    bank1.printCustomersAndAccounts(cout);
    return 0;
}
