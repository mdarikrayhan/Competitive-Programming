#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
      
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> a(n-1),b(n);
        for(int i=0;i<n-1;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll i = 0,j = 0,cnt = 0,mx = 0;
        while(j<n ){
            if(i == n-1){
                mx = b[j];
                cnt++;
                break;
            }
            if(a[i] < b[j]){
                i++;
                j++;
            }else{
                mx = max(mx,b[j]);
                j++;
                cnt++;
            }
        }
        
        if(m <= mx-1){
            cout<<m*(cnt-1)<<endl;
        }else{
            cout<<(mx-1)*(cnt-1)+(m-mx+1)*cnt<<endl;
        }
    }
 
    return 0;
}