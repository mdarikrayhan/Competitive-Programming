#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n"
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
const int inf = 1e18;
const int mod = 1e9 + 7;
vector<int>dp;
void result() {
    int n;cin>>n;
    int ind=lower_bound(all(dp),n)-dp.begin();
    cout<<dp[ind];
}
signed main() {
    int q = 1;
  cin >> q;
    dp.push_back(1);
    vector<int>pow3;
    for(int i=2;i<=1e5;i++){
        int x=i;
        for(int j=531441;j>=1&&x;j/=3){
            if(j<=x)x-=j;
        }
        if(!x)dp.push_back(i);
    }
    while (q--) {
        result();
        cout<<endl;
    }
}