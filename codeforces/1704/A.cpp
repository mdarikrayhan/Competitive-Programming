#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define el '\n'

void solve(){
   int n,m;
   cin>>n>>m;
   string a,b;
   cin>>a>>b;
   if(a==b){
    cout<<"YES"<<el;
    return;
   }
   if(m>n){
    cout<<"NO"<<el;
    return;
   }
   int i=m-1;
   int j=n-1;
   while(i>0){
    if(a[j]!=b[i]){
        cout<<"NO"<<el;
        return;
    }
    i--;
    j--;
   } 
  // j--;
   while(j>=0){
    if(a[j]==b[i]){
        cout<<"YES"<<el;
        return;
    }
    j--;
   }
   cout<<"NO"<<el;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}