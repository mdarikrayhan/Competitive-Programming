#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long a,b=1,c=0,ans;
    cin>>a;
    ans= (a*(a+1))/2;
    while(b<=a)
    {
        c+=b;
        b*=2;
    }
    ans=ans-2*c;
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}