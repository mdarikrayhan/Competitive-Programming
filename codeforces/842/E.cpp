#include <bits/stdc++.h>

#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define YES "Yes"
#define NO "No"
#define endline '\n'

using namespace std;

const ll N = 5e5 + 10, MM = 998244353, MAX = 1e18;

int n;
int T[N][20],LOG[N],D[N];
vector<ll>v[N];

void dfs(int i=1,int p=1,int d=0){
  D[i]=d;
  T[i][0]=p;
  for(auto x:v[i]){
    if(x!=p){
      dfs(x,i,d+1);
    }
  }
}

void build(){
  for(int msk=1;msk<20;msk++){
    for(int i=1;i<=n;i++){
      T[i][msk]=T[T[i][msk-1]][msk-1];
    }
  }
}

int lca(int a,int b){
  if(D[a]>D[b])return lca(b,a); 
  int dif=D[b]-D[a];
  for(int j=0;j<20;j++){
    if(dif&(1<<j)){
      b=T[b][j];
    }
  }
  if(b==a)return a;
  for(int j=19;j>=0;j--){
    if(T[b][j]!=T[a][j]){
      b=T[b][j];
      a=T[a][j];
    }
  }
  return T[a][0];
}

int dis(int a,int b){
  int c=lca(a,b);
  return D[a]+D[b]-2*D[c];
}

int solve() {
  cin>>n;
  n++;
  for(int i=2;i<=n;i++){
    int x;cin>>x;
    v[x].emplace_back(i);
    v[i].emplace_back(x);
  }
  dfs();
  build();
  int lastDis=0;
  vector<pair<ll,ll>>v1;
  v1.emplace_back(1,1);
  for(int i=2;i<=n;i++){
    int d1=dis(v1.back().first,i);
    int d2=dis(v1.back().second,i);
    if(max(d1,d2)>lastDis){
      lastDis=max(d1,d2);
      if(d1==lastDis){
        v1.emplace_back(v1.back().first,i);
      }else{
        v1.emplace_back(v1.back().second,i);
      }
    }else{
      v1.emplace_back(v1.back());
    }
  }
  vector<ll>v2(n+1,n);
  for(int i=1;i<=n;i++){
    int l=i-1,r=n-1;
    while(l<=r){
      int mid=l+r>>1;
      int d1=dis(v1[mid].first,i);
      int d2=dis(v1[mid].second,i);
      if(max(d1,d2)==dis(v1[mid].first,v1[mid].second)){
        l=mid+1; 
      }else{
        r=mid-1;
        v2[i]=mid;
      }
    }
  }
  int sum=0;
  vector<ll>Remove(n+1);
  for(int i=1;i<=n;i++){
    if(v2[i]!=i-1){
      sum++;
      Remove[v2[i]]++;
    }
    if(i>1)
    cout<<sum<<'\n';
    sum-=Remove[i];
  }



  return 0;
}

int main() {
	speed;
	int t = 1;
	//cin >> t;
	int i = 1;
	while (t--) {
		//cout << "Case #" << i++ << ": ";
		solve();
	}
	return 0;
}
/*


*/

