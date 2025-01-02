#include <iostream>
using namespace std;

int main() {
    int t, p, q, count = 0;
    
    cin >> t;

    while(t--) {
        cin >> p >> q;
        if((q - p) >= 2) {
            count++;
        }
    }
    cout << count;
}