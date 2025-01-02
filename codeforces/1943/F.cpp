#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
typedef vector<int> vi;
const int oo = 1e9;
void sgnify(string& s) {
    for(auto& i : s) {
        if(i=='0') i =-1;
        else i =1;
    }
}
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string t; cin >> t;
    sgnify(s),sgnify(t);
    int sum=0;
    for(auto i : t) sum+=i;
    if(sum>0) {
        sum=-sum;
        for(auto& i : s) i=-i;
        for(auto& i : t) i=-i;
    }

    vector<bool> bad(n+1);
    // prefix sums
    vi p(n+1);
    const int LIM = n+2;
    p[0]=LIM;
    for(int i=0;i<n;++i) p[i+1]=t[i]+p[i];
    
    vi pref = p,suf = p;
    for(int i=1;i<=n;++i)  pref[i]=min(pref[i],pref[i-1]);
    for(int i=n-1;i>=0;--i) suf[i]=max(suf[i+1],suf[i]);

    for(int i=0;i<n;++i) if(s[i]==1) bad[i] = pref[i]>suf[i+1];
    bad[n]=1;

    vi firstbad(LIM*2+1,n);
    int at=2*LIM;
    for(int i=0;i<n;++i) if(bad[i]) {
        while(at>p[i+1]) {
            firstbad[at--]=i;
        }
    }
    vi dp(n+1,oo);
    for(int i=0;i<=n;++i) if(bad[i]) {
        dp[i]=0;
        break;
    }
    for(int i=0;i<n;++i) if(bad[i] and dp[i]!=oo) {
        int k=i, zeros=0;
        for(int j=i;j<n;++j) {
            zeros+=t[j]==-1;
            int e = (pref[i] - suf[j+1]+1)/2;
            while(zeros>e) {
                zeros-=t[k++]==-1;
            }
            int nwminimum = p[j+1] - (j+1-k) + (p[k]-pref[k]);
            int to = firstbad[max(0,nwminimum)];
            dp[to]=min(dp[to],dp[i]+e);
        }
    }
    cout << min((-sum+1)/2,dp[n]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}