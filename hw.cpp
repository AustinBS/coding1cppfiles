#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // create an array of strings named faveGames with size 10
    // start a while true loop
    // ask the player what they want to do
    // add a game
    // show all games
    // quit

    vector<string> favGames;
    string input = "";

    while (true) {
        cout << "What do you want to do?" << endl;
        cout << "add: Add a game to the list" << endl;
        cout << "show: Display the current list" << endl;
        cout << "quit: Quit the program" << endl;
        getline(cin, input);

        if (input == "add") {
            cout << "What game would you like to add?" << endl;
            getline(cin, input);

            favGames.push_back(input);
        } 
        else if (input == "show") {
            if(favGames.size() != 0) {
                for (int i = 0; i < favGames.size(); i++) {
                    cout << favGames[i] << endl;
                }
            }
            else {
                cout << "Your list is currently empty" << endl;
            }
        } 
        else if (input == "quit") {
            cout << "Thanks for playing!" << endl;
            break;
        } 
        else {
            cout << "invalid input, please input add, show, or quit" << endl;
        }
    }

    return 0;
}