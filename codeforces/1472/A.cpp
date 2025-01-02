#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int a, b, c, o=1;cin>>a>>b>>c;
    while (a%2==0) {a/=2;o*=2;}
    while (b%2==0){b/=2;o*=2;}
    if(o>=c)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
