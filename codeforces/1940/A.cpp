#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
vector<int>V[LIM];
int F[LIM];
set<int>odw;
map<pair<int,int>,int>mp;
vector<pair<int,int>>A, B, oba;
int fnd(int x) {
  if(F[x]==x) return x;
  return F[x]=fnd(F[x]);
}
void uni(int a, int b) {
  a=fnd(a); b=fnd(b);
  if(a==b) return;
  if(V[a].size()<V[b].size()) swap(a, b);
  for(auto i : V[b]) V[a].pb(i);
  V[b].clear();
  F[b]=a;
}
void solve() {
  odw.clear();
  mp.clear();
  A.clear();
  B.clear();
  oba.clear();
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  rep(i, n) V[i].clear();
  rep(i, n) {
    V[i].pb(i);
    F[i]=i;
    odw.insert(i);
  }
  while(m1--) {
    int a, b;
    cin >> a >> b; --a; --b;
    if(a>b) swap(a, b);
    mp[{a, b}]+=1;
  }
  while(m2--) {
    int a, b;
    cin >> a >> b; --a; --b;
    if(a>b) swap(a, b);
    mp[{a, b}]+=2;
  }
  rep(i, n) if(odw.find(i)!=odw.end()) {
    queue<int>q;
    q.push(i);
    odw.erase(i);
    while(!q.empty()) {
      int p=q.front(); q.pop();
      int lst=0;
      while(true) {
        auto it=odw.lower_bound(lst);
        if(it==odw.end()) break;
        int x=*it;
        lst=x+1;
        if(mp[{min(p, x), max(p, x)}]%3==0) {
          uni(p, x);
          q.push(x);
          odw.erase(it);
          if(mp[{min(p, x), max(p, x)}]==0) oba.pb({min(p, x), max(p, x)});
        }
      }
    }
  }
  bool ok=false;
  rep(i, n) if(F[i]==i && V[i].size()>1) {
    ok=true;
    cout << "Yes\n";
    rep(j, n) if(F[j]==j && i!=j) {
      pair<int,int>a={V[i][0], V[j][0]}, b={V[i][1], V[j][0]};
      if(a.st>a.nd) swap(a.st, a.nd);
      if(b.st>b.nd) swap(b.st, b.nd);
      if(mp[a]==1) A.pb(a); else B.pb(a);
      if(mp[b]==2) A.pb(b); else B.pb(b);
      
    }
    break;
  }
  if(!ok) {
    if(n==3) {
      cout << "No\n";
      return;
    }
    cout << "Yes\n";
    rep(i, n-1) {
      pair<int,int>a={i, i+1};
      if(mp[a]==1) A.pb(a); else B.pb(a);
    }
    pair<int,int>a={1, n-1};
    if(mp[a]==2) A.pb(a); else B.pb(a);
    for(int i=2; i<n; ++i) {
      a={0, i};
      if(mp[a]==2) A.pb(a); else B.pb(a);
    }
  }
  if(A.size()>B.size()) swap(A, B);
  cout << oba.size()+A.size() << '\n';
  for(auto i : oba) cout << i.st+1 << " " << i.nd+1 << '\n';
  for(auto i : A) if(mp[i]==1) cout << i.st+1 << " " << i.nd+1 << '\n';
  for(auto i : A) if(mp[i]==2) cout << i.st+1 << " " << i.nd+1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1, subtask;
  cin >> _ >> subtask;
  while(_--) solve();
}