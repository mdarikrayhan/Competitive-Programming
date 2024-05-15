#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    cout << 1;
                } else {
                    cout << -1;
                }
                cout << " ";
            }
            cout << endl;
        } else {
            if (n == 3) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                for (int i = 0; i < n; i++) {
                    int m = n / 2;
                    if (i % 2 == 0) {
                        cout << m - 1;
                    } else {
                        cout << -m;
                    }
                    cout << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
