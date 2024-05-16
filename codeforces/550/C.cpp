#pragma ide diagnostic ignored "bugprone-branch-clone"
#pragma clang diagnostic ignored "-Wconstant-conversion"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define endl '\n'
#define pii pair<int,int>
#define vc vector<int>
#define vs vector<string>
#define vii vector<vector<int>>
#define vpii vector<pair<int,int>>
#define pb push_back
#define pf push_front
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
const int inf = 2e9;
const ll llinf = 1e18 - 1;
const int N = 3e5 + 5;
const int mod = 1e9 + 7;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int n, m, k;
void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto it : s)mp[it]++;
    if(mp['0']){
        yes();
        cout << 0 <<endl;
        return;
    } else if(mp['8']){
        yes();
        cout << 8 <<endl;
        return;
    } else {
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                int num = (s[i] - '0') * 10 + (s[j] - '0');
                if (num % 8 == 0) {
                    yes();
                    cout << num << endl;
                    return;
                }
            }
        }
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                for (int k = j + 1; k < s.length(); k++) {
                    int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                    if(num % 8 == 0){
                        yes();
                        cout << num << endl;
                        return;
                    }
                }
            }
        }
        no();
    }
}
/*


*/
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    //cin >> _;
    for (int i = 1; i <= _; i++) {
        solve();
    }
    return 0;
}
#pragma clang diagnostic pop
