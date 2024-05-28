#include <bits/stdc++.h>
using namespace std;
const int N = 2010, M = 2010;
#define deb(x) cout << #x << " = " << x << '\n';
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
typedef pair<int, int> pii;
int f[N][N];
vector<pii> s;
vector<int> ans;
void dfs(int x,int y){
    if(x==0) return;
    if(f[x-1][y-s[x].first]==-1){
         ans.push_back(x);
         dfs(x-1,y-s[x].first);
    }
    else dfs(x-1,y);
}
void solve() {
    int n;cin>>n;
    int m=n*2;
    vector<int> p(m+10),a,b;
    for(int i=0;i<m;i++) cin>>p[i];
    s.push_back({0,0});
    int x=p[0],cnt=1;
    for(int i=1;i<m;i++){
        if(x>p[i]) cnt++;
        else s.push_back({cnt,i-cnt}),cnt=1,x=p[i];
    }
    s.push_back({cnt,m-cnt});
    //for(auto e:s) cout<<e.first<<' '<<e.second<<endl;
    f[0][0]=-1;
    for(int i=1;i<s.size();i++)
      for(int j=0;j<=n;j++){
          f[i][j]=f[i-1][j];
          if(j>=s[i].first&&f[i][j]!=-1) f[i][j]=f[i-1][j-s[i].first];
      }
    if(f[s.size()-1][n]!=-1){
        cout<<-1<<endl;
        return;
    }
    dfs(s.size()-1,n);
    map<int,int> mp;
    sort(ans.begin(),ans.end());
    for(auto e:ans){
        int cnt=s[e].first,id=s[e].second;
        for(int i=id;i<id+cnt;i++) cout<<p[i]<<' ',mp[p[i]]=1;
    }
    cout<<endl;
    for(int i=0;i<m;i++)
      if(!mp[p[i]]) cout<<p[i]<<' ';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while (t--) solve();
}