#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void setIO(string name)
{
    cin.tie(0);ios_base::sync_with_stdio(0);
    if(name.size()){freopen((name+".in").c_str(),"r",stdin);freopen((name+".out").c_str(),"w",stdout);}
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*------------------------------------code------------------------------------*/
const ll MAXN=1e6+3;
const ll INF=1e9;
const int R=(1<<18);
const ll M=1e6;

vector<pair<ll, ll>> cnt;
int n, k;

bool cmp(pair<ll, int> a, pair<ll, int> b)
{
    return a.first<b.first;
}

void solve()
{
    for(ll i=1,res,pos;i<=k+1;i++)
    {
        cout<<'?'<<" ";
        for(int j=1;j<=k+1;j++)
        {
            if(i!=j)
                cout<<j<<" ";
        }
        cout<<"\n";
        cin>>pos>>res;

        if(i==1)
            cnt.pb({res, 1});
        else if(res!=cnt[0].first && cnt.size()==1)
            cnt.pb({res, 1});
        else
            (res==cnt[0].first ? cnt[0].second++ : cnt[1].second++);
    }
    cout<<'!'<<" "<<(cnt[0].first>cnt[1].first ? cnt[0].second : cnt[1].second);
}

int main()
{
//    setIO("");
    cin>>n>>k;
    solve();
    return 0;
}
