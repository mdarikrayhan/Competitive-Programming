#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n ; cin >> n ;
    ll arr[n] ;
    for( ll i=0 ;i<n ; i++ ) cin >> arr[i] ;

    ll prefix_sum[n] ;
    prefix_sum[0]=arr[0] ;
    for( ll i=1 ; i<n ; i++ ) prefix_sum[i]=prefix_sum[i-1]+arr[i] ;

    vector <pair<ll,ll>> ans ;

    for( ll i=0 ; i<n-1 ; i++ ){
        if( ((i+1)*(i+2))/2==prefix_sum[i] && (n-(i+1))*(n-i)/2==prefix_sum[n-1]-prefix_sum[i] ){

            // cout << 10 << endl ;
            bool t1[i+1]={0} , t2[n-(i+1)]={0} ;
            bool flag=1;

            for( ll j=0 ; j<i+1 ; j++ ){
                if( arr[j]>i+1 ) flag=0 ;
                else t1[arr[j]-1]=1 ;
            }

            // cout << flag << endl ;
            for( ll j=i+1 ; j<n ; j++ ){
                if( arr[j]>(n-(i+1)) ) flag=0 ;
                else t2[arr[j]-1]=1 ;
            }
            // cout << flag << endl ;
            for( ll j=0 ; j<i+1 ; j++ ){
                if( t1[j]==0 ) flag=0 ;
            }
            // cout << flag << endl ;
            for( ll j=0 ; j<(n-(i+1)) ; j++ ){
                if( t2[j]==0 ) flag=0 ;
            }
            // cout << flag << endl ;
            
            if( flag ){
                pair <ll,ll>temp ;
                temp.first=i+1 ;
                temp.second=n-i-1 ;
                ans.push_back(temp) ;
            }
        }
    }

    cout << ans.size() << endl ;
    for( ll i=0 ; i<ans.size() ; i++ ){
        cout << (ans[i]).first << " " << (ans[i]).second << endl ;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solve();
    }

return 0;
}