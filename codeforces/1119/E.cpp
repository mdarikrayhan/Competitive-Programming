#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const long long longlongmax=9223372036854775807;
const int modul=998244353;
const long long mod = 1e9 + 7;


signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("factory.in","r",stdin);
    //freopen("factory.out","w",stdout);


    int n;
    cin >> n;
    vector<int> niz(n);
    for(auto&x:niz)
        cin >> x;
    /*vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(2));
    dp[0][0]={niz[0]/3,niz[0]%3};
    dp[0][1]=dp[0][0];
    for(int i=1; i<n; i++){
        dp[i][0]={max(dp[i-1][0].first,dp[i-1][1].first)+niz[i]/3,niz[i]%3};
        if(niz[i]==1){dp[i][1]={}}
        dp[i][1]=max(dp[i-1][])
    }*/
    int rez=0,ost=0;
    rez+=niz[0]/3;
    ost=niz[0]%3;
    for(int i=1; i<n; i++){
        int mini=min(niz[i]/2,ost);
        rez+=mini;
        niz[i]-=mini*2;
        ost-=mini;
        rez+=niz[i]/3;
        ost+=niz[i]%3;
        //cout << i << " " << rez << " " << ost << endl;
    }
    cout << rez;


    return 0;
}
/*
    abcde
    01234
    04321 --> 12340
              0   1
    011
    110
*/
