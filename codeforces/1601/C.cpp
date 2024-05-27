#include<bits/stdc++.h>

using namespace std;

const int N=1000005;
int n,m;
int a[N],b[N],q[N*2];
int p[N],t[N*2];

void add(int k){
	for (;k;k-=k&(-k)) t[k]++;
}
int ask(int k){
	int s=0;
	for (;k<=*q;k+=k&(-k)) s+=t[k];
	return s;
}
void solve(int l,int r,int L,int R){
	int inv=0,pos=L-1,mn=0;
	int mid=(l+r)/2;
	for (int i=L;i<=R;i++){
		if (b[mid]<a[i]) ++inv;
		if (b[mid]>a[i]) --inv;
		if (inv<mn) mn=inv,pos=i;	
	}
	p[mid]=pos;
	if (l<mid) solve(l,mid-1,L,pos);
	if (r>mid) solve(mid+1,r,pos,R);
}
void solve(){
	*q=0;
	scanf("%d%d",&n,&m);	
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),q[++*q]=a[i];
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i]),q[++*q]=b[i];
	sort(q+1,q+*q+1);
	sort(b+1,b+m+1);
	for (int i=1;i<=n;i++)
		a[i]=lower_bound(q+1,q+*q+1,a[i])-q;
	for (int i=1;i<=m;i++)
		b[i]=lower_bound(q+1,q+*q+1,b[i])-q;
	solve(1,m,1,n);
	int t=1;
	long long ans=0;
	p[m+1]=-1;
	for (int i=0;i<=n;i++){
		if (i) add(a[i]),ans+=ask(a[i]+1);
		while (p[t]==i) add(b[t]),ans+=ask(b[t]+1),++t;
	}
	cout<<ans<<endl;
	for (int i=1;i<=*q;i++) ::t[i]=0;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}