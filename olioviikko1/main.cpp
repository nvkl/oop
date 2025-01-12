#include <iostream>

using namespace std;

int game(int maxNum);

int main() {
    int maxNum;

    cout << "Enter parameter : ";
    cin >> maxNum;

    srand(static_cast<unsigned int>(time(nullptr)));

    int guessCount = game(maxNum);

    cout << "Total guesses : " << guessCount << endl;
    return 0;
}

int game(int maxNum) {
    int number = rand() % maxNum + 1;

    int guess, guessCount = 0;

    do {
        cout << "Guess a number between 1 - " << maxNum << endl;
        cin >> guess;
        guessCount++;

        if (guess > number){
            cout << "Lower" << endl;
        }
        else if (guess < number){
            cout << "Higher" << endl;
        }
        else if (guess == number) {
            cout << "Correct" << endl;
        }
        /*else {
            cout << "Invalid" << endl;
        }*/

    } while (guess != number);

    return guessCount;
}
