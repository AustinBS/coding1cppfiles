#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "favgames.h"

using namespace std;

int main() {
    
    vector<string> favGames;
    const string filename = "favgames.txt";
    load(favGames, filename);
    int choice;
    
    while (true) {
        cout << "Menu:\n1. Add a favorite game\n2. Edit a favorite game\n3. Show favorite games\n4. Clear favorite games\n5. Quit\n";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
                cout << "Enter the name of the game: ";
                string newGame;
                getline(cin, newGame);
                favGames.push_back(newGame);
        } else if (choice == 2) {
            cout << "Enter the index of the game you want to edit: ";
            int index;
            cin >> index;
            index--;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (index >= 0 && index < favGames.size()) {
                cout << "Enter the new name of the game: ";
                string newName;
                getline(cin, newName);
                favGames[index] = newName;
            } else {
                cout << "Invalid index!\n";
            }
        } else if (choice == 3) {
            cout << "Favorite Games:\n";
            for (size_t i = 0; i < favGames.size(); ++i) {
                cout << i + 1 << ". " << favGames[i] << endl;
            }
        } else if (choice == 4) {
            favGames.clear();
            cout << "Favorite games list cleared.\n";
        } else if (choice == 5) {
            save(favGames, filename);
            cout << "Exiting program.\n";
            return 0;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    }
    return 0;
}