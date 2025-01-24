#include "chef.h"
#include "italianchef.h"
using namespace std;

int main()
{
    srand(time(NULL));

    int ingredients[4];

    for (int i = 0; i < 4; i++) {
        ingredients[i] = { rand() % 96 + 5 };
    }

    Chef chef("Ramsay");
    chef.makeSalad(ingredients[0]);
    chef.makeSoup(ingredients[1]);

    ItalianChef ichef("Luigi");

    string password;

    do {
        cout << "Enter password" << endl;
        cin >> password;

        if (password == "end") {
            cout << "Ending program..." << endl;
            return 0;
        }

        if (password == "pizza") {
            ichef.askSecret(password, ingredients[2], ingredients[3]);
        }
        else{
            cout << "Password incorrect\nType 'end' to end program" << endl;
        }

    } while (password != "pizza");

    return 0;
}
