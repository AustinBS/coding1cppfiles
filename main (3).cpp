#include <iostream>
#include <string>
#include <vector>
using namespace std;

int triple(int number);
class dogs {
public:
    string name;
    int hungerLevel;
    int mood;

    void bark() {
        cout << "My name is " << name << endl;
        if(mood + hungerLevel > 15) cout << "I am raging!" << endl;
        else if(mood + hungerLevel > 10) cout << "I am upset." << endl;
        else if(mood + hungerLevel > 5) cout << "I am cranky." << endl;
        else cout << "I am great" << endl;
        passTime();
    }
    void runAround();
    void snarf() {
        hungerLevel--;
        if(hungerLevel < 0) hungerLevel = 0;
        passTime();
    }
    void passTime() {
        hungerLevel++;
        mood++;
    }
    dogs(string givenName = "Max") {
        name = givenName;
        hungerLevel = 2;
        mood = 2;
    }
};

int main() {
    // string name = "Austin";
    // int age = 21;

    // cout << "there are " << name.size() << "characters in the name" << name << endl;
    // cout << age << endl;
    // name.erase(name.begin() + 2);
    // cout << name << endl;

    // dogs dog("Jerry");
    // dog.bark();
    // string input;
    // while(true) {
    //     cout << "type STOP to stop" << endl;
    //     cout << "type BARK to hear from your dog" << endl;
    //     cout << "type PLAY to play with your dog" << endl;
    //     cout << "type FEED to feed your dog" << endl;
    //     getline(cin, input);

    //     if(input == "STOP") {
    //         cout << "Thanks for playing!" << endl;
    //         break;
    //     }
    //     else if(input == "BARK") {
    //         dog.bark();
    //     }
    //     else if(input == "PLAY") {
    //         dog.runAround();
    //     }
    //     else if(input == "FEED") {
    //         dog.snarf();
    //     }
    //     else {
    //         cout << "Invalid input, please try again" << endl;
    //     }
    // } // end of tamagotchi
    
    vector<dogs> dogsVec(5);

    for(int i = 0; i < dogsVec.size(); i++) {
        dogsVec[i].bark();
    }

    dogs bluey;
    dogs bingo = dogs("Bingo");
}

//defining a function
int triple(int number) {
    return number + number + number;
}
void dogs::runAround() {
    cout << "I can catch the ball!" << endl;
    mood--;
    if(mood < 0) mood = 0;
    passTime();
}