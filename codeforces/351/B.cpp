#include <iostream>
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> pbds;

using namespace std;


#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
//#define mod 998244353
//#define infinity LONG_LONG_MAX
#define infinity 9999999999999999
#define yes "yes"
#define no "no"
#define No "No"
#define Yes "Yes"
#define YES "YES"
#define NO "NO"
#define ten_6 1000000
#define all(x) x.begin(), x.end()

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
    cout << "(" << p.first << ", " << p.second << ") ";
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

int add(vector<int> v) {
    int ans = 0;
    for (int x: v) ans += x;
    return ans;
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


int vector_sum(vector<int> v) {
    int ans = 0;
    for (int p: v) ans += p;
    return ans;
}

//int n, m, k;
vector<int> arr;
set<int> *adj;


struct SegmentTree {
    int n;
    vector<int> values;
    int *tree;
    int IDENTITY = 0;


    SegmentTree(vector<int> vals) {
        n = (int) vals.size();
        tree = new int[4 * n];
        values = vals;
        build(1, 0, n - 1);
    }

private:
    int f(int a, int b) {
        return a + b;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = values[start];
            return;
        }
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
    }


    void update_helper(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx >= start && idx <= mid) update_helper(node * 2, start, mid, idx, val);
        else update_helper(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
    }

    int query_helper(int node, int l, int r, int query_low, int query_high) {
        if (query_low <= l && r <= query_high) return tree[node];
        if (r < query_low || query_high < l) return IDENTITY;
        int mid = (l + r) / 2;
        return f(query_helper(2 * node, l, mid, query_low, query_high),
                 query_helper(2 * node + 1, mid + 1, r, query_low, query_high));
    }

public:

    int query(int from, int to) {
        return query_helper(1, 0, n - 1, from, to);
    }


    void update(int idx, int val) {
        update_helper(1, 0, n - 1, idx, val);
    }
};


void solve() {

    int n = chut();
    arr = read_vector(n);

    int inv = 0;
    range(i, 0, n) {
        range(j, i + 1, n) {
            if (arr[i] > arr[j]) {
                inv += 1;
            }

        }
    }
//    print(inv);
    int t = inv;
    print(t / 2 * 4 + (t & 1));

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

////
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

//    freopen("milkorder.in", "r", stdin);
//    freopen("milkorder.out", "w", stdout);

//    sieve(200001);
    int T = 1;

//    cin >> T;


    while (T--) {
        solve();
    }


    return 0;
}
