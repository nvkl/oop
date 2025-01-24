#include "chef.h"

Chef::Chef(string n) : chefName(n) {
    cout << "Chef " << n << " constructor" << endl;
}

string Chef::getName() {
    return Chef::chefName;
}

int Chef::makeSalad(int i) {
    int portion = i / 5;
    cout << "Chef " << chefName << " with " << i << " items can make " << portion << " salad portions" << endl;
    return portion;
}

int Chef::makeSoup(int i) {
    int portion = i / 3;
    cout << "Chef " << chefName << " with " << i << " items can make " << portion << " soup portions" << endl;
    return portion;
}

Chef::~Chef() {
    cout << "Chef " << chefName << " deconstructor" << endl;
}
