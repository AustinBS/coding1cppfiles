#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class robot {
private:
    //member variables
    string name;
    int charge;
public:
    //member functions
    robot(string givenName = "rob", int givenCharge = 100) {
        cout << "Constructor is Constructing" << endl;
        name = givenName;
        charge = givenCharge;
    }

    //setters
    void setName(string givenName) {
        if (givenName.size() < 15) {
            name = givenName;
        }
        else {
            cout << "Error: Names must be less than 15 characters" << endl;
        }
    }
    void setCharge(int givenCharge) {
        if (givenCharge > 0 && givenCharge <= 100) {
            charge = givenCharge;
        }
        else if (givenCharge < 0) {
            charge = 0;
        }
        else if (givenCharge > 100) {
            charge = 100;
        }
    }
    //getters
    string getName() { return name; }
    int getCharge() { return charge; }

    void status() {
        cout << "[name: " << name << ", charge: " << charge << "]" << endl;
    }
};

int main() {
    srand(time(0));
    //building classes

    //create a new variable of type robot named rob
    /*
    //this will break because we changed our variables to private and then made getters and setters
    robot rob;
    rob.name = "Ripe_Ostrich_Bingus";
    rob.charge = rand() % 100 + 1;

    cout << "My robots name is " << rob.name << endl;
    cout << "My robots charge is " << rob.charge << endl;

    rob.status();

    robot robv2("R2-D2", 4);
    robv2.status();
    */
    vector<string> names = {"torbot", "morbot", "shorbot", "corbot", "porbot"};
    vector<robot> robits;

    for (int i = 0; i < 10; i++) {
        robot rober(names[rand() % names.size()], rand() % 100 + 1);
        robits.push_back(rober);
    }
    for (int j = 0; j < robits.size(); j++) {
        robits[j].status();
    }
    return 0
}