// LUOGU_RID: 158139126
#pragma GCC optimize(2,3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define lowbit(i) (i&(-i))
#define mid ((l+r)>>1)
#define add(i,j) (((i+j)>=mod)?i+j-mod:i+j)
using namespace std;
int l[1000005];
int pre[1000005],suf[1000005];
int lsh[1000005],m,posl[1000005],posr[1000005],toend[1000005];
struct sgt{
	int f[1000005];
	void pushdown(int i){
		if(f[i]){
			f[i*2]=f[i];
			f[i*2+1]=f[i];
			f[i]=0;
		}
	}
	void change(int i,int l,int r,int ql,int qr,int cg){
		if(ql>qr) return ;
		if(ql<=l&&r<=qr){
			f[i]=cg;
			return ;
		}
		pushdown(i);
		if(ql<=mid) change(i*2,l,mid,ql,qr,cg);
		if(qr>mid) change(i*2+1,mid+1,r,ql,qr,cg);
	}
	int qry(int i,int l,int r,int pos){
		if(l==r) return f[i];
		pushdown(i);
		if(pos<=mid) return qry(i*2,l,mid,pos);
		else return qry(i*2+1,mid+1,r,pos);
	}
}tree;
signed main(){
	int n,g,r; cin>>n>>g>>r;
	int mod=g+r;
	lsh[++m]=0;
	for(int i=1;i<=n+1;i++) cin>>l[i],pre[i]=pre[i-1]+l[i];
	for(int i=n+1;i>=1;i--) suf[i]=suf[i+1]+l[i];
	for(int i=1;i<=n;i++){
		lsh[++m]=posl[i]=(mod-pre[i]%mod)%mod;
		lsh[++m]=posr[i]=(g+mod-pre[i]%mod)%mod;
	}
	sort(lsh+1,lsh+m+1);
	int qq=unique(lsh+1,lsh+m+1)-lsh-1; m=qq;
//	for(int i=1;i<=m;i++) cout<<lsh[i]<<" "; cout<<"\n";
	for(int i=n;i>=1;i--){
		int kend=tree.qry(1,1,m,lower_bound(lsh+1,lsh+m+1,posl[i])-lsh);
		if(kend==0) toend[i]=suf[i+1];
		else{
			int tmp=pre[kend]-pre[i];
			toend[i]=(tmp+mod-1)/mod*mod+toend[kend];
		}
		if(posl[i]<posr[i]){
			tree.change(1,1,m,1,lower_bound(lsh+1,lsh+m+1,posl[i])-lsh-1,i);
			tree.change(1,1,m,lower_bound(lsh+1,lsh+m+1,posr[i])-lsh,m,i);
		}
		else{
			tree.change(1,1,m,lower_bound(lsh+1,lsh+m+1,posr[i])-lsh,lower_bound(lsh+1,lsh+m+1,posl[i])-lsh-1,i);
		}
//		cout<<toend[i]<<" "; 
	}
	int q; cin>>q;
	while(q--){
		int st; cin>>st;
		int bel=upper_bound(lsh+1,lsh+m+1,st%mod)-lsh-1;
//		cout<<bel<<" ";
		int kend=tree.qry(1,1,m,bel);
//		cout<<kend<<" ";
		if(kend==0) cout<<st+pre[n+1]<<"\n";
		else cout<<(st+pre[kend]+mod-1)/mod*mod+toend[kend]<<"\n";
	}
	return 0;
}