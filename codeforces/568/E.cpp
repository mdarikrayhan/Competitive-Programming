#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define ls(x) x*2
#define rs(x) x*2+1
#define mp make_pair
#define sec second
#define fir first
#define pii pair<int,int>
#define lowbit(i) i&-i
using namespace std;
const int N=1e5+5,S=(1<<20)+5,mo1=1e9+9,base1=19491001,mo2=998244353,base2=19260817,inf=1e9+7;
typedef long long ll;
void read(int &p){
	int x=0,w=1;
	char ch=0;
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	p=x*w;
}
int n,m,a[N],b[N],f[N],g[N],p[N],h[N];
unordered_map<int,int>cnt;
vector<pii>mdf;
int main(){
	read(n);
	rep(i,1,n)
	    read(a[i]),f[i]=inf;
	read(m);
	rep(i,1,m)
	    read(b[i]),cnt[b[i]]++;
	sort(b+1,b+m+1);
	rep(i,1,n){
		if(a[i]!=-1){
			int le=0,ri=i-1,res=0;
			while(le<=ri){
				int mid=(le+ri)>>1;
				if(f[mid]<a[i])res=mid,le=mid+1;
				else ri=mid-1;
			}
			f[res+1]=a[i],g[res+1]=i,p[i]=g[res],h[i]=res+1;
		}
		else{
			int targ=1;
			mdf.clear();
			rep(j,1,m){
				while(targ<=i-1&&f[targ]<b[j])
				    targ++;
				mdf.push_back(mp(targ,b[j]));
			}
			for(auto j:mdf)
				f[j.fir]=min(f[j.fir],j.sec),g[j.fir]=i,p[i]=g[j.fir-1],h[i]=j.fir;
		}
	}
	int nwp=0,la=inf,ans=0;
	repp(i,n,1){
		if(g[i]){
			nwp=g[i],ans=i;
			break;
		}
	}
	while(nwp){
		if(a[nwp]!=-1)la=a[nwp],nwp=p[nwp];
		else{
			int targ=lower_bound(b+1,b+m+1,la)-b-1;
			la=a[nwp]=b[targ],cnt[b[targ]]--,targ=0;
			rep(i,1,nwp-1){
				if(a[i]==-1)continue;
				if(h[i]>=ans-1&&a[i]<a[nwp]){
					targ=i;
					break;
				}
			}
			if(!targ){
				repp(i,nwp-1,1){
					if(a[i]==-1){
						targ=i;
					    break;
					}
			    }
			}
			nwp=targ;
		}
		ans--;
		if(!ans)break;
	}
	nwp=1;
	rep(i,1,n){
		if(a[i]!=-1)continue;
		while(cnt[b[nwp]]<=0)
		    nwp++;
		cnt[b[nwp]]--,a[i]=b[nwp];
	}
	rep(i,1,n)
	    printf("%d ",a[i]);
	return 0;
}
	 					 	    	     	    				