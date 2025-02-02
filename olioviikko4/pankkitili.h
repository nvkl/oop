#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <string>

using namespace std;

class pankkitili
{
public:
    pankkitili(string);
    double getBalance(void);
    virtual bool deposit(double);
    virtual bool withdraw(double);
protected:
    string omistaja;
    double saldo = 0;
};

#endif // PANKKITILI_H
