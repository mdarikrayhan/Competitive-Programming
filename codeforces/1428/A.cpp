#include <bits/stdc++.h>
using namespace std;
void test() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << abs(x1 - x2) + abs(y1 - y2) + 2 * (x1 != x2 && y1 != y2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        test();
        cout << "\n";
    }
}