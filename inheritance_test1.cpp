#include <iostream>
using namespace std;

class Performer {
    private:
        string name;
        int age;

    public:
        Performer(string name, int age):name(name), age(age){}

        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }
};

class Singer : public Performer {
    private:
        string vocalRange;
    public:
        Singer(string name, int age, string vocalRange): Performer(name, age), vocalRange(vocalRange) {}

        string getVocalRange(){
            return vocalRange;
        }

        void display(){
            cout << getName() << " is a singer, age " << getAge() << " and has a vocal range of " << getVocalRange() << endl;
        }
};

class Dancer : public Performer {
    private:
        string danceStyle;
    public:
        Dancer(string name, int age, string danceStyle): Performer(name, age), danceStyle(danceStyle) {}

        string getDanceStyle(){
            return danceStyle;
        }

        void dancerDisplay(){
            cout << getName() << " is a dancer, age " << getAge() << " and has a dance style of " << getDanceStyle() << endl;
        }
};

int main() {
    int choice;
    cout << "What are you? 1. Singer 2. Dancer: ";
    cin >> choice;

    if (choice == 1) {
        string name, vocalRange;
        int age;
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Vocal Range: ";
        cin >> vocalRange;

        Singer s(name, age, vocalRange);
        s.display();
    } else if (choice == 2) {
        string name, danceStyle;
        int age;
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Dance Style: ";
        cin >> danceStyle;

        Dancer d(name, age, danceStyle);
        d.dancerDisplay();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
