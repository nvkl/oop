#include "game.h"

int main() {

    int max;
    cout << "Enter parameter : ";
    cin >> max;

    game g(max);
    game p(max);

    p.play();
}
