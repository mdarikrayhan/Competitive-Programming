#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    int ans=0;
    for(int i=0;i<n-1;i++){
        if((a[i] % 2 == 0 && a[i+1] % 2 == 0) || (a[i] % 2 != 0 && a[i+1] % 2 != 0))
            ans++;
    }
    
    cout<<ans<<endl;
}
 
int main()
{
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }
    return 0;
}