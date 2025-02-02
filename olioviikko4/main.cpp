#include <iostream>
#include "asiakas.h"
using namespace std;

int main()
{
    asiakas userOne("User1",1000);
    userOne.showSaldo();

    cout << "Debit deposit: ";
    int dd;
    cin >> dd;
    userOne.talletus(dd);

    cout << "Debit withdraw: ";
    int dw;
    cin >> dw;
    userOne.nosto(dw);

    cout << "Credit withdraw: ";
    int cw;
    cin >> cw;
    userOne.luotonNosto(cw);

    cout << "Credit deposit: ";
    int cd;
    cin >> cd;
    userOne.luotonMaksu(cd);

    userOne.showSaldo();


    asiakas userTwo("User2",3500);
    userTwo.showSaldo();

    cout << "Account name: " << userOne.getName() << endl;

    cout << "Transfer from: " << userOne.getName() << " to : " << userTwo.getName() << endl;
    int ta;
    cin >> ta;
    userOne.tiliSiirto(ta,userTwo);

    cout << "Account name: " << userTwo.getName() << endl;;
    userTwo.showSaldo();

    return 0;
}
