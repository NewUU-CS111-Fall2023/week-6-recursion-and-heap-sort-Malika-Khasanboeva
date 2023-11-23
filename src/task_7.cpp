// Time: O(n)

#include <iostream>
using namespace std;

int reverseDigits(int n, int result) {
    if (n == 0) {
        return result;
    }
    int digit = n % 10;
    result = result * 10 + digit;
    return reverseDigits(n / 10, result);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int reversedNumber = reverseDigits(n, 0);
    cout << "Reversed number: " << reversedNumber << endl;
    return 0;
}
