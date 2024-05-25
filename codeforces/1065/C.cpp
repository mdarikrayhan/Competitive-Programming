#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define all(x) (x).begin(), (x).end()
#define FOR(i, n) for(int i=0;i<n;++i)
#define FOR1(i, n) for(int i=1;i<=n;++i)
#define ceil(a, b) ((a+b-1)/(b))
#define mid(l,r)  (l + (r - l) / 2)
#define MULTI_TEST_CASE 0
const int N = 2e5+10;
int pref[N]{0};
void solve() {
    ll n, k, MaxH = 0, MinH = 2e5+10, temp;
    cin >> n >> k;
    FOR(i,n){
        cin >> temp;
        pref[1]++;
        pref[temp+1]--;
        MaxH = max(MaxH, temp);
        MinH = min(MinH, temp);
    }
    FOR1(i,MaxH){
        pref[i] = pref[i]+pref[i-1];
    }
    ll slices = 0, sum = 0, current;
    for(int i = MaxH; i > MinH; --i){
        current = pref[i];
        sum += current;
        if(sum > k){
            slices++;
            sum = current;
        }
    }
    if(sum){
        slices++;
    }
    cout << slices;
}
int main() {
    IOS
    file();
    clock_t z = clock();
    int testCase = 1;
    if (MULTI_TEST_CASE) cin >> testCase;
    while (testCase--) {
        solve();
    }
    cerr << "Run Time : " << ((double) (clock() - z) / CLOCKS_PER_SEC);
}

  		   		  	 							   				  		