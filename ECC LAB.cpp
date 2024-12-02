#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to extract a numeric value from the string
double extractNumeric(const string &input) {
    bool decimalFound = false;
    bool signFound = false;
    bool isValid = true;
    double result = 0.0;
    double fractionalPart = 0.0;
    double fractionDivider = 10.0;

    for (size_t i = 0; i < input.length(); ++i) {
        char ch = input[i];

        // Check for a valid sign at the beginning
        if (i == 0 && (ch == '+' || ch == '-')) {
            signFound = true;
            if (ch == '-') result = -result;
            continue;
        }

        // Check for valid digits
        if (isdigit(ch)) {
            if (decimalFound) {
                fractionalPart += (ch - '0') / fractionDivider;
                fractionDivider *= 10;
            } else {
                result = result * 10 + (ch - '0');
            }
        }
        // Check for valid decimal point
        else if (ch == '.' && !decimalFound) {
            decimalFound = true;
        } else {
            isValid = false;
            break;
        }
    }

    // Final result calculation
    if (!isValid) return -999999.99;
    if (result < 0) return result - fractionalPart;
    return result + fractionalPart;
}

int main() {
    string input;

    cout << "Enter a string (type 'END' to quit): " << endl;
    while (true) {
        getline(cin, input);

        if (input == "END") break;

        double extractedValue = extractNumeric(input);

        if (extractedValue == -999999.99) {
            cout << "The input is invalid." << endl;
        } else {
            cout << "The input is: " << fixed << setprecision(4) << extractedValue << endl;
        }
    }

    return 0;
}