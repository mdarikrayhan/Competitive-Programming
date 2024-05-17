#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define el cout << '\n'
#define mod 1000000007
#define infinity 99999999999999
#define MAXN 1000001
#define max_k 1000000
#define size 12


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8
void print() {
    cout << "\n";
}

void print(string s) {
    cout << s << '\n';
}

void print(int a) {
    cout << a << '\n';
}

void print(pair<int, int> p) {
    cout << "(" << p.first << ", " << p.second << ")";
}

void print(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

void print(bool A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

void print(const vector<int> &v) {
    for (int x: v) {
        cout << x << ' ';
    }
    cout << '\n';
}

void print(const vector<vector<int>> &v) {
    for (const auto &x: v) {
        print(x);
    }
}

void print(const vector<pair<int, int>> &v) {
    for (auto it: v) {
        print(it);
        cout << ' ';
    }
    cout << "\n";
}

void print(const map<int, int> &mp) {
    cout << "{";
    for (auto it: mp) cout << it.first << ": " << it.second << ", ";
    cout << "}\n";
}

void print(pair<int, int> A[], int N) {
    range(i, 0, N) {
        cout << "(" << A[i].first << ", " << A[i].second << ") ";
    }
    cout << '\n';
}

void print(const multiset<int> &st) {
    for (int i: st) cout << i << ' ';
    cout << '\n';
}

void print(const set<int> &st) {
    for (int i: st) cout << i << ' ';
    cout << '\n';
}

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int array_sum(int A[], int n) {
    int ans = 0;
    range(i, 0, n) ans += A[i];
    return ans;
}

int minimum(int A[], int n) {
    int mn_ = A[0];
    range(i, 1, n) mn_ = min(mn_, A[i]);
    return mn_;
}

int maximum(int A[], int n) {
    int mx_ = A[0];
    range(i, 1, n) mx_ = max(mx_, A[i]);
    return mx_;
}

int just_greater_power_of_2(int x) {
    int po = 1;
    while (po < x) po *= 2;
    return po;
}

long long multiply_mod(long long a, long long b) {
    long long res = 0;
    a %= mod;
    while (b) {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;

        b >>= 1;
    }
    return res;
}






void solve2(){
    string s;
    cin >> s;

    vector<int> l, r;
    int idx = 1;
    for(char c: s){
        if (c == 'l'){
            l.push_back(idx++);
        }else{
            r.push_back(idx++);
        }
    }

    reverse(l.begin(), l.end());
    for(int x: r){
        print(x);
    }
    for(int x: l){
        print(x);
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


#ifndef ONLINE_JUDGE

    freopen("../input.txt", "r", stdin);

    freopen("../output.txt", "w", stdout);

#endif


    int T = 1;

//    cin >> T;

    while (T--) {
        solve2();
    }


    return 0;
}