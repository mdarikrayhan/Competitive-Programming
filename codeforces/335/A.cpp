#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<numeric>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<iomanip>
#include<array>
//#include<bits/stdc++.h>
 
#define ll long long
#define double long double
#define str string
#define ins insert
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;

void solve() {
    str s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> v(26,0);
    for (int i=0; i<s.size(); i++) {
        v[s[i]-'a']++;
    } int l=1, r=1e9;
    while (l<r) {
        int mid=(l+r)/2;
        int cnt=0;
        for (int i=0; i<26; i++) {
            cnt+=v[i]/mid;
            cnt+=!(v[i]%mid==0);
        } if (cnt<=n) {
            r=mid;
        } else {
            l=mid+1;
        }
    } if (l==1e9) {
        cout << -1;
    } else {
        cout << l << "\n";
        str ans="";
        int p=0;
        for (int i=0; i<26; i++) {
            if (v[i]!=0) p=i;
            int cnt=v[i]/l;
            cnt+=!(v[i]%l==0);
            for (int j=0; j<cnt; j++) {
                ans+=(char)'a'+i;
            }
        } while (ans.size()!=n) {
            ans+=(char)'a'+p;
        } cout << ans;
    }
}
 
int main() {
    //freopen("moocast.in", "r", stdin);
    //freopen("moocast.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    //cin >> tt;
    while (tt--) {
        //cout << "Case#" << tt <<":\n";
        solve();
    }
    return 0;
}
 
//use setprecision(20) for double baka