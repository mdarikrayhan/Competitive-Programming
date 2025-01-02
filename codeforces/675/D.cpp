#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define F first
#define S second
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define Ok(x) x == true ?cout<<"Yes"<<endl : cout<<"No"<<endl;
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1e5 + 3;
const int M = 998244353;
const int LOG = 30;
const ll INF = 1e18;
/////////////////////////////////////
int arr[N];
set < int > s;
map < int , int > adj_left , adj_right;
int add ( int child )
{
    auto it = s.upper_bound( arr[child] );
    int node;
    if ( it != s.end() and adj_left.find(*it) == adj_left.end() ){
        node = *it;
        adj_left[node] = arr[child];
        return node;
    }
    it--;
    node = *it;
    adj_right[node] = arr[child];
    return node;
}
void Solve()
{
    int n;
    cin >> n;
    for ( int i = 1 ; i <= n ; i += 1 )
    {
        cin >> arr[i];
    }
    for ( int i = 1 ; i <= n ; i += 1 )
    {
        if ( i > 1 )cout << add ( i ) << ' ';
        s.insert( arr[i] );
    }
}
signed main()
{
    Fast;
    //freopen("input.txt","r",stdin );
    //freopen("output.txt","w",stdout);
    int Test = 1 ;
    ///cin >> Test;
    for(int test = 1 ; test <= Test ; test++ )
    {
        Solve();
    }
}
