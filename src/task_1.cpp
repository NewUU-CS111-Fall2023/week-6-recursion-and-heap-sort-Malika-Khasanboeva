/*
 * Author:
 * Date:
 * Name:
 */
#include <iostream>
using namespace std;

void printNumbers(int start, int end) {
  if(start == end) { 
    cout << start << " ";
    return;
  }
  cout << start << " ";
  if(start < end) { 
    printNumbers(start+1, end);
  } else { 
    printNumbers(start-1, end);
  }
}

int main() {
  int a, b;
  cin >> a >> b;
  printNumbers(a, b);
  return 0;
}

// Runtime complexity: O(n)
