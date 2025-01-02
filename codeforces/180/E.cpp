// LUOGU_RID: 159788557
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],lst[N],nxt[N],fa[N];
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!lst[a[i]]) fa[a[i]]=i,lst[a[i]]=i;
		else nxt[lst[a[i]]]=i,lst[a[i]]=i;
	}
	int maxn=0;
	for(int i=1;i<=m;i++){
		int cnt=1;
		int l=fa[i],r=fa[i];
		do{
			r=nxt[r];
			cnt++;
			while(r-l+1-cnt>k) l=nxt[l],cnt--;
			maxn=max(maxn,cnt);
		}while(nxt[r]);
	}
	cout<<min(maxn,n);
	return 0;
}
