#include "asiakas.h"
#include <iostream>

using namespace std;

asiakas::asiakas(string name, double creditLimit) : nimi(name), kayttotili(name), luottotili(name, creditLimit) {
    cout << "Bank account created for: " << name << endl;
    cout << "Credit account created for: " << name << ", credit limit: " << creditLimit << endl;
    cout << "Customership created for: " << name << endl;
}

string asiakas::getName() {
    return nimi;
}

void asiakas::showSaldo() {
    cout << "Checking account balance: " << kayttotili.getBalance() << endl;
    cout << "Credit account balance: " << luottotili.getBalance() << endl;
}

bool asiakas::talletus(double amount) {
    return kayttotili.deposit(amount);
}

bool asiakas::nosto(double amount) {
    return kayttotili.withdraw(amount);
}

bool asiakas::luotonMaksu(double amount) {
    return luottotili.deposit(amount);
}

bool asiakas::luotonNosto(double amount) {
    return luottotili.withdraw(amount);
}

bool asiakas::tiliSiirto(double transferAmount, asiakas &tili) {
    if (transferAmount > kayttotili.getBalance()){
        cout << "Transfer error; insufficient funds." << endl;
        return false;

    } else if (transferAmount < 0){
        cout << "Transfer error; invalid amount." << endl;
        return false;

    } else {
        cout << "Transferring "<< transferAmount << " to: " << tili.getName() << endl;

        kayttotili.withdraw(transferAmount);

        tili.kayttotili.deposit(transferAmount);

        return true;
    }
}
