// Time: O(n)
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s, int start, int end) { 
    if (start >= end) {
        return true;
    } 
    if (s[start] == s[end]) {
        return isPalindrome(s, start+1, end-1);
    }
    else {
        return false;
    }
}

int main() {
    string word;
    cin >> word;
    if (isPalindrome(word, 0, word.length()-1)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
