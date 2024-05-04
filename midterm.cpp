//adventure!
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int diceRoll(int size= 6) {
    if (size < 1) {
        size = 2;
    }
    if (size > 100) {
        size = 100;
    }

    return rand() % size + 1;
}

bool askYN(string question) {
    do {
        cout << question << " (y/n)" << endl;
        char input;
        cin >> input;

        if(input == 'y') {
            return true;
        }
        if(input == 'n') {
            return false;
        }

        cout << "please input either a lowercase y or n" << endl;
    }while(true);
}

bool isDead(int hp) {
    if (hp <= 0) {
        cout << "You have died :(" << endl;
        return true;
    }
    else {
        return false;
    }
}

int main(){
    srand(time(0));

    bool adventuring = false;
    int hp = 30;
    int gold = 0;
    int foundGold = 0;
    int block = 0;
    int attack = 0;
    int turnctr = 0;
    adventuring = askYN("Do you want to start your adventure?");

    do {
        turnctr++;
        cout << "An orc attacks!" << endl << "Prepare for battle!" << endl;
        block = diceRoll();
        attack = diceRoll();
        cout << "You rolled " << block << endl << "The orc rolled " << attack << endl;
        if (block >= attack) {
            hp--;
            if (isDead(hp) == true) {
                break;
            }
            cout << "You successfully blocked the attack and got away! But you took 1 damage" << endl;
            foundGold += rand() % 100 + 1;
            cout << "You found " << foundGold << " gold" << endl;
            gold += foundGold;

            adventuring = askYN("Do you want to keep adventuring");
        }
        else {
            hp -= attack;
            if (isDead(hp) == true) {
                break;
            }
            cout << "Oh no! You didn't block the attack and took " << attack << " damage!" << endl;
        } 
    }while (adventuring == true);

    if (isDead(hp) == false) {
        cout << "You survived! :)" << endl;
        if (hp < 5) {
            cout << "You might want to go to a doctor though, you're looking pretty rough" << endl;
        }
        cout << "You found " << gold << " gold! You're rich!" << endl;
    } else {
        cout << "Oops, you didn't make it back alive, but you had " << gold << " gold on you" << endl;
    }

    cout << "You lasted " << turnctr << " turns!" << endl;
    cout << endl << "Thanks for adventuring!!!" << endl << "Sorry if you died lol" << endl;
    return 0;
}