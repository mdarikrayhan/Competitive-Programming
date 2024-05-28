#include<bits/stdc++.h>
using namespace std;
int n,m;
int A[305],B[305],C[305];
int a[10005][305];int tot;
int ok[305][305];int ans[305];
int use[305],o[305];
void solve(){
	memset(a,0,sizeof(a));memset(ok,0,sizeof(ok));
	for(int i = 0;i<=m;i++)use[i] = 0,ans[i] = 0,o[i] = 0;
	for(int i = 0;i<=tot;i++)for(int j =0;j<=m+1;j++)a[i][j] = 0;
	cin >> n >> m;
	for(int i =0;i<=n;i++)for(int j =0;j<=n;j++)ok[i][j] = 0;
	for(int i = 1;i<=m;i++)cin >> A[i] >> B[i] >> C[i];
	int tot =0 ;
	for(int i = 1;i<=m;i++){
		ok[A[i]][B[i]] = ok[B[i]][A[i]] = i;
		if(C[i]!=-1){
			a[++tot][i] = 1,a[tot][m+1] = C[i]%3;
		}
	}for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			for(int k = j+1;k<=n;k++){
				if(ok[i][j] and ok[j][k] and ok[i][k]){
					a[++tot][ok[i][j]] = 1;
					a[tot][ok[j][k]] = 1;
					a[tot][ok[i][k]] = 1;
					a[tot][m+1] = 0;
				}
			}
		}
	}
	
	//for(int i = 1;i<=tot;i++){
	//	for(int j = 1;j<=m+1;j++){
	//		cout<< a[i][j] << " ";
	//	}cout << endl;
	//}
	
	int r =0 ;
	for(int i = 1;i<=m;i++){
		int pos =0;
		for(int j=r+1;j<=tot;j++){
			if(a[j][i]){
				pos = j;break;
			}
		}
		if(!pos){
			for(int j = 1;j<=tot;j++)a[j][i] =0 ;ans[i] =0;
			continue;
		}
		swap(a[++r],a[pos]);
		if(a[r][i] != 1){
			for(int j = 1;j<=m+1;j++)a[r][j] = (3-a[r][j])%3;
		}o[i] = 1;
//		cout << " " << r << " "<< i << endl;
		for(int j = 1;j<=tot;j++){
			if(j == r)continue;
			int v = a[j][i];
			if(!v)continue;
			for(int k = 1;k<=m+1;k++){
				a[j][k] = (a[j][k]-a[r][k]*v+9)%3;
			}
		}
	//	cout << i << endl;
	//		for(int i = 1;i<=tot;i++){
	//			for(int j = 1;j<=m+1;j++){
	///				cout<< a[i][j] << " ";
	///			}cout << endl;
	//		}
	}
	int okk = 1;
	for(int i = r+1;i<=tot;i++){
		for(int j =1;j<=m+1;j++)if(a[i][j]!=0)okk = 0;
	}
	if(!okk){
		cout << -1 << endl;return;
	}
	for(int i = 1;i<=r;i++){
		int pos=0;
		for(int j = 1;j<=m;j++){
			if(a[i][j]){
				pos = j;break;
			}
		}
		//assert(!use[pos]);
		if(use[pos]){cout << ' ' <<o[pos]<<o[pos]<< ' '<< pos << endl;return;}
		use[pos] = 1;
		ans[pos] = a[i][m+1];
	}
	//cout << endl;
	//for(int i = 1;i<=tot;i++){
	//	for(int j = 1;j<=m+1;j++){
	//		cout<< a[i][j] << " ";
	//	}cout << endl;
	//}
	for(int i = 1;i<=m;i++){
		if(!ans[i])ans[i] = 3;
		cout << ans[i] << " ";
	//	assert(C[i] == -1 or C[i] == ans[i]);
	}
	cout << '\n';return;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin >> t;
	while(t--){
		solve();
	}
	return 0;
}/*
1
3 3
1 2 1
2 3 2
3 1 -1
3 3
1 2 1
2 3 1
3 1 -1
4 4
1 2 -1
2 3 -1
3 4 -1
4 1 -1
3 3
1 2 1
2 3 1
3 1 2
*/