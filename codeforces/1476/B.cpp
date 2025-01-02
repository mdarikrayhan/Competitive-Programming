#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int M=1e9+7;
int main()
{
    optimize();
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        ll l=0,r=1e14,ans=0;
        while(l<r){
            ll mid=(l+r)/2;
            ll sum=arr[0]+mid;
            bool ok=true;
            for(int i=1;i<n;i++){
                ll x=(sum*k)/100;
                if(arr[i]>x){
                    ok=false;
                    break;
                }
                sum+=arr[i];
            }
            
            if(ok){
                
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        cout<<l<<endl;
    }
        
}