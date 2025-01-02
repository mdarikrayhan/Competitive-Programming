#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int cst=1e9+7;
// <<fixed<<setprecision(9);
// next_permutation(v.begin(),v.end());

int binpow(int x, int n) {
    int res=1;
    for (int bit=0; bit<=60; bit++) {
        if (n>>bit&1) 
            res=(res*x);
        x=(x*x);
    }
    return res;
}

int t[20010];
int ans[5010]={};
int prevans[5010]={};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin>>n>>m;
    int a[n];
    vector <int> v[m];
    set <int> more;
    vector <int> less;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        v[a[i]%m].push_back(i);
    }
    for(int i=0; i<m; i++)
        if(v[i].size()>n/m)
            more.insert(i);
    for(int i=0; i<m; i++)
    {
        if(v[i].size()<n/m)
        {
            int rep=n/m-v[i].size();
            while(rep--)
                less.push_back(i);
        }
    }
    int ans=0;
    for(auto type: less)
    {
        auto it=more.upper_bound(type);
        if(it==more.begin())
            it=more.end();
        it--;
        int cur=v[(*it)][v[(*it)].size()-1];
        v[(*it)].pop_back();
        if(v[(*it)].size()==n/m)
            more.erase((*it));
        int plus=0,fromtype=a[cur]%m;
        plus=(type-fromtype+m)%m;
        a[cur]+=plus;
        ans+=plus;
    }
    cout<<ans<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}