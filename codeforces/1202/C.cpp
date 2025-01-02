/*
Problem: 1202C
Date: 23-05-2024 07:28 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 2e5 + 5;
int q;
string s;
int pos[MAX_N][2];
int prefmin[MAX_N][2], prefmax[MAX_N][2], sufmin[MAX_N][2], sufmax[MAX_N][2];

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> s;
        int x = 0, y = 0;
        int mx = 0, my = 0, Mx = 0, My = 0;
        int n = s.length();
        prefmin[0][0] = prefmin[0][1] = prefmax[0][0] = prefmax[0][1] = 0;
        pos[0][0] = pos[0][1] = 0;
        for(int i = 0; i < n; i++) {
            x += (s[i] == 'D') - (s[i] == 'A');
            y += (s[i] == 'W') - (s[i] == 'S');
            pos[i + 1][0] = x;
            pos[i + 1][1] = y;
            prefmin[i + 1][0] = mx = min(mx, x);
            prefmin[i + 1][1] = my = min(my, y);
            prefmax[i + 1][0] = Mx = max(Mx, x);
            prefmax[i + 1][1] = My = max(My, y);
        }
        // cout << mx << " " << Mx << " " << my << " " << My << endl;
        ll A = ((ll) (Mx - mx + 1)) * ((ll) (My - my + 1));

        mx = Mx = x, my = My = y;
        for(int i = n; i >= 0; i--) {
            sufmin[i][0] = mx = min(mx, pos[i][0]);
            sufmin[i][1] = my = min(my, pos[i][1]);
            sufmax[i][0] = Mx = max(Mx, pos[i][0]);
            sufmax[i][1] = My = max(My, pos[i][1]);
        }
        for(int i = 1; i < n; i++) {
            A = min(A, ((ll) max(prefmax[i][0], sufmax[i][0] - 1) - min(prefmin[i][0], sufmin[i][0] - 1) + 1) * ((ll) My - my + 1));
            A = min(A, ((ll) max(prefmax[i][0], sufmax[i][0] + 1) - min(prefmin[i][0], sufmin[i][0] + 1) + 1) * ((ll) My - my + 1));
            A = min(A, ((ll) Mx - mx + 1) * ((ll) max(prefmax[i][1], sufmax[i][1] - 1) - min(prefmin[i][1], sufmin[i][1] - 1) + 1));
            A = min(A, ((ll) Mx - mx + 1) * ((ll) max(prefmax[i][1], sufmax[i][1] + 1) - min(prefmin[i][1], sufmin[i][1] + 1) + 1));
        }
        cout << A << endl;
    }
}