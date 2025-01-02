#ifndef ONLINE_JUDGE
#include"debugger.h"
#endif
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define mod 1000000007
const int inf = 9e18;
const int N = 1e5+10;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(2); cout.setf(ios::fixed,ios::floatfield);

void solve(int cx) {
    int a, b;
    set<int> s;
    cin >> a >> b;
    int cnt = 0;
    while (a) {
        cnt++;
        s.insert(a%b);
        a/= b;
    }
    if (cnt == s.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int tc = 0;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (tc){int t;cin>>t;for(int i=1;i<=t;i++)solve(i);}
    else solve(0);
    return 0;
}