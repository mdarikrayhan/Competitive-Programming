#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(x, y, z) for(int x=y;x<(z);x++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define st first
#define nd second
inline int in(){int x;cin >> x;return x;}
const int GRZ=1e5+100,MOD=998244353;
vector<int> cx[GRZ],cy[GRZ];
bool frag(int x, int y){
  cout<<"? "<<x<<" "<<y<<endl;
  string s; cin>>s;
  return (s=="Yes");
}
void solve(){
  int n=in();
  pair<int,int> a[n];
  rep(i, 0, n) a[i].st=in(), a[i].nd=i;
  sort(a, a+n);
  vector<array<int, 3>> arr;
  rep(i, 0, n)
    rep(j, i+1, n)
      arr.pb({abs(a[i].st-a[j].st), a[i].nd, a[j].nd});
  sort(all(arr));
  reverse(all(arr));
  for(auto [dumm, x, y] : arr){
    if(frag(y+1, x+1)){
      cout<<"! "<<x+1<<" "<<y+1<<endl;
      return;
    }
  }
  cout<<"! "<<0<<" "<<0<<endl;
}
int main(){
  // ios::sync_with_stdio(false);  
  // cin.tie(0);
  int T=1;
  // T=in();
  while(T--)solve();
  cerr<<double(clock())/CLOCKS_PER_SEC<<"\n";
}