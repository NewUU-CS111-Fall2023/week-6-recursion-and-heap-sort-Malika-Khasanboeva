// Time: O(n)
#include <iostream>
using namespace std;

void findSecondLargest(int& largest, int& secondLargest) {
    int num;
    cin >> num;
    
    if (num == 0) {
        return;
    }
    
    if (num > largest) {
        secondLargest = largest;
        largest = num;
    } else if (num > secondLargest && num < largest) {
        secondLargest = num;
    }
    
    findSecondLargest(largest, secondLargest);
}

int main() {
    int largest = 0;
    int secondLargest = 0;
    
    findSecondLargest(largest, secondLargest);
    
    cout << secondLargest << endl;
    
    return 0;
}
