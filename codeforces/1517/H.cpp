// author: xay5421
// created: Tue Oct 26 21:13:01 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T,n;
struct seg{
	int l,r;
	seg operator&(const seg&k)const{
		return (seg){max(l,k.l),min(r,k.r)};
	}
	void operator&=(const seg&k){
		l=max(l,k.l),r=min(r,k.r);
	}
	bool operator==(const seg&k)const{return l==k.l&&r==k.r;}
	bool isbad()const{return l>r;}
};
int main(){ // fake solution
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		vector<seg>X(n),Y(n-1),Z(n-2);
		rep(i,0,n-1)scanf("%d%d",&X[i].l,&X[i].r);
		rep(i,0,n-2)scanf("%d%d",&Y[i].l,&Y[i].r);
		rep(i,0,n-3)scanf("%d%d",&Z[i].l,&Z[i].r);
		puts(([&](){
			for(int tc=0;;++tc){
				if(tc>n)return 0;
				vector<seg>X_=X,Y_=Y,Z_=Z;
				rep(i,0,n-2){
					Y[i]&=(seg){X[i+1].l-X[i].r,X[i+1].r-X[i].l};
					X[i+1]&=(seg){X[i].l+Y[i].l,X[i].r+Y[i].r};
					if(i<n-2){
						Z[i]&=(seg){Y[i+1].l-Y[i].r,Y[i+1].r-Y[i].l};
						Y[i+1]&=(seg){Y[i].l+Z[i].l,Y[i].r+Z[i].r};
					}
				}
				per(i,n-1,1){
					if(i<n-1){
						Y[i-1]&=(seg){Y[i].l-Z[i-1].r,Y[i].r-Z[i-1].l};
					}
					X[i-1]&=(seg){X[i].l-Y[i-1].r,X[i].r-Y[i-1].l};
				}
				if(X==X_&&Y==Y_&&Z==Z_)break;
				for(auto&x:X)if(x.isbad())return 0;
				for(auto&x:Y)if(x.isbad())return 0;
				for(auto&x:Z)if(x.isbad())return 0;
			}
			return 1;
		})()?"YES":"NO");
	}
	return 0;
}