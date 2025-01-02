#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int max_joy = -1e9; // Initialize max_joy to a very small value

    for (int i = 0; i < n; ++i) {
        int f, t;
        cin >> f >> t;

        int joy;
        if (t > k) {
            joy = f - (t - k);
        } else {
            joy = f;
        }

        max_joy = max(max_joy, joy);
    }

    cout << max_joy << endl;

    return 0;
}
