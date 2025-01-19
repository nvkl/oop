#include "game.h"

game::game(int m) : maxNumber(m), playerGuess(0), numOfGuesses(0){
    srand(time(NULL));
    randomNumber = rand() % maxNumber + 1;
    cout << "GAME CONSTRUCTOR: object initialized with " << m << " as maximum value" << endl;
}

game::~game(){
    cout << "GAME CONSTRUCTOR: object cleared from stack memory"<< endl;
}

void game::play(){
    do {
        cout << "Guess a number between 1 - " << maxNumber << endl;
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess > randomNumber){
            cout << "Lower" << endl;
        }
        else if (playerGuess < randomNumber){
            cout << "Higher" << endl;
        }
        else if (playerGuess == randomNumber) {
            cout << "Correct" << endl;
        }
    } while (playerGuess != randomNumber);

    printGameResult();
}

void game::printGameResult(){
    cout << "You guessed the right answer = " << randomNumber << " with " << numOfGuesses << " guesses" << endl;
}
