#include <bits/stdc++.h>
using namespace std;
#define cyes cout<<"YES"<<endl;
#define cno cout<<"NO"<<endl;

void solve(){
    int n, r, b;
    cin>>n>>r>>b;
    int val= ceil(r/(b+1.0));
    
    for(int i=0; i<b; i++){
        int cnt= min(r-b+i, val);
        r -= cnt;
        for(int j=0; j<cnt; j++)
            cout<<"R";
        cout<<"B";
    }
    for(int j=0; j<r; j++)
            cout<<"R";
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
}