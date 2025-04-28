#include <iostream>
#include <iomanip>
using namespace std;

class Beverage {
private:
    string name;
    int volume;
    bool isChilled;

public:
    Beverage(string name, int volume, bool isChilled) : name(name), volume(volume), isChilled(isChilled) {}

    string getName() {
        return name;
    }

    int getVolume() {
        return volume;
    }

    bool getIsChilled() {
        return isChilled;
    }

    string toString() {
        string result = name + " (" + to_string(volume) + "mL) ";
        result += (isChilled ? "is still chilled" : "is not chilled anymore");
        return result;
    }
};

class Water : public Beverage {
private:
    string type;

public:
    Water(int volume, bool isChilled, string type) : Beverage("Water", volume, isChilled), type(type) {}

    Water(int volume, bool isChilled) : Beverage("Water", volume, isChilled) {
        type = "Regular";
    }

    string getType() {
        return type;
    }

    void display() {
        cout << toString() << " [" << getType() << "]" << endl;
    }
};

class Beer : public Beverage {
private:
    double alcoholicContent;

public:
    Beer(int volume, bool isChilled, double alcoholicContent) : Beverage("Beer", volume, isChilled), alcoholicContent(alcoholicContent) {}

    double getAlcoholicContent() {
        return alcoholicContent;
    }

    string getType() {
        if (alcoholicContent < 0.03) {
            return "Flavored";
        } else if (alcoholicContent < 0.06) {
            return "Regular";
        } else {
            return "Strong";
        }
    }

    void display() {
        cout << fixed << setprecision(1);
        cout << toString() << " (" << alcoholicContent * 100 << "% alcoholic content) [" << getType() << "]" << endl;
    }
};

int main() {
    // Input Water
    int waterVolume;
    string chilledInput, specifyTypeInput, waterType;
    bool isWaterChilled;

    cout << "Enter water volume (mL): ";
    cin >> waterVolume;
    cout << "Is the water chilled? (yes/no): ";
    cin >> chilledInput;
    isWaterChilled = (chilledInput == "yes" || chilledInput == "Yes");

    cout << "Do you want to specify water type? (yes/no): ";
    cin >> specifyTypeInput;

    Water water = (specifyTypeInput == "yes" || specifyTypeInput == "Yes") ?
        Water(waterVolume, isWaterChilled, (cout << "Enter water type (Purified, Regular, Distilled): ", cin >> waterType, waterType))
        : Water(waterVolume, isWaterChilled);

    cout << endl << "Water Details:" << endl;
    water.display();

    // Input Beer
    int beerVolume;
    string beerChilledInput;
    bool isBeerChilled;
    double alcoholContent;

    cout << endl << "Enter beer volume (mL): ";
    cin >> beerVolume;
    cout << "Is the beer chilled? (yes/no): ";
    cin >> beerChilledInput;
    isBeerChilled = (beerChilledInput == "yes" || beerChilledInput == "Yes");

    cout << "Enter alcohol content (e.g., 0.045 for 4.5%): ";
    cin >> alcoholContent;

    Beer beer(beerVolume, isBeerChilled, alcoholContent);

    cout << endl << "Beer Details:" << endl;
    beer.display();

    return 0;
}
