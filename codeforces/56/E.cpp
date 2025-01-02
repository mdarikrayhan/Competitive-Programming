// LUOGU_RID: 160352184
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int ans[maxn],last[maxn];
struct node{int p,h,id;}p[maxn];
bool cemp(node p,node q){
	return p.p<q.p;
}
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].p,&p[i].h);
		p[i].id=i;
	}
	sort(p+1,p+1+n,cemp);
	for(int i=1;i<=n;i++) ans[i]=1;
	for(int i=n;i>=1;i--){
		int pos=i+1;
		while(pos&&p[i].p+p[i].h>p[pos].p){
			ans[p[i].id]+=ans[p[pos].id];
			pos=last[pos];
		}
		last[i]=pos;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n"); return 0;
}