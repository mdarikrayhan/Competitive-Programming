#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
const int N = 1003;
void fast ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0) ;
}

int dx[]= {0,1,0,-1} ;
int dy[]= {1,0,-1,0} ;
ll dp[N][N] , n , m ;
string s , t ;
ll solve(int i , int j)
{
    if( i==n&&j==m )
        return 0 ;
    ll&ret = dp[i][j] ;
    if( ret!=-1 )
        return ret ;
    ret=1e6 ;
    if(i<n&&j<m&&s[i]==t[j])
        ret = min(ret,solve(i+1,j+1)) ;
    if(i<n&&j<m)ret = min( ret , solve(i+1,j+1)+1) ;
    if(j<m)ret = min( ret , solve(i,j+1)+1 ) ;
    if(i<n)ret = min( ret , solve(i+1,j)+1 ) ;

    return ret ;
}

void build(int i,int j,int c)
{
    if(i==n&&j==m)
        return;
    ll best = solve(i,j) ;
    if( s[i]==t[j] && best == solve(i+1,j+1) )
        return build(i+1,j+1,c) ;
    else if( best-1 == solve(i+1,j+1) )
    {
        cout<< "REPLACE "<<i+c+1<<" "<<t[j]<<"\n" ;
        return build(i+1,j+1,c) ;
    }
    else if( best-1 == solve(i,j+1) )
    {
        cout<< "INSERT "<<i+c+1<<" "<<t[j]<<"\n" ;
        return build(i,j+1,c+1) ;
    }
    else
    {
        cout<< "DELETE "<<i+c+1<<"\n" ;
        return build(i+1,j,c-1) ;
    }
}
int main ()
{
    fast();
    cin>> s >> t ;
    n = s.size() ;
    m = t.size() ;
    memset(dp,-1,sizeof(dp)) ;
    cout<< solve(0,0) << endl ;
    build(0,0,0) ;
    return 0 ;
}



				   		 	    		 		 	 	 		  	