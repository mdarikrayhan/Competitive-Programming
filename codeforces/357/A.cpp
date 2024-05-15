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
    int n, a, b;
    cin >> n;
    vi v(n);
    int s = 0;
    for (int &x: v)cin >> x, s += x;
    cin >> a >> b;


    int c = 0;
    for (int i = 0; i < n; i++) {
        c += v[i];
        if(a <= c && c <= b && a <= s - c && s - c <= b){
            cout << i + 2 << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
