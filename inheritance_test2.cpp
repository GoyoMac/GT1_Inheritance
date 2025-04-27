#include <iostream>
#include <iomanip>
using namespace std;

// Base Class
class Number {
private:
    int rawValue;

public:
    Number(int rawValue) {
        this->rawValue = rawValue;
    }

    int getRawValue() {
        return rawValue;
    }

    void setRawValue(int value) {
        rawValue = value;
    }
};

// Subclass - WholeNumber
class WholeNumber : public Number {
public:
    WholeNumber(int value) : Number(value) {}

    void multiply(WholeNumber otherWhole) {
        setRawValue(getRawValue() * otherWhole.getRawValue());
    }

    string toString() {
        return to_string(getRawValue());
    }
};

// Subclass - DecimalNumber
class DecimalNumber : public Number {
private:
    int decimalPlaces;

public:
    DecimalNumber(int value, int decimalPlaces) : Number(value) {
        this->decimalPlaces = decimalPlaces;
    }

    int getDecimalPlaces() {
        return decimalPlaces;
    }

    void setDecimalPlaces(int places) {
        decimalPlaces = places;
    }

    void multiply(DecimalNumber decimalNumber) {
        setRawValue(getRawValue() * decimalNumber.getRawValue());
        setDecimalPlaces(decimalPlaces + decimalNumber.getDecimalPlaces());
    }

    string toString() {
        double value = getRawValue();
        for (int i = 0; i < decimalPlaces; i++) {
            value /= 10.0;
        }

        // Using C++ iomanip for formatting
        cout << fixed << setprecision(decimalPlaces);
        return to_string(value);
    }
};

// Main Function
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
    cout << "WholeNumber Result (Multiplication): " << w1.toString() << endl << endl;

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

    // Output decimal result
    double result = d1.getRawValue();
    int totalDecimalPlaces = d1.getDecimalPlaces();
    for (int i = 0; i < totalDecimalPlaces; i++) {
        result /= 10.0;
    }

    cout << fixed << setprecision(totalDecimalPlaces);
    cout << "DecimalNumber Result (Multiplication): " << result << endl;

    return 0;
}
