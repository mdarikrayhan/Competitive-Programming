#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void setIO(string name)
{
    cin.tie(0);ios_base::sync_with_stdio(0);
    if(name.size()){freopen((name+".in").c_str(),"r",stdin);freopen((name+".out").c_str(),"w",stdout);}
}
mt19937 rng(time(0));
/*------------------------------------code------------------------------------*/
const ll MAXN=3*1e5+3;
const ll INF=1e9;
const int R=MAXN;//(1<<19);
const ll M=1e9;
const int S=21;

int n, q;
vector<ll> arr(MAXN, 0);
vector<ll> st[S];
unordered_map<ll, vector<ll>> mp;

void update(int k, int x)
{
    if(mp[x].empty())
        for(int t=0;t<S;t++)
            mp[x].pb(rng()%M+1);
    arr[k]=x;
    for(int t=0;t<S;t++)
    {
        int pos=k+R;
        st[t][pos]=mp[x][t];
        while(pos>1)
        {
            pos/=2;
            st[t][pos]=st[t][pos*2]+st[t][pos*2+1];
        }
    }
}

bool query(int l, int r, int k)
{
    ll a, b, res;
    for(int t=0;t<S;t++)
    {
        a=l, b=r, res=(l==r ? st[t][l] : st[t][l]+st[t][r]);
        while(a/2!=b/2)
        {
            if(a%2==0)
                res+=st[t][a+1];
            if(b%2==1)
                res+=st[t][b-1];
            a/=2;
            b/=2;
        }
        if(res%k)
            return false;
    }
    return true;
}

void solve()
{
    for(int i=0;i<n;i++)
    {
        if(mp[arr[i]].empty())
        {
            vector<ll> v;
            for(int t=0;t<S;t++)
                v.pb(rng()%M+1);
            mp[arr[i]]=v;
        }
    }
    for(int t=0;t<S;t++)
    {
        st[t].resize(2*MAXN+3, 0);
        for(int i=0;i<n;i++)
            st[t][i+R]=mp[arr[i]][t];
        for(int i=R-1;i>=1;i--)
            st[t][i]=st[t][2*i]+st[t][2*i+1];
    }
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int i, x;
            cin>>i>>x;
            update(i-1, x);
        }
        else
        {
            int l, r, k;
            cin>>l>>r>>k;
            cout<<(query(l+R-1, r+R-1, k) ? "YES" : "NO")<<"\n";
        }
    }
}

int main()
{
    setIO("");
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    solve();
    return 0;
}
