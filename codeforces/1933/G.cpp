#include<bits/stdc++.h>
using namespace std;
bool a[8];
void solve(){
    int n,m,q,ans;
    cin >> n >>m >>q;
    for(int i=0;i<8;i++) a[i]=1;
   cout<<"8\n";
    while(q--){
        int x,y;
        cin >> x >> y;
        string st;
        cin>>st;
        bool c=(st=="circle"),s=(st=="square");
        if((x+(y+1)/2)%2) a[0]&=c,a[1]&=s;
        else a[0]&=s,a[1]&=c;
        if((x+y/2)%2) a[2]&=c,a[3]&=s;
        else a[2]&=s,a[3]&=c;
        if((y+(x+1)/2)%2) a[4]&=c,a[5]&=s;
        else a[4]&=s,a[5]&=c;
        if((y+x/2)%2) a[6]&=c,a[7]&=s;
        else a[6]&=s,a[7]&=c;
        ans=0;
        for(int i=0;i<8;i++) ans+=a[i];
        cout<<ans<<"\n";
    }
}
int main(){
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}