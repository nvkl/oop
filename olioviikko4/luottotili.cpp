#include "luottotili.h"
#include <iostream>
using namespace std;

luottotili::luottotili(string name, double creditLimit): pankkitili(name), luottoRaja(-creditLimit){

}

bool luottotili::deposit(double depositAmount)
{
    if (saldo + depositAmount > 0) {
        cout << "Deposit too high" << endl;
        return false;
    }

    else if (depositAmount <= 0) {
        cout << "Invalid deposit amount" << endl;
        return false;

    } else {
        saldo += depositAmount;
        cout << "Deposit made to credit account: " << depositAmount << "Remaining credit: " << saldo << endl;
        return true;
    }
}

bool luottotili::withdraw(double withdrawAmount) {
    if (withdrawAmount <= 0) {
        cout << "Invalid withdrawal amount" << endl;
        return false;
    }

    if (withdrawAmount > luottoRaja) {
        cout << "Withdrawal exceeds available credit. Remaining credit: " << luottoRaja << endl;
        return false;

    } else {
        luottoRaja -= withdrawAmount;
        cout << "Withdrawn " << withdrawAmount << " from credit account. Remaining credit: " << luottoRaja << endl;
        return true;
    }
}
