#include <bits/stdc++.h>
using namespace std;
#define FOR( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++)
#define nl endl
#define bl ' '
#define check cout << "OK"
const int N = 75001 ;
long long k , idx , row[N] , a[N] , edge[N] , len[16] , sub[N] ;
long long s[16] , allsum ;
unordered_map < long long , long long > mp;
vector < pair < long long , long long  > > cycle[N] , tmp;
bool dp[N] ;
pair < long long , int > ans[16];
void dfs( int x )
{
    if( sub[x] ){
        dfs( sub[x] ) ;
        dfs( x^sub[x]) ;
    }
    for( auto [f,s] : cycle[x] ){
        ans[row[s]].first = a[s];
        ans[row[s]].second = row[f] + 1;
    }
}
int main()
{
    cin >> k ;
    FOR( i , 0 , k - 1){
        cin >> len[i] ;
            FOR( j , 0 , len[i] - 1 )
            {
                cin >> a[idx] ;
                s[i] += a[idx] ;
                mp[a[idx]] = idx ;
                row[idx++] = i ;
            }
            allsum += s[i];
    }
    if( allsum % k != 0 )
    {
        cout << "NO" << nl;
        return 0 ;
    }
    allsum /= k;
    FOR( i , 0 , idx - 1 )
    {
        auto it = mp.find( allsum - s[row[i]] + a[i] ) ;
        edge[i] = it == mp.end() ? -1 : it->second ;
    }
    FOR( i , 0 , idx - 1 )
    {
        if( edge[i] != - 1 )
        {
            int s = 0 ;
            tmp.clear();
            for( int j = i ; ; )
            {
                if( s >> row[j] & 1 || edge[j] == -1 ) break ;
                tmp.push_back( { j , edge[j] });
                s |= (1 << row[j]);
                j = edge[j] ;
            }
            if( tmp.back().second == i ){
                dp[s] = 1 ;
                cycle[s] = tmp;
            }
        }
    }
    for ( int  i = 1 ; i < ( 1 << k) ; i++ )
        for ( int j = i ; j && !dp[i] ; j = ( j - 1 ) & i )
            if( dp[j] && dp[i^j] )
            {
                dp[i] = true;
                sub[i] = j;
                break;
            }
    if( dp[(1<<k)-1] == 0 )
    {
        cout << "NO" << nl ;
        return 0 ;
    }
    cout << "YES" << nl;
    dfs( ( 1 << k ) - 1 ) ;
    FOR( i , 0 , k - 1 )
        cout << ans[i].first << bl << ans[i].second << nl ;
}
