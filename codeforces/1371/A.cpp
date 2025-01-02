#include <iostream>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int sticks;
        cin >> sticks;
        cout << (sticks + 1) / 2 << endl;
    }
    return 0;
}
