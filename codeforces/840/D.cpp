// LUOGU_RID: 160020948
#include<bits/stdc++.h>
#define N 300005
#define M 300005
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int n,m,bl,tot,res,cnt[M],a[N],b[N],ans[N];
struct query{int l,r,id,p,k;}q[N];
bool cmp(const query &a,const query &b){return a.l/bl==b.l/bl?a.r<b.r:a.l<b.l;}
mt19937 R(114514);
#undef int
int main(){
#define int long long
	n=read(),m=read();
	bl=sqrt(n);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)
		q[i].l=read(),q[i].r=read(),q[i].k=read(),q[i].id=i,q[i].p=i;
	sort(q+1,q+1+m,cmp);
	for(int i=1,l=q[1].l,r=l-1;i<=m;i++){
		ans[q[i].id]=-1;
		while(l>q[i].l)++cnt[a[--l]];
		while(r<q[i].r)++cnt[a[++r]];
		while(l<q[i].l)--cnt[a[l++]];
		while(r>q[i].r)--cnt[a[r--]];
		int _=190;
		while(_--){
			int x=R()%(r-l+1)+l;
			if(cnt[a[x]]*q[i].k>r-l+1){
				if(ans[q[i].id]==-1)ans[q[i].id]=a[x];
				else ans[q[i].id]=min(ans[q[i].id],a[x]);
			}
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}