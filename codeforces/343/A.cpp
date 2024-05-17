#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e9+7;
 int arr[100011];
 
void solve(){
    int a,b;
    cin>>a>>b;
    int ans=0;
    ans+=a/b;
    
    if(a%b==0){
        cout<<ans<<"\n";
        return;
    }
    int x=a,y=b,temp;
    x=a%b;
    while( x!=0 ){
        // cout<<x<<"-"<<y<<" ";
        ans+=y/x;
        temp=y;
        y=x;
        x=temp%x;
    }
    // cout<<"--\n";
    cout<<ans<<"\n";
}
 
int32_t main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _t=1;//cin>>_t;
    while(_t--){solve();}   
    return 0;
}
