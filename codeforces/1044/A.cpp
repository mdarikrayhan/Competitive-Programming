#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <tuple>
#include <numeric>
#include <ctype.h>
#include <fstream>
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;
using ll = long long;
using ld = long double;


ll inf18 = 1e18;
ll inf9 = 1e9;
ll inf6 = 1e6;
ll MOD = 1e9 + 7;
string templ = "qwertyuiopasdfghjklzxcvbnm";

vector<int> abm(vector<int> mask) {
    int n = mask.size();
    int i = n - 1;
    while (i > -1 && mask[i] == 1) {
        i--;
    }
    if (i == -1) {
        return mask;
    }
    else if (i == n - 1) {
        mask[i] = 1;
        return mask;
    }
    else {
        mask[i] = 1;
        i++;
        while (i < n) {
            mask[i] = 0;
            i++;
        }
        return mask;
    }
}

int in(char el, string str) {
    return count(str.begin(), str.end(), el);
}

void dfs(int x, int y) {

}

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> vert;
    vector<ll> hor;
    ll el1,el2,el3;
    for (int i = 0; i < n; i++) {
        cin >> el1;
        vert.pb(el1);
    }
    vert.pb(1e9);
    for (int i = 0; i < m; i++) {
        cin >> el1 >> el2 >> el3;
        if (el1 == 1) {
            hor.pb(el2);
        }
    }
    ll answ = inf9;
    if (m == 0 && n == 0) {
        cout << 0;
        return;
    }
    sort(vert.begin(), vert.end());
    sort(hor.begin(), hor.end());
    int hp = 0, vp = 0;
    m = hor.size();
    while (hp < m && vp <= n) {
        while (hp < m && hor[hp] < vert[vp]) {
            hp++;
        }
        answ = min(answ, m - hp + vp);
        vp++;
    }
    if(answ == inf9){
        cout << 0;
    }
    else {
        cout << answ;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}