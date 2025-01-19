#include "game.h"

int main() {

    int max;
    cout << "Enter parameter : ";
    cin >> max;

    game g(max);

    g.play();
}
