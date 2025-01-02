#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
#define int long long
#define ld long double 

const int N = 2e5 + 20;
const int LOG = 20;

int up[N][LOG];
int dep[N];

int n;

int lca(int a,int b){
	if(dep[a] < dep[b])swap(a, b);
	int k = dep[a] - dep[b];
	for(int i = 0;i<LOG;i++)
		if(k & (1 << i))
			a = up[a][i];
		
	if(a == b)
		return a;
	for(int i = LOG -1;i>=0;i--)
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
		
	return up[a][0];
}

int dist(int a,int b){
	return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

signed main(){ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	int d1 = 0;
	int d2 = 0;
	int d = 0;
	for(int i = 1;i<n;i++){
		int p;
		cin>>p;
		--p;
		up[i][0] = p;
		dep[i] = dep[p] + 1;
		for(int j = 1;j<LOG;j++)
			up[i][j] = up[up[i][j-1]][j-1];
	
		if(dist(d1, i) > d){
			d = dist(d1, i);
			d2 = i;
		}
		if(dist(d2, i) > d){
			d = dist(d2, i);
			d1 = i;
		}
		cout<<d<<" ";
	}
	cout<<endl;
}
