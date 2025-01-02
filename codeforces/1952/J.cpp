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

void solve(int cx) {
    int t; cin >> t;
    if(t == 1) {
        cout << "yoink a\n"
                "yoink b\n"
                "*slaps a on top of b*\n"
                "yeet b\n"
                "go touch some grass\n";
    } else if (t == 2) {
        cout << "yoink a\n"
                "bruh b is lowkey just 0\n"
                "rip this b fell off by a\n"
                "vibe check a ratios b\n"
                "simp for 7\n"
                "bruh a is lowkey just b\n"
                "yeet a\n"
                "go touch some grass\n";
    } else if (t == 3) {
        cout << "yoink n\n"
                "yoink a\n"
                "bruh m is lowkey just a[0]\n"
                "bruh i is lowkey just 1\n"
                "vibe check n ratios i\n"
                "simp for 9\n"
                "yeet m\n"
                "go touch some grass\n"
                "vibe check a[i] ratios m\n"
                "bruh m is lowkey just a[i]\n"
                "*slaps 1 on top of i*\n"
                "simp for 5\n";
    } else {
        cout << "yoink n\n"
                "yoink a\n"
                "yoink k\n"
                "bruh i is lowkey just 0\n"
                "vibe check n ratios i\n"
                "simp for 11\n"
                "bruh x is lowkey just n\n"
                "rip this x fell off by k\n"
                "yeet a[x]\n"
                "go touch some grass\n"
                "bruh j is lowkey just 1\n"
                "vibe check n ratios j\n"
                "simp for 16\n"
                "*slaps 1 on top of i*\n"
                "simp for 5\n"
                "bruh y is lowkey just j\n"
                "rip this y fell off by 1\n"
                "vibe check a[y] ratios a[j]\n"
                "simp for 22\n"
                "*slaps 1 on top of j*\n"
                "simp for 12\n"
                "bruh tmp is lowkey just a[y]\n"
                "bruh a[y] is lowkey just a[j]\n"
                "bruh a[j] is lowkey just tmp\n"
                "simp for 20\n";
    }
}

int tc = 0;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (tc){int t;cin>>t;for(int i=1;i<=t;i++)solve(i);}
    else solve(0);
    return 0;
}
