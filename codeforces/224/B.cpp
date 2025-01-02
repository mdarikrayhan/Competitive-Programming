#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define rep(i, j, n) for (int i = j; i <= n; i++)
using namespace std;
int a[100010];
int n,m;
int ct[100010];
int cts=0;
void solve() {
  cin >> n >> m;
  rep(i,1,n){
  	cin>>a[i];
  }
  int l=1;
  int al=-1,ar=-1,aws=1000000000000000000,sum=0;
  rep(i,1,n){
	ct[a[i]]++;
	sum+=a[i];
	if(ct[a[i]]==1){
		cts++;
	}
  	for(;l<=n;l++){
  		if(cts<m){
  			break;
  		}
  		if(cts==m){
  			if(aws>min(aws,sum)){
  				al=l;
  				ar=i;	
  				aws=sum;
  			}
  		}
  		ct[a[l]]--;
  		sum-=a[l];
  		if(ct[a[l]]==0){
  			cts--;
  		}
  	}
  }
  cout<<al<<" "<<ar<<endl;
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

  return 0;
}