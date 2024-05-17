#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int mod=998244353;
#define int long long
const int M = 2e5 + 10;
int  power(int a, int b){
    if (b==0) return 1;
    int t =power(a,b/2);
    return (b%2?t*t%mod*a%mod:t*t%mod);
}
 int ask(int l,int r){
    int a;
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>a;
    return a;
 }
 void solve(){
     int n;cin>>n;
     int pos=ask(1,n);
     if(pos!=n&&ask(pos,n)==pos){
        int l=pos+1,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(ask(pos,mid)!=pos){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        cout<<"! "<<l;
     }
     else{
        int l=1,r=pos-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(ask(mid,pos)!=pos){
                r=mid-1;
            }
            else{
             l=mid+1;
            }
        }
        cout<<"! "<<r;
     }
 }
 signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    //cin>>T;
    while (T--) {
        solve();
    }
}