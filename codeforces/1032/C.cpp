#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define el <<endl ;
#define ll long long
#define Lol ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(n) (int)n.size()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mem(arr,num) memset(arr, num, sizeof(arr))
/*
 * ياا مسهل الاحوال
 * يا رب كوتش من عندك يا رب
 * */
int dx[]= { -1,1,0,0 } ;
int dy[]= { 0,0,-1,1 } ;
int add( int a , int b , int mod ) { return ( a%mod + b%mod + mod)%mod ;}
using namespace __gnu_pbds;
using namespace std;
void _3K_W_RABK_YFK(){
    int n ;cin>>n ;
    vector<int>v(n) ;
    for( auto &i:v ) cin>>i ;
    vector<vector<int>>dp(n,vector<int>(6,0)) ;
    for( int i=1; i<=5; ++i )
        dp[0][i]=i ;
    for( int i=0 ;i<n-1 ; ++i ){
        for( int num=1; num<=5; ++num ) {
            if( !dp[i][num] ) continue;
            if (v[i] == v[i + 1]) {
                for (int j = 1; j <= 5; ++j)
                    if (num != j)
                        dp[i + 1][j] = num;
            }
            if( v[i]<v[i+1]){
                for( int j=num+1 ; j<=5; ++j ){
                    dp[i+1][j]=num ;
                }
            }
            if( v[i]>v[i+1] ){
                for( int j=num-1 ; j>=1; --j )
                    dp[i+1][j]=num ;
            }
        }
    }
    bool chk=0 ;
    int idx ;
    for( int i=1; i<=5; ++i ){
        if( dp[n-1][i] ){
            chk=1 ;
            idx=i ;
        }
    }
    /*
    for( int i=0 ; i<n ; ++i ){
        for( int j=1; j<=5; ++j )
            cout<<dp[i][j]<<' ' ;
        cout el
    }
    cout el
    cout<<idx<<endl ;
     */
    if( !chk ) cout<<-1 ;
    else {
        vector<int>ans={idx} ;
        for( int i=n-1; i>0 ; --i){
            ans.push_back(dp[i][ans.back()]) ;
        }
        reverse(all(ans)) ;
        for( auto i:ans ) cout<<i<<' ' ;
    }
}
int32_t main()
{
    Lol
    //freopen("closing.in", "r", stdin);
    //freopen("closing.out", "w", stdout);
    int t=1 ; //cin>>t ;
    for( int i=1; i<=t; ++i ){
        _3K_W_RABK_YFK();
    }
    return 0;
}
/* practice makes PERFECT */