#include <bits/stdc++.h>
using namespace std;
                
void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
}

signed main() {
    fastio();
    int arr[8];
    for (int &i : arr)
        i = -1;
    char c;
    char aa[8][8];
    int a = 10, b = 10;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> aa[i][j];
            if (aa[i][j] == 'W') {
                if (arr[j] == -1)
                    a = min(i, a);
            }
            if (aa[i][j] == 'B') {
                arr[j] = i;
            }
        }
    }
    for (int &i : arr)
        i = -1;
    for (int i = 7; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            if (aa[i][j] == 'W') {
                arr[j] = i;
            }
            if (aa[i][j] == 'B') {
                if (arr[j] == -1)
                    b = min(7 - i, b);
            }
        }
    }
    if(a <= b)
        cout << 'A';
    else
        cout << 'B';
}
