#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Player {
public:
    int money;
    string username;
    vector<int> winningHistory;
};

int main () {


    Player player;
    random_device rd;
    uniform_int_distribution<int> dist (1, 100);
    int randomNumber = dist(rd);
    int userAmount = 0;
    cout << "---------------------------------------\n";
    cout << "Welcome to Casino Number Guessing Game!\n";
    cout << "---------------------------------------\n\n";
    cout << "In this game you will have to guess a number between 1 and 100.\nThis Game has 3 levels of difficulty and you will have limited "
        "choices based on the level you choose.\n\n";
    cout << "Please type your username for this Game Session: ";
    cin >> player.username;
    cout << "\nPlease enter the difficulty level:\n";
    cout << "1) Easy(10 tries)   2) Medium(7 tries)   3)  Hard(4 tries)   0) End Game\n";
    int difficultyLevel;
    cout << "Select: ";
    cin >> difficultyLevel;
    while (difficultyLevel) {
        int tries;
        if (difficultyLevel == 1) {
            tries == 10;
        }   else if (difficultyLevel == 2) {
            tries = 7;
        }   else {
            tries = 4;
        }
    }
    cout << "Good Bye! We hope you'll be back soon!";
    return 0;
}
