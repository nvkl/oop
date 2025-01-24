#include "italianchef.h"

ItalianChef::ItalianChef(string n) : Chef(n) {
    cout << "Italian chef " << n << " constructor" << endl;
}

bool ItalianChef::askSecret(string p, int f, int w) {
    if (p != ItalianChef::password) {
        return false;
    }
    else {
        cout << "Password correct" << endl;
        ItalianChef::makepizza(f, w);
        return true;
    }
}

int ItalianChef::makepizza(int f, int w) {
    int flourPortion = f / 5;
    int waterPortion = w / 5;
    int pizza = min(flourPortion,waterPortion);
    cout << "Italian chef " << ItalianChef::getName() << " with " << f << " flours and " << w << " waters can make " << pizza << " pizzas" << endl;
    return pizza;
}

ItalianChef::~ItalianChef() {
    cout << "Italian chef " << ItalianChef::getName() << " deconstructor" << endl;
}
