// LUOGU_RID: 160031806
#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define int long long
#define db long double
#define pii pair<int,int>
#define pb push_back
#define st first
#define ed second
#define mod 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define il inline
#define umap unordered_map
#define eps 1e-9
il int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int T=1,n,m,q,k,S;
vector<pii> a,b;
int l[N],r[N];
signed main(){
//	n=read();
//	sort(tmp+1,tmp+1+tot);m=unique(tmp+1,tmp+1+tot)-(tmp+1);
//	for(int i=1;i<=n;i++){
//		l[i]=lower_bound(tmp+1,tmp+1+m,l[i])-tmp;
//		r[i]=lower_bound(tmp+1,tmp+1+m,r[i])-tmp;
//		int op=0;
//		if(l>r)op=1,swap(l[i],r[i]);
//		s[i]={l[i],r[i],tmp[r[i]],tmp[r[i]]-tmp[l[i]],op};
//		printf("%lld %lld %lld %lld %lld\n",s[i].l,s[i].r,s[i].R,s[i].len,s[i].op);
//	}
	n=read();
	for(int i=1;i<=n;i++)l[i]=read();
	for(int i=1;i<=n;i++)r[i]=read();
	int ans=0;
	for(int i=1;i<=n;i++){
		if(l[i]<=r[i])a.pb({l[i],r[i]});
		else b.pb({r[i],l[i]});
		ans+=abs(l[i]-r[i]);
	}
	sort(a.begin(),a.end());sort(b.begin(),b.end());
	int ma=a.size(),mb=b.size();
	int Max=0,add=0;
	int i=0;
	for(int j=0;j<mb;j++){
		while(i<ma&&a[i].st<=b[j].st)Max=max(Max,a[i++].ed);
		add=max(add,min(b[j].ed,Max)-b[j].st);
	}
	Max=0;
	int j=0;
	for(int i=0;i<ma;i++){
		while(j<mb&&b[j].st<=a[i].st)Max=max(Max,b[j++].ed);
		add=max(add,min(a[i].ed,Max)-a[i].st);
	}
	printf("%lld\n",ans-2*add);
	return 0;
}
