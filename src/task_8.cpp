// Time: O(n^log3)

#include <iostream>
#include <string>
using namespace std;

string addZeros(string num, int zeros) {
    for (int i = 0; i < zeros; i++) {
        num += "0";
    }
    return num;
}

string removeLeadingZeros(string num) {
    int i = 0;
    while (num[i] == '0') {
        i++;
    }
    return num.substr(i);
}

string add(string num1, string num2) {
    int carry = 0;
    string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result = to_string(sum % 10) + result;
        carry = sum / 10;
        i--;
        j--;
    }
    return result;
}

string subtract(string num1, string num2) {
    string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int borrow = 0;
    while (i >= 0) {
        int digit1 = num1[i] - '0';
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = to_string(diff) + result;
        i--;
        j--;
    }
    return removeLeadingZeros(result);
}

string multiply(string num1, string num2) {
    if (num1.length() == 1 || num2.length() == 1) {
        return to_string(stoi(num1) * stoi(num2));
    }
    int n = max(num1.length(), num2.length());
    int m = n / 2;

    string a = num1.substr(0, num1.length() - m);
    string b = num1.substr(num1.length() - m);
    string c = num2.substr(0, num2.length() - m);
    string d = num2.substr(num2.length() - m);

    string ac = multiply(a, c);
    string bd = multiply(b, d);
    string ab_cd = multiply(add(a, b), add(c, d));
    string ad_bc = subtract(ab_cd, add(ac, bd));

    return add(addZeros(ac, 2 * m), addZeros(ad_bc, m), bd);
}

int main() {
    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    string result = multiply(num1, num2);
    cout << "Product: " << result << endl;

    return 0;
}
