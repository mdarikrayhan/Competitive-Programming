#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

#define endl "\n"
#define Amgad ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

unordered_map<int,int>mp;
unordered_map<int,map<int,int>>BIT;

void update(int pos,int x,int val)
{
    for(int i=pos;i<=1e9;i+=i&(-i))
    {
        BIT[i][x]+=val;
    }
}

int query(int pos,int x)
{
    int ret=0;
    for(int i=pos;i;i-=i&(-i))
    {
        ret+=BIT[i][x];
    }
    return ret;
}

void Solve()
{
    int q;
    cin>>q;
    int cnt=0;
    while(q--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
        {
            if(!mp.count(y)) mp[y]=++cnt;
            update(x,mp[y],1);
        }
        else if(t==2)
        {
            update(x,mp[y],-1);
        }
        else
        {
            cout<<query(x,mp[y])<<endl;
        }
    }
}

int main()
{
    Amgad
    ll T=1;
    //cin>>T;
    while(T--)
    {
        Solve();
    }
}
