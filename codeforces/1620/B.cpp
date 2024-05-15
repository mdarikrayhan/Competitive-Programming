#include <bits/stdc++.h>
using namespace std;
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl

void solve(){
    int w,h,k,l,r,x,height;
    long long ans=0;
    cin>>w>>h;
    for(int j=0; j<4; j++){
        if(j<2)
            height=h;
        else
            height=w;
        cin>>k;
        cin>>l;
        for(int i=2; i<k; i++)
            cin>>x;
        cin>>r;
        ans = max(ans, 1ll*height*(r-l));
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
}