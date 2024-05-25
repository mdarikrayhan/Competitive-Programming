#include <iostream>
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
//#define mod 998244353
//#define infinity LONG_LONG_MAX
#define infinity 9999999999999
#define yes "yes"
#define no "no"
#define No "No"
#define Yes "Yes"
#define YES "YES"
#define NO "NO"
#define ten_6 1000000
#define all(x) x.begin(), x.end()
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> pbds;


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8
void print() {
    cout << "\n";
}

void print(string s) {
    cout << s << '\n';
}

void print(double x) {
    cout << x << '\n';
}

void print(int a) {
    cout << a << '\n';
}

void print(pair<int, int> p) {
    cout << "(" << p.first << ", " << p.second << "), ";
}

void print(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

void print(bool A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

void print(const vector<int> &v, int length) {
    for (int x: v) {
        cout << x << ' ';
        length--;
        if (length < 0) break;
    }
    cout << '\n';
}

void print(const vector<int> &v) {
    for (int x: v) cout << x << ' ';
    cout << '\n';
}

void print(const vector<string> &v) {
    for (string x: v) cout << x << '\n';
    cout << "\n\n\n";
}

void print(const vector<bool> &v) {
    for (bool x: v) cout << x << ' ';
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

void print(const unordered_set<int> &st) {
    for (int i: st) cout << i << ' ';
    cout << '\n';
}

void print(queue<int> q) {
    for (size_t i = 0; i < q.size(); i++) {
        cout << q.front() << ' ';
        q.push(q.front());
        q.pop();
    }
    print();
}


void print(map<pair<int, int>, int> mp) {
    cout << "{";
    for (auto it: mp) cout << '(' << it.first.first << ", " << it.first.second << ")" << ": " << it.second << ", ";
    cout << "}\n";
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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
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

int get_digit_sum(int x) {
    int ans = 0;
    while (x) {
        ans += (x % 10);
        x /= 10;
    }
    return ans;
}

int input() {
    int x;
    cin >> x;
    return x;
}

int chut() {
    int x;
    cin >> x;
    return x;
}

string read() {
    string s;
    cin >> s;
    return s;
}

vector<int> read_vector(int len) {
    vector<int> temp(len);
    range(i, 0, len) cin >> temp[i];
    return temp;
}

vector<int> spf;

void sieve(int MAXN) {
    spf.resize(MAXN);
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

int inverse(int x, int p) {
    return power(x, p - 2, p);
}


//int n, m;
//vector<int> arr, cost;
vector<int> *adj;


void solve() {


    int n = chut();
    vector<pair<int, int>> arr(n);


    range(i, 0, n) cin >> arr[i].first;
    range(i, 0, n) cin >> arr[i].second;

    sort(all(arr));

    int suffix[n];
    suffix[n - 1] = arr[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + arr[i].second;
    }
//    print(arr);
//    print(suffix, n);
    int start = 0;

    map<int, int> costs;

    int mn = infinity;


    while (start < n) {
        int end = start;
        while (end + 1 < n and arr[end + 1].first == arr[start].first) {
            end += 1;
        }
        int ans = 0;
        if (end + 1 < n) ans += suffix[end + 1];

        int freq = end - start + 1;
        int total = end + 1;
        int allowed = 2 * freq - 1;
        int to_delete = max((int) 0, total - allowed);

        for(auto it: costs){
            if (to_delete == 0) break;
            int can = min(it.second, to_delete);

            to_delete -= can;
            ans += (can * it.first);
        }




        mn = min(mn, ans);
        range(i, start, end + 1) {
            costs[arr[i].second]++;
        }

        start = end + 1;


    }


    print(mn);

}


int32_t main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);


#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

//    freopen("milkorder.in", "r", stdin);
//    freopen("milkorder.out", "w", stdout);

    int T = 1;

//    cin >> T;


    while (T--) {
        solve();
    }


    return 0;
}
