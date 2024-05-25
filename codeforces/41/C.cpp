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

void NeedForSpeed() {
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

    string str;
    cin >> str;
    string ans;
    bool flag = false;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 't' && str[i - 1] == 'a' && !flag && i != str.size() - 1 && i != 1) {
            flag = true;
            ans.pop_back();
            ans += '@';
        } else if (str[i] == 't' && str[i - 1] == 'o' && str[i - 2] == 'd' && i != str.size() - 1 && i != 2) {
            ans.pop_back();
            ans.pop_back();
            ans += '.';
        } else ans += str[i];
    }
    cout << ans;

}


signed main() {
    NeedForSpeed();
    IO();

    // Node *head = NULL;
    doTask();


}