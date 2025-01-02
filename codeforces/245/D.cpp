#include<bits/stdc++.h>
using namespace std;
int n;
int b[105][105]={};
int p[35]={};
bool testBit(int x,int k){
    return x&p[k];
}
int main(){
    cin>>n;
    p[0]=1;
    for (int i=1;i<=29;i++) p[i]=p[i-1]*2;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) cin>>b[i][j];
    }
    for (int i=1;i<=n;i++){
        int ans=0;
        for (int u=0;u<=29;u++){
            int mx=0;
            for (int j=1;j<=n;j++){
                if (i==j) continue;
                mx=max(mx,(int)testBit(b[i][j],u));
            }
            ans+=p[u]*mx;
        }
        cout<<ans<<" ";
    }
}