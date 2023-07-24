#include <iostream>
#include <random>
#include <vector>
using namespace std;

int difficultyLevel, randomNumber, userAmount;
random_device rd;
uniform_int_distribution<int> dist(1, 50);

class Player {
   public:
    int money = 0;
    string username;
};

void goodLevel() {
    while (difficultyLevel < 0 && difficultyLevel > 3) {
        cout << "Invalid Selection, Please select a number between 0 and 3: ";
        cin >> difficultyLevel;
    }
}

void startGame(Player &player) {
    cout << "---------------------------------------\n";
    cout << "Welcome to Casino Number Guessing Game!\n";
    cout << "---------------------------------------\n\n";
    cout << "In this game you will have to guess a number between 1 and 50.\nThis Game has 3 levels of difficulty and you will have limited "
            "choices based on the level you choose.\n";
    cout << "Amount of cash you win at every difficulty level:\n";
    cout << "Easy Level = 500$  ||  Medium Level = 1000$  ||  Hard Level = 3000$\n\n";
    cout << "Please type your username for this Game Session: ";
    cin >> player.username;
    cout << "\nPlease enter the difficulty level:\n";
    cout << "1) Easy(10 tries)   2) Medium(7 tries)   3)  Hard(4 tries)   0) End Game\n";

    cout << "Select: ";
    cin >> difficultyLevel;
    goodLevel();
}

void playGame(Player &player) {
    while (difficultyLevel) {
        int tries;
        if (difficultyLevel == 1) {
            tries = 10;
        } else if (difficultyLevel == 2) {
            tries = 7;
        } else {
            tries = 4;
        }
        randomNumber = dist(rd);
        int usersNumber;
        bool found = false;
        while (tries--) {
            cout << "You have " << tries + 1 << " tries available\n";
            cout << "Try guessing the number: ";
            cin >> usersNumber;
            if (usersNumber == randomNumber) {
                found = true;
                cout << "\nCongratulations, " << player.username << "! You have won ";
                if (difficultyLevel == 1) {
                    cout << "500$\n";
                    player.money += 500;
                } else if (difficultyLevel = 2) {
                    cout << "1000$\n";
                    player.money += 1000;
                } else {
                    player.money += 3000;
                    cout << "3000$\n";
                }
                cout << "Your current balance is " << player.money << "$\n";
                tries = 0;
                cout << "You can continue your journey or end it right here, what do you think?\n";
                cout << "\nPlease enter the difficulty level or select 0 to end this game session:\n";
                cout << "1) Easy(10 tries)   2) Medium(7 tries)   3)  Hard(4 tries)   0) End Game\n";
                cout << "Select: ";
                cin >> difficultyLevel;
                goodLevel();
            }
        }
        if (!found) {
            cout << "Unfortunately, you could not guess the number. Better luck next time!\n";
            cout << "You still have the opportunity to play again!\n";
            cout << "\nPlease enter the difficulty level:\n";
            cout << "1) Easy(10 tries)   2) Medium(7 tries)   3)  Hard(4 tries)   0) End Game\n";
            cout << "Select: ";
            cin >> difficultyLevel;
            goodLevel();
        }
    }
}

int main() {
    Player player;

    startGame(player);
    playGame(player);

    cout << "Good Bye! We hope you'll be back soon!";
    return 0;
}
