#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

#define endl "\n"
#define Amgad ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

int n,BIT[5005];

void update(int pos,int val)
{
    for(int i=pos;i<=n;i+=i&(-i))
    {
        BIT[i]+=val;
    }
}

int query(int pos)
{
    ll ret=0;
    for(int i=pos;i;i-=i&(-i))
    {
        ret+=BIT[i];
    }
    return ret;
}

void Solve()
{
    cin>>n;
    vector<int>p(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        p[i]++;
    }
    int sum,mx,way;
    sum=mx=way=0;
    for(int i=n;i;i--)
    {
        memset(BIT,0,(n+1)*sizeof BIT[0]);
        for(int j=i-1;j;j--)
        {
            if(p[j]<p[i]) continue;
            sum++;
            int len=query(p[j]);
            if(len==mx) way++;
            else if(len>mx)
            {
                mx=len;
                way=1;
            }
            update(p[j],1);
        }
    }
    cout<<sum-2*mx-1<<' '<<way<<endl;
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
