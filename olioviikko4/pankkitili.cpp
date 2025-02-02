#include "pankkitili.h"
#include <iostream>
using namespace std;

pankkitili::pankkitili(string name): omistaja(name), saldo(0) {

}

double pankkitili::getBalance(void) {
    return saldo;
}

bool pankkitili::deposit(double depositAmount) {
    if (depositAmount <= 0){
        cout << "Invalid deposit amount" << endl;
        return false;

    } else {
        saldo += depositAmount;
        cout << "Deposited " << depositAmount << ". New balance: " << saldo << endl;
        return true;
    }
}

bool pankkitili::withdraw(double withdrawAmount) {
    if (withdrawAmount <= 0) {
        cout << "Please withdraw a valid amount" << endl;
        return false;
    }

    if (withdrawAmount > saldo) {
        cout << "Insufficient funds. Available balance: " << saldo << endl;
        return false;

    } else {
        saldo -= withdrawAmount;
        cout << "Withdrew " << withdrawAmount << ". New balance: " << saldo << endl;
        return true;
    }
}
