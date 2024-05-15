#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> count(n+1);
    for (int i = 0; i < n; i++)
    {
        count[v[i]]++;
    }
    vector<int> cf(n+1);
    cf[0] = count[0];
    for (int i = 1; i < n+1; i++)
    {
        cf[i] = cf[i-1]+count[i];
    }
    
    int ans=0;
    int i=0;
    while(i<n){
        if(cf[i]==0){
            i++;
        }
        else if(i>=cf[i]){
            i++;
        }
        else if(cf[cf[i]]==cf[i]){
            ans++;
            i = cf[i];
        }
        // else if(cf[cf[i]]==cf[i]){
        //     i++;
        // }
        else{
            i = cf[i];
        }
    }




    // for (int i = 0; i < n; i++)
    // {
    //     if(count[i]!=0 && count[i+1]==0 && cf[i]>=i+1){
    //         ans++;
    //     }
    // }
    if(count[0]==0){
        cout<<ans+1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}