//ZEJU FAN
//21019135
//Assignment 1
//16/08/2023

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Check if the input string represents a binary number
//Thinking: Determine whether it is binary by identifying whether the input characters only include 0 and 1
bool isBinary(const string& Bininput) {
    for (char ch : Bininput) {
        if (ch != '0' && ch != '1') {
            return false;
        }
    }
    return true;
}

// Check if the input string is an 8-bit binary number
bool is8Bit_Binary(const string& str) {
    return str.length() <= 8;
}
CFVV
// Check if the input string has leading zeros
bool hasLeadingZero(const string& str) {
    return str.length() > 1 && str[0] == '0';
}

// Convert binary to decimal
int binaryToDecimal(const string& binaryStr) {
    int decimal = 0;
    int power = 0;

    for (int i = binaryStr.length() - 1; i >= 0; --i) {
        if (binaryStr[i] == '1') {
            decimal += pow(2, power);
        }
        ++power;
    }

    return decimal;
}

// Convert decimal to binary
string decimalToBinary(int decimal) {
    string binaryStr = "";
    while (decimal > 0) {
        binaryStr = to_string(decimal % 2) + binaryStr;
        decimal /= 2;
    }

    // Add leading zeros to make it an 8-bit binary number
    while (binaryStr.length() < 8) {
        binaryStr = "0" + binaryStr;
    }

    // Add spaces every 4 bits
    for (int i = 4; i < binaryStr.length(); i += 5) {
        binaryStr.insert(i, " ");
    }

    return binaryStr;
}

int main() {
    string input;
    cout << "Enter a number : ";
    cin >> input;

    if (isBinary(input)) {
        if (!is8Bit_Binary(input)) {
            cout << "This binary number has more than 8 binary digits." << endl;
        } else if (hasLeadingZero(input)) {
            cout << "Invalid binary number. It must not have leading zeros." << endl;
        } else {
            int decimalNumber = binaryToDecimal(input);
            if (decimalNumber >= 0 && decimalNumber <= 255) {
                cout << "Converting binary to decimal. The result is  " << decimalNumber << endl;
            } else {
                cout << "Invalid binary number. It must be in the range of 8-bit binary numbers (00000000 - 11111111)." << endl;
            }
        }
    } else {
        if (hasLeadingZero(input)) {
            cout << "This is not a valid binary number." << endl;
        } else {
            int decimalValue;
            try {
                decimalValue = stoi(input);
            } catch (const std::invalid_argument&) {
                cout << "This is not a valid number." << endl;
                return 1;
            }

            if (decimalValue >= 0 && decimalValue <= 255) {
                string binaryNumber = decimalToBinary(decimalValue);
                cout << "Converting decimal to binary. The result is  " << binaryNumber << endl;
            } else {
                cout << "This decimal number is outside the range 0 to 255." << endl;
            }
        }
    }

    return 0;
}
