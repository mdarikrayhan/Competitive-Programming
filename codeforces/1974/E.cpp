#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void FAST() { //FAST Input Output, DONT use both scnaf,printf / cin,cout , Use any ONE system
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
}

// cost for that happiness
// reverse recursion
int happiness(int n, vector<int> cost, vector<int> happiness, int currenthappiness){

}

void solve(){
    vector<long long int> dp(1e5,1e18);
    int n,pay,maxh=0;
    cin>>n>>pay;
    vector<int> h(n),c(n);
    for (int i=0;i<n;i++){
        cin>>c[i]>>h[i];
    }

    dp[0]=0;
    for (int i=0;i<n;i++){
        int happiness=h[i], cost = c[i];
        maxh+=happiness;
        for (int j=maxh;j>=0;j--){
            if (dp[j]+cost<=0) dp[happiness+j]=min(dp[happiness+j], dp[j]+cost);
        }
        // if (i!=n-1){
            for (int j=0;j<=maxh;j++){
                dp[j]-=pay;
            }
        // }       
    }

    long long int ans=0;
    for (int i=0;i<=maxh;i++){
        if (dp[i]<=0){ans=i;}
    }
    cout<<ans<<endl;

}

int main() {
    FAST();
    int t;
    cin>>t;
    while (t--){solve();}

    return 0;
}
