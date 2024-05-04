#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Weapon {
public:
    string name;
    int damage;

    Weapon(string name, int damage) : name(name), damage(damage) {}
};

class Consumable {
public:
    int foundCount = 1;

    bool findConsumable() {
        if (rand() % 2 == 1) { // 50% chance of finding a consumable
            foundCount++; // Increment found consumables count
            cout << "you found a healing item" << endl;
            return true;
        }
        return false;
    }

    // Function to use the consumable and heal a random amount of HP between 10 and 25
    int useConsumable() {
        if (foundCount > 0){
            cout << "You used one healing item" << endl;
            foundCount--;
            return rand() % 16 + 10;
        }
        else {
            cout << "You have no healing items" << endl;
            return 0;
        }
    }
};

class Enemy {
public:
    string name;
    int maxHealth;
    int currHealth;
    Weapon weapon;

    Enemy(string name, int maxHealth, Weapon weapon) : name(name), maxHealth(maxHealth), currHealth(maxHealth), weapon(weapon) {}

    void healthPercent() {
        double healthPercent = (double) currHealth / maxHealth;
        if (healthPercent <= 0.33)
            cout << "It's looking weak." << endl;
        else if (healthPercent <= 0.66)
            cout << "It is looking a bit rough." << endl;
        else
            cout << "It still looks tough!" << endl;
    }

    void attackPlayer(int& playerHealth) {
        int roundDamage = weapon.damage + rand() % 10 - 5;
        cout << name << " attacks you with " << weapon.name << " causing " << roundDamage << " damage." << endl;
        playerHealth -= roundDamage;
    }

    void playerAttacks (Weapon playerWeapon) {
        int roundDamage = playerWeapon.damage + rand() % 10 - 5;
        cout << "You attack " << name << " with " << playerWeapon.name << " causing " << roundDamage << endl;
        currHealth -= roundDamage;
    }
};

int main() {
    srand(time(0));
    vector<string> names = {"Orcs", "Goblins", "Golems", "Zombies", "Assassins", "Trolls", "Gnomes"};
    Weapon weapons[] = {
        Weapon("Dagger", 5),
        Weapon("Club", 10),
        Weapon("Sword", 15),
        Weapon("Spear", 20),
        Weapon("Crossbow", 25),
        Weapon("Waraxe", 30)
    };
    int playerHealth = 250;
    Weapon playerWeapon("Magic Sword", 20);
    Consumable healthPotion;

    cout << "Welcome to the Adventure Game!" << endl;
    while (playerHealth > 0) {
        healthPotion.findConsumable();
        Enemy currenemy(names[rand() % names.size()], rand() % 66 + 10, weapons[rand() % 6]);
        cout << "You encounter an " << currenemy.name << " holding a " << currenemy.weapon.name << "!" << endl;
        while (currenemy.currHealth > 0) {
            cout << "Your health: " << playerHealth << endl;
            currenemy.healthPercent();
            cout << "What will you do?" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Use Healing Item" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            if (choice == 1) {
                currenemy.playerAttacks(playerWeapon);
                currenemy.attackPlayer(playerHealth);
                if (playerHealth <= 0) {
                    cout << "Game Over! You died." << endl;
                    break;
                }
            } else if (choice == 2) {
                if (playerHealth <= 0) {
                    cout << "Game Over! You died." << endl;
                    break;
                }
                playerHealth += healthPotion.useConsumable();
            } else {
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }

    return 0;
}