
#include <bits/stdc++.h>
#define LL long long
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

#ifdef LOCAL
void debug(){cerr << "\n";}
template<class T, class ... U>
void debug(T a, U ... b){cerr << a << " ", debug(b...);}
template<class T> void pary(T l, T r){
    while (l!=r) cerr << *l << " ", l++;
    cerr << "\n";
}
#else
#define debug(...) void()
#define pary(...) void()
#endif

const LL MAX_N = 5e5+10;
const LL INF = 2e18;

int a;
string b;

void solve1(){

    // input
    cin >> a >> b;

    // process
    reverse(b.begin(), b.end());
    a += atoi(b.c_str());

    cerr << "test: " << atoi(b.c_str()) << "\n";

    // output
    cout << a << "\n";

    return;
}

signed main(){

    fastio;

    int t = 1;
    while (t--){
        solve1();
    }

    return 0;
}
