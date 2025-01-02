#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<iterator>
#include<list>
#include<unordered_map>
#include<set>
//#include "utility.h"
using namespace std;
//#define int long long
#define ll long long
#define ull unsigned long long
#define all(v) v.begin(), v.end()
#define Rall(v) v.rbegin(), v.rend()
#define L '\n'
#define EPS 1e-9
const ll MOD = 1e9 + 7;

void YF12() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void IO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

template<typename T = int>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v) in >> x;
    return in;
}

template<typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const auto &x: v) {
        out << x << " ";
    }
    return out;
}


void doTask() {
    int n;
    cin >> n;
    int mini = INT_MAX,ans=-1;
    vector<int> v(n);
    cin >> v;
    for (int i = 1; i <= 100; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (abs(v[j] - i) > 1) {
                if (v[j] > i)sum += abs(v[j] - (i + 1));
                else sum += abs(abs(i - 1)-v[j]);
            }
        }
        if (mini>sum){
            mini = sum;
            ans = i;
        }
    }
    cout << ans<<" "<<mini;
}

signed main() {
    YF12();
    IO();
    int t = 1;
//    cin >> t;
    while (t--) {
        doTask();
//        cout << "\n";
    }

}