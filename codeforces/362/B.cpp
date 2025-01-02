//Idk how it works but it works
//¯\_(ツ)_/¯
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <deque>
#include <stdio.h>
#include <string>
#include <numeric>
#include <cstring>
#include <unordered_map>
#include <random>
#include <chrono>
#include <bitset>

using namespace std;

//main define
#define SVap swap
//#define endl "\n"
#define int long long
#define pii pair < int, int >
#define pss pair < string, string >
#define ll long long
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define eb emplace_back
#define pb push_back
#define pf push_front
#define mkp make_pair
#define full(a) a.begin(), a.end()
#define itn int
#define fro for
#define cotu cout
#define INF 0x3F3F3F3F

string Pi = "3141592653589793238462643383279502884197169399375105820974944592307816406";
double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406;
string vowels = "AEIOUY";
string consonants = "BCDFGHJKLMNPQRSTVWXZ";
string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int MOD = 1e9 + 7;

void output(bool fl) {
    if(fl) cy;
    else cn;
}

int __lcm(int a, int b){
    return a / __gcd(a, b) * b;
}

//bool cmp(pair < int, int > a, pair < int, int > b) {
//    if(a.first == b.first) return a.second < b.second;
//    else return a.first > b.first;
//}

int binPow(int n, int k) {
    int res = 1;
    while(k) {
        if(k % 2) {
            res = (res * n) % MOD;
            k--;
        }
        else {
            n = (n * n) % MOD;
            k /= 2;
        }
    }
    return res;
}

bool isPrime(int n) {
    if(n == 1) return 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

// (\___/)
// ( ^W^ )
// / >❤️>

void solve() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    if(m == 0) {
        cy;
        return;
    }
    set < int > st;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
        vector < int > a;
        for(auto &it : st) a.eb(it);
        if(a[0] == 1 || a.back() == n) {
            cn;
            return;
        }
        for(int i = 2; i < a.size(); i++) {
            if(a[i - 2] + 1 == a[i - 1] && a[i - 1] + 1 == a[i]) {
                cn;
                return;
            }
        }
        cy;
}

main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cin.exceptions(ios::badbit | ios::failbit);
    setlocale( LC_ALL, "Ukr" );

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
