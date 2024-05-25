#include<bits/stdc++.h>
using namespace std;
#define hi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define xx first
#define yy second
#define mem(a,d) memset(a,d,sizeof a)
#define memc(a,d) memcpy(a,d,sizeof a)
#define Maxn 1e18
#define PI 2*acos(0.0)
#define endl "\n"
#define test cout<<" mike_testing "
#define N 300009
//#define mx 1100009
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define PII pair<int\,int\>
typedef tree<PII, null_type,
        less<PII>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/
//priority_queue < pair< int\,  int\>, vector < pair <  int\,  int\ >> , greater<pair< int\,  int\>> > qq;
int mod=998244353;
int bigmod( int l,  int r)
{
    if(r == 0)
        return 1LL;
    int res = bigmod(l, r / 2)% mod;
    res = (res * res) % mod;
    if(r & 1)
        res = (res * l)% mod;
    return res% mod;
}

void solve()
{
    int n,m;
    set<int>st;
    cin>>n>>m;
    int x[n];
    for(int i=0; i<n; i++)cin>>x[i];
    map<int,int>mp;
    for(int i=0; i+1<m; i++)
    {
        mp[x[i]]++;
        if(mp[x[i]]==1)st.insert(x[i]);
        else st.erase(x[i]);
    }
    int id=0;
    for(int i=m-1; i<n; i++)
    {
        mp[x[i]]++;
        if(mp[x[i]]==1)st.insert(x[i]);
        else st.erase(x[i]);
        //cout<<x[i]<<" "<<mp[x[i]]<<" "<<*st.begin()<<" "<<*st.rbegin()<<endl;
        if(st.size()==0)cout<<"Nothing"<<endl;
        else cout<<*(st.rbegin())<<endl;
        if(mp[x[id]]==1)st.erase(x[id]);
        mp[x[id]]--;
        if(mp[x[id]]==1)st.insert(x[id]);
        id++;
    }
}
signed main()
{
    hi;
    int t,i;
    t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
/*
*/


 	  			  	   	 			  			 	  		 	