#include <bits/stdc++.h>
using namespace std;
#define cyes cout<<"YES"<<endl;
#define cno cout<<"NO"<<endl;

void solve(){
    int n, d;
    cin>>n>>d;
    int a[n];
    int ans=0, remaining=n;
    
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
    
    for(int i=n-1; i>=0; i--){
        int val=d/a[i] + 1;
        if(val<=remaining){
            remaining-=val;
            ans++;
        }
        else
            break;
    }
    cout<<ans<<endl;
}

int main() {
    // int t;
    // cin>>t;
    // while(t--)
        solve();
}