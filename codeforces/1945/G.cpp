#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define fast_read ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define _rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) x.begin(), x.end()
#define int long long

struct stu{
    int i;
    int k;//优先级
    int s;//时间

    bool operator<(const stu&x)const{
        if(k==x.k){
            if(i==x.i){
                return s>x.s;
            }
            return i>x.i;
        }
        return k<x.k;
    }
}a[200005];

int sufMax[200005];
int n,d;

int check(vector<vector<stu>>& eat){
    int eated=0;
    priority_queue<stu> qu;
    for(int i=0;i<d && eated<n;++i){
        if(qu.empty() || qu.top().k<=sufMax[eated]){
            int nextm=i+a[eated].s;
            if(nextm<d){
                eat[nextm].push_back(a[eated]);
            }
            ++eated;
            if(eated==n){
                return i+1;
            }
        }else{
            int nextm=i+qu.top().s;
            if(nextm<d){
                eat[nextm].push_back(qu.top());
            }
            qu.pop();
        }
        for(const auto&s:eat[i]){
            qu.push({i,s.k,s.s});
        }
    }
    return -1;
}

void solve()
{
    cin>>n>>d;
    for(int i=0;i<n;++i){
        cin>>a[i].k>>a[i].s;
        a[i].i=i;
    }
    vector<vector<stu>> eat(d+1);
    sufMax[n-1]=a[n-1].k;
    for(int i=n-2;i>=0;--i){
        sufMax[i]=max(a[i].k,sufMax[i+1]);
    }
    cout<<check(eat)<<"\n";
}

int32_t main()
{
    fast_read
    int _ ;cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
