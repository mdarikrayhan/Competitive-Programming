//Syru
#include<bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {return rng() % (r - l + 1) + l;}
template<class T>
bool minimize(T &x, T y) {if(x > y) {x = y;return true;}return false;}
template<class T>
bool maximize(T &x, T y) {if(x < y) {x = y;return true;}return false;}
void copy_file(string f1, string f2) {ifstream fi(f1);ofstream fo(f2);string s;while(getline(fi, s))fo << s << endl;}
#define PROB "d"
void file() {if(fopen(PROB".inp", "r")) {freopen(PROB".inp", "r", stdin);freopen(PROB".out", "w", stdout);}ios_base::sync_with_stdio(false);cin.tie(0);}

int a, b, k;
bool prime[50005];

void read() {
    cin >> a >> b >> k;
}

bool check(int k) {
    for(int i = 2; i * i <= k; ++i)
        if(k % i == 0)
            return false;
    return true;
}

int calc(int n, int k) {
    if(k > n)
        return 0;
    if(1LL * k * k > n)
        return 1;
    n /= k;
    int res = n;
    for(int i = 2; i < k; ++i)
        if(prime[i])
            res -= calc(n, i);
    return res;
}

void solve() {
    if(!check(k)) {
        cout << 0;
        return;
    }
    fill(prime + 2, prime + 50001, true);
    for(int i = 2; i * i <= 50000; ++i)
        if(prime[i])
            for(int j = i * i; j <= 50000; j += i)
                prime[j] = false;
    cout << calc(b, k) - calc(a - 1, k);
}

int main() {
    file();
    read();
    solve();
}