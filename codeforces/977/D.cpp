#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define clr(x,val) memset((x),(val),sizeof(x)) 
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }
ll Ceil(ll a, ll b) { return (a + (b - 1)) / b; }
void hhh() {//freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
}
int dx[] = { 0,0,-1,1,-1,1,-1,1 };
int dy[] = { 1,-1,0,0,-1,-1,1,1 };
bool getBit(ll num, int idx) { return ((num >> idx) & 1); }
ll setBit(ll num, int idx, bool val) { return val ? (num | (1LL << idx)) : (num & ~(1LL << idx)); }
ll flipBit(ll num, int idx) { return (num ^ (1LL << idx)); }
ll count_ones(ll n) { ll cnt = 0; while (n) { cnt++, n &= n - 1; }return cnt; }
int n, k; vector<ll>v,ans;
map<ll, ll>ma;
void solve(int i, vector<ll>t) {
    if (i == n) {
        vector<ll >ve = t;
        sort(ve.begin(), ve.end());
        if (ve == v) {
            ans = t;
        }
        return;
    }
    if (t.back() % 3 == 0) {
        ll x = t.back() / 3;
        if (ma[x]) {
            t.push_back(x);
            solve(i + 1, t);
            t.pop_back();
        }
    }
    if (ma[t.back() * 2]) {
        t.push_back(t.back() * 2);
        solve(i + 1, t);
        t.pop_back();
    }
}
int main() {
    hhh();
    cin >> n;
    v = vector<ll>(n); for (auto& it : v)cin >> it,ma[it]++;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        vector<ll>t;
        t.push_back(v[i]);
        solve(1, t);
        if (ans.size()==n) {
            for (auto& it : ans)cout << it << " ";
            break;
        }
    }
    return 0;
}