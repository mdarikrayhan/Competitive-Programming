#include <iostream>
 
using namespace std;
 
int main() {
    float a1, b1, c1, a2, b2, c2, t1 = 0, t2 = 0;
    cin >> a1 >> b1 >> c1>> a2 >> b2 >> c2;
    if (a1 == 0 && b1 == 0 && c1 == 0) {
        t1 = 1;
    }
    else if (a1 == 0 && b1 == 0 && c1 != 0) {
        t1 = -1;
    }
    else {
        t1 = 0;
    }
    if (a2 == 0 && b2 == 0 && c2 == 0) {
        t2 = 1;
    }
    else if (a2 == 0 && b2 == 0 && c2 != 0) {
        t2 = -1;
    }
    else {
        t2 = 0;
    }
    if (t1 > t2) {
        int gk = t1;
        t1 = t2;
        t2 = gk;
    }
    
    if (t1 == -1) {
        cout << 0;
    }
    else if (t1 == 0 && t2 == 1) {
        cout << -1;
    }
    else if (t1 == 1 && t2 == 1) {
        cout << -1;
    }
    else if (t1 == 0 && t2 == 0) {
        if ((b1 == 0) && (b2 == 0)) {
            if (c1 / a1 == c2 / a2) {
                cout << -1;
            }
            else {
                cout << 0;
            }
        }
        else if ((a1 == 0) && (a2 == 0)) {
            if (c1 / b1 == c2 / b2) {
                cout << -1;
            }
            else {
                cout << 0;
            }
        }
        else if ((a1 / b1 == a2 / b2) && ((c1 / c2 == a1 / a2) || (c1 == 0 && c2 == 0))) {
            cout << -1;
        }
        else if (a1 / b1 == a2 / b2) {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
}