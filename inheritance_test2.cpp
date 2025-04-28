#include <iostream>
#include <iomanip>
using namespace std;

class Number {
private:
    int rawValue;

public:
    Number(int rawValue) : rawValue(rawValue) {}

    int getRawValue() {
        return rawValue;
    }

    void setRawValue(int value) {
        rawValue = value;
    }
};

class WholeNumber : public Number {
public:
    WholeNumber(int value) : Number(value) {}

    void multiply(WholeNumber otherWhole) {
        setRawValue(getRawValue() * otherWhole.getRawValue());
    }

    string toString() {
        return "WholeNumber Result (Multiplication): " + to_string(getRawValue());
    }

    void display() {
        cout << toString() << endl;
    }
};

class DecimalNumber : public Number {
private:
    int decimalPlaces;

public:
    DecimalNumber(int value, int decimalPlaces) : Number(value), decimalPlaces(decimalPlaces) {}

    int getDecimalPlaces() {
        return decimalPlaces;
    }

    void setDecimalPlaces(int places) {
        decimalPlaces = places;
    }

    void multiply(DecimalNumber otherDecimal) {
        setRawValue(getRawValue() * otherDecimal.getRawValue());
        setDecimalPlaces(decimalPlaces + otherDecimal.getDecimalPlaces());
    }

    string toString() {
        double result = getRawValue();
        for (int i = 0; i < decimalPlaces; i++) {
            result /= 10.0;
        }
        cout << fixed << setprecision(decimalPlaces);
        return "DecimalNumber Result (Multiplication): " + to_string(result);
    }

    void display() {
        cout << toString() << endl;
    }
};

int main() {
    // Whole Number Multiplication
    int firstWhole, secondWhole;
    cout << "Enter first whole number: ";
    cin >> firstWhole;
    cout << "Enter second whole number: ";
    cin >> secondWhole;

    WholeNumber w1(firstWhole);
    WholeNumber w2(secondWhole);

    w1.multiply(w2);
    w1.display();

    cout << endl;

    // Decimal Number Multiplication
    int firstDecimalRaw, firstDecimalPlaces;
    int secondDecimalRaw, secondDecimalPlaces;

    cout << "Enter first decimal number's raw value (e.g. 125 for 1.25): ";
    cin >> firstDecimalRaw;
    cout << "Enter number of decimal places for first decimal: ";
    cin >> firstDecimalPlaces;

    cout << "Enter second decimal number's raw value (e.g. 20 for 0.20): ";
    cin >> secondDecimalRaw;
    cout << "Enter number of decimal places for second decimal: ";
    cin >> secondDecimalPlaces;

    DecimalNumber d1(firstDecimalRaw, firstDecimalPlaces);
    DecimalNumber d2(secondDecimalRaw, secondDecimalPlaces);

    d1.multiply(d2);
    d1.display();

    return 0;
}
