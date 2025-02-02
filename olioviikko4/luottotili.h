#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"

class luottotili: public pankkitili
{
public:
    luottotili(string, double);
    virtual bool deposit(double) override;
    virtual bool withdraw(double) override;

protected:
    double luottoRaja = 0;
};

#endif // LUOTTOTILI_H
