#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    float r, g, b;
    cin >> r >> g >> b;
    int time = 30;
    while (r > 0 || g > 0 || b > 0) {
        if (r > 0) {
            r -= 2;
            if (r <= 0 && g <= 0 && b <= 0) {
                break;
            }
        }
        time += 1;
        if (g > 0) {
            g -= 2;
            if (r <= 0 && g <= 0 && b <= 0) {
                break;
            }
        }
        time += 1;
        if (b > 0) {
            b -= 2;
            if (r <= 0 && g <= 0 && b <= 0) {
                break;
            }
        }
        time += 1;
    }
    cout << time << endl;
    return 0;
}
