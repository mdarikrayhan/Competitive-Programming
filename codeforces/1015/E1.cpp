#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl "\n"
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int modi = 1e9 + 7, n, m;


void solve() {
    cin >> n >> m;
    string arr[n + 2];
    string st = "";
    for (int i(0); i < m + 2; i++) st += '.';
    arr[0] = st; arr[n + 1] = st;
    for (int i(1); i <= n; i++) {
        string pt = ".";
        string at; cin >> at;
        pt += at; pt += '.';
        arr[i] = pt;
    }
    string brr[n + 2];
    vector<vector<int>> vec;
    for (int i(0); i < n + 2; i++) brr[i] = st;
    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            if (arr[i][j] == '*' && arr[i - 1][j] == '*' && arr[i + 1][j] == '*' && arr[i][j - 1] == '*' && arr[i][j + 1] == '*') {
                int sz = 0;

                while (true) {
                    if (arr[i][j] == '*' && arr[i - sz - 1][j] == '*' && arr[i + sz + 1][j] == '*' && arr[i][j - sz - 1] == '*' && arr[i][j + sz + 1] == '*') {
                        sz++;
                    }
                    else break;

                }
                vector<int> vc;
                vc.pb(i), vc.pb(j), vc.pb(sz);
                vec.push_back(vc);
            }
        }
    }

    for (auto e : vec) {
        int xc = e[0], yc = e[1], lambai = e[2];
        brr[xc][yc] = '*';
        for (int i(1); i <= lambai; i++) {
            brr[xc - i][yc] = '*';
            brr[xc + i][yc] = '*';
            brr[xc][yc - i] = '*';
            brr[xc][yc + i] = '*';
        }



    }

    bool flagu = 1;
    for (int i(0); i <= n + 1; i++) {
        if (arr[i] != brr[i]) {flagu = 0; break;}
    }

    if (!flagu) cout << -1;
    else {
        cout << vec.size() << endl;
        for (auto e : vec) {
            for (auto f : e) cout << f << " "; cout << endl;
        }
    }


}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin) ;
    freopen("outp.txt", "w", stdout);
#endif
    solve();

}