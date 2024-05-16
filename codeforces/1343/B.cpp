#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        if (n % 4 != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            int sum1 = 0, sum2 = 0;
            
            for (int i = 2; i <= n; i += 2) {
                cout << i << " ";
                sum1 += i;
            }
            
            for (int i = 1; i <= n - 2; i += 2) {
                cout << i << " ";
                sum2 += i;
            }
            
            cout <<sum1 - sum2 <<  endl;
        }
    }

    return 0;
}
