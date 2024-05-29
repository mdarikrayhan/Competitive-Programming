// LUOGU_RID: 158289775
// 2024 HOPE IN VALUABLE
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int inf=1000000005;
int n,op,lst,cnt,le[N],ri[N],f[N][2],pre[N][2],ans[N]; ll a[N];
inline ll calc(int x){ return 1ll*x*(x+1)/2; }
inline bool chk(int ql,int qr,ll v){
	int l=0,r=qr-ql+1,pos=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(calc(ql+mid-1)-calc(ql-1)<=v) pos=mid,l=mid+1;
		else r=mid-1;
	}
	return calc(qr)-calc(qr-pos)>=v;
}
inline void find(int l,int r,ll v){
	if(!v) return;
	if(l<r&&chk(l+1,r,v)) find(l+1,r,v);
	else ans[l]=1,find(l+1,r,v-l);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]; reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++) if(a[i]){
		if(!lst) le[++cnt]=i;
		else if(a[i]<a[lst]) ri[cnt]=lst,le[++cnt]=i;
		lst=i;
	}	ri[cnt]=lst;
	for(int i=1;i<=cnt+1;i++) f[i][0]=f[i][1]=-1;
	f[cnt+1][1]=n+1; ri[0]=-1; le[cnt+1]=n+1;
	for(int i=cnt;i;i--){
		int l=le[i],r=ri[i],nxtl=le[i+1],prer=ri[i-1];
		for(int x=0;x<2;x++){
			if(!x&&a[l]!=a[r]) continue;
			if(x&&l<r&&a[l]==a[r]) continue;
			for(int y=0;y<2;y++){
				if(f[i+1][y]<r) continue;
				ll tar=a[l]-(x^1)+(y^1)-a[nxtl];
				int tmp=l; if(!x&&i==1) tmp=r;
				if(tar<tmp) tmp=tar;
				int lim=x?l:prer+1;
				while(tmp>=lim&&((!x&&a[tmp])||!chk(r+1,min(f[i+1][y],nxtl)-1,tar-tmp))) tmp--;
				if(tmp>=lim&&tmp>f[i][x]) f[i][x]=tmp,pre[i][x]=y;
			}
		}
	}
	for(int i=1,x=(f[1][0]==-1);i<=cnt;i++){
		int l=le[i],r=ri[i],y=pre[i][x],nxtl=le[i+1];
		ll tar=a[l]-(x^1)+(y^1)-a[nxtl];
		ans[f[i][x]]=1;
		find(r+1,min(f[i+1][y],nxtl)-1,tar-f[i][x]);
		x=y;
	}
	reverse(ans+1,ans+n+1); for(int i=1;i<=n;i++) cout<<ans[i];
	return 0;
}