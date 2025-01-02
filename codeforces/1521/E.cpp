// LUOGU_RID: 160219684
#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define ls(x) x*2
#define rs(x) x*2+1
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second 
using namespace std;
typedef long long ll;
const int N=605,M=2e5+5,mo=998244353,inf=998244353,bs=19491001;
const double eps=1e-8;
inline void read(int &p){
	int x=0,w=1;
	char ch=getchar();
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
int T;
int n,m,ans[N][N];
pii c[M];
int gettp(int x,int y){
	x^=1,y^=1;
	return ((x&1)<<1)+(y&1);
}
bool check(int x){
	int num[4];
	rep(i,0,3)
	    num[i]=0;
	rep(i,1,x){
		rep(j,1,x)
		    num[gettp(i,j)]++;
	}
	if(num[0]+num[1]+num[2]<m||num[0]+num[1]<c[n].fir)return 0;
	return 1;
}
void print(int x){
	rep(i,1,x){
		rep(j,1,x)
		    ans[i][j]=0;
	}
	int nwn=n;
	rep(i,1,x){
		rep(j,1,x){
			if(gettp(i,j)!=1)continue;
			while(nwn&&!c[nwn].fir)
			    nwn--;
			if(!nwn)return;
			ans[i][j]=c[nwn].sec,c[nwn].fir--;
		}
	}
	rep(i,1,x){
		rep(j,1,x){
			if(gettp(i,j)!=0)continue;
			while(nwn&&!c[nwn].fir)
			    nwn--;
			if(!nwn)return;
			ans[i][j]=c[nwn].sec,c[nwn].fir--;
		}
	}
	rep(i,1,x){
		rep(j,1,x){
			if(gettp(i,j)!=2)continue;
			while(nwn&&!c[nwn].fir)
			    nwn--;
			if(!nwn)return;
			ans[i][j]=c[nwn].sec,c[nwn].fir--;
		}
	}
}
void solve(){
	read(m),read(n);
	rep(i,1,n)
	    read(c[i].fir),c[i].sec=i;
	sort(c+1,c+n+1);
	int le=1,ri=450,res=0;
	while(le<=ri){
		int mid=(le+ri)>>1;
		if(check(mid))res=mid,ri=mid-1;
		else le=mid+1; 
	}
	print(res);
	printf("%d\n",res);
	rep(i,1,res){
		rep(j,1,res)
		    printf("%d ",ans[i][j]);
		puts("");
	}
}
int main(){
	read(T);
	while(T--)
	    solve();
	return 0;
}