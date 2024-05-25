#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n;
    cin >> n;

    vi a(n), b(n), d(n);
    for (int &x: a)cin >> x;
    for (int &x: b){
        cin >> x, x--;
        if(x>=0)d[x]++;
    }

    vi r;
    for(int i=0;i<n;i++) {
        if (a[i] == 1) {
            int x = i;
            vi t;
            t.pb(x);
            while (b[x] != -1 && a[b[x]] == 0 && d[b[x]] <= 1) {
                x = b[x];
                t.pb(x);
            }
            if (t.size() > r.size())r = t;
        }
    }
    cout << r.size() << endl;
    reverse(r.begin(), r.end());
    for(int x: r)cout << x + 1 << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
