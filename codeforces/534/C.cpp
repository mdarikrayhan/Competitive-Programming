#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;


#define ll  long long
#define db  long double
#define sz(x) (int)x.size()

void _3zzat() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << __LINE__ << ": [", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__)
#define dbgArr(arr, n) cerr << __LINE__ << ": [", _DEBUG_UTIL_::printerArr(#arr, arr, n)
#else
#define dbg(x...)
#define dbgArr(arr, n)
#endif
namespace _DEBUG_UTIL_ {
    void print(const char *x) {}

    void print(bool x) { cerr << (x ? "T" : "F"); }

    void print(char x) { cerr << '\'' << x << '\''; }

    void print(signed short int x) { cerr << x; }

    void print(unsigned short int x) { cerr << x; }

    void print(signed int x) { cerr << x; }

    void print(unsigned int x) { cerr << x; }

    void print(signed long int x) { cerr << x; }

    void print(unsigned long int x) { cerr << x; }

    void print(signed long long int x) { cerr << x; }

    void print(unsigned long long int x) { cerr << x; }

    void print(float x) { cerr << x; }

    void print(double x) { cerr << x; }

    void print(long double x) { cerr << x; }

    void print(string x) { cerr << '\"' << x << '\"'; }

    template<size_t N>
    void print(bitset<N> x) { cerr << x; }

    void print(vector<bool> x) {
        int f = 0;
        cerr << '{';
        for (bool i: x) {
            cerr << (f++ ? "," : "");
            cerr << (i ? "T" : "F");
        }
        cerr << "}";
    } /* Template Datatypes Declarations */ template<typename T>
    void print(T x);

    template<typename T>
    void print(vector<vector<T>> mat);

    template<typename T, size_t N>
    void print(T (&arr)[N]);

    template<typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);

    template<typename F, typename S>
    void print(pair<F, S> x);

    template<typename T>
    void print(priority_queue<T> pq);

    template<typename T>
    void print(priority_queue<T, vector<T>, greater<T>> pq);

    template<typename T>
    void print(stack<T> st);

    template<typename T>
    void print(queue<T> q); /* Template Datatypes Definitions */ template<typename T>
    void print(T x) {
        int f = 0;
        cerr << '{';
        for (auto i: x) cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }

    template<typename T>
    void print(vector<vector<T>> mat) {
        int f = 0;
        cerr << "{\n";
        for (auto i: mat) cerr << (f++ ? ",\n" : ""), print(i);
        cerr << "}\n";
    }

    template<typename T, size_t N>
    void print(T (&arr)[N]) {
        int f = 0;
        cerr << '{';
        for (auto &i: arr) cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }

    template<typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]) {
        int f = 0;
        cerr << "{\n";
        for (auto &i: mat) cerr << (f++ ? ",\n" : ""), print(i);
        cerr << "}\n";
    }

    template<typename F, typename S>
    void print(pair<F, S> x) {
        cerr << '(';
        print(x.first);
        cerr << ',';
        print(x.second);
        cerr << ')';
    }

    template<typename T>
    void print(priority_queue<T> pq) {
        int f = 0;
        cerr << '{';
        while (!pq.empty()) cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }

    template<typename T>
    void print(priority_queue<T, vector<T>, greater<T>> pq) {
        int f = 0;
        cerr << '{';
        while (!pq.empty()) cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }

    template<typename T>
    void print(stack<T> st) {
        int f = 0;
        cerr << '{';
        while (!st.empty()) cerr << (f++ ? "," : ""), print(st.top()), st.pop();
        cerr << "}";
    }

    template<typename T>
    void print(queue<T> q) {
        int f = 0;
        cerr << '{';
        while (!q.empty()) cerr << (f++ ? "," : ""), print(q.front()), q.pop();
        cerr << "}";
    } /* Printer */ template<typename T>
    void printer(const char *name, T &&head) {
        cerr << name << " = ";
        print(head);
        cerr << "]\n";
    }

    template<typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail) {
        int bracket = 0, i = 0;
        while (names[i] != ',' or bracket != 0) {
            if (names[i] == '(') bracket++; else if (names[i] == ')') bracket--;
            i++;
        }
        cerr.write(names, i) << " = ";
        print(head);
        cerr << " ||";
        printer(names + i + 1, tail...);
    } /* PrinterArr */ template<typename T>
    void printerArr(const char *name, T arr[], int N) {
        cerr << name << " : {";
        for (int i = 0; i < N; i++) { cerr << (i ? "," : ""), print(arr[i]); }
        cerr << "}]\n";
    }
}

using namespace __gnu_pbds;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
istream &operator>>(istream &input, vector<T> &data) {
    for (T &x: data)
        input >> x;
    return input;
}

template<typename T>
ostream &operator<<(ostream &output, const vector<T> &data) {
    for (const T &x: data)
        output << x << " ";
    return output;
}

int dx8[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy8[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string dir = "RLDU";
const ll N = 1e6 + 2, M = 900 + 2, MOD = 1e9 + 7, inf = 3e18, inf2 = 1e9;


void code() {
    ll n, x, sum = 0;
    cin >> n >> x;
    vector<ll> v(n);
    for (auto &i: v)cin >> i, sum += i;
    for (int i = 0; i < n; ++i) {
        ll dlim, uplim;
        dlim = max(1LL, x - (sum - v[i]));
        uplim = min(v[i], x - (n - 1));
        cout << (dlim - 1) + (v[i] - uplim)<<' ';
    }

}


signed main() {
    _3zzat();

    int tes = 1;
    //cin >> tes;
    for (int i = 1; i <= tes; ++i) {
        code();
    }

}