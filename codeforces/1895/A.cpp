#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, k, result;
        cin >> x >> y >> k;  
        int diff = abs(x - y);

        if (x == y) {
            result = x;
        } else if (x > y) {
            result = x;
        } else {
            if (k < diff) {
                result = x + k + 2 * (y - k - x);
            } else {
                result = y;
            }
        }
        cout << result << endl;
    }
    return 0;
}
