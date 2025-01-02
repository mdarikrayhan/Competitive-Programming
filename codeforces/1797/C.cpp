#include <bits/stdc++.h>

#define int LL
using namespace std;
typedef long long LL;

// void IOS()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
// }
void f(int x,int y){
    int d1,d2;
    cout<<"? "<<x<<" "<<y<<endl;
    cin>>d1;
    if(d1==0){
        cout<<"! "<<x<<" "<<y<<endl;
    }
    else{
        cout<<"? "<<x-d1<<" "<<y<<endl;
        cin>>d2;
        if(d2==0){
            cout<<"! "<<x-d1<<" "<<y<<endl;
        }
        else cout<<"! "<<x<<" "<<y-d1<<endl;
    }
}
void solve(){
    int n,m,d0,d1,d2;
    cin>>n>>m;
    cout<<"? 1 1"<<endl;
    cin>>d0;
    if(d0==0){
        cout<<"! 1 1"<<endl;
    }
    else{
        if(n<=d0){
            f(n,1+d0);
        }
        else if(m<=d0){
            f(1+d0,m);
        }
        else{
            f(1+d0,1+d0);
        }
        
    }
}
signed main()
{
    // IOS();
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}