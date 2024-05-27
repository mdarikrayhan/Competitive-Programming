// LUOGU_RID: 160024314
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXX=1e3+10;

int n,pos,len;
int a[MAXX],b[MAXX];
char ans[MAXX];
bool f=1;
int sol(int p) {
	ans[++len]='(';
	int siz=1;
	while(pos<n&&siz<a[p]) siz+=sol(++pos);
	if(siz<a[p]||b[p]<siz) f=0;
	ans[++len]=')';
	return siz+1;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(pos<n) {
		sol(++pos);
	}
	if(f) {
		for(int i=1;i<=2*n;i++) cout<<ans[i];
	}
	else cout<<"IMPOSSIBLE\n";

	return 0;
}