#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define ls(x) lson[x]
#define rs(x) rson[x]
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second
#define pb push_back
using namespace std;
typedef long long ll;
const int N=2e5+5,M=1e6+2,inf=1e9+7,bs=19491001;
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
int n,m,d[N],app[N],le=inf,ri;
ll ans=0;
vector<pii>res;
int main(){
	read(n);
	rep(i,1,n)
	    read(d[i]);
	repp(i,n,2)
	    d[i]-=d[i-1];
	read(m);
	rep(i,1,m){
		int x;
		read(x);
		le=min(le,x),ri=max(ri,x);
		app[x]++;
	}
	rep(i,1,n)
	    app[i]*=2;
	int stp=1;
	while(stp<=n){
		if(!app[stp]){
			stp++;
			continue;
		}
		int nw=stp;
		while(nw<=n){
			if(nw==n||!app[nw+1]){
				app[nw]--,res.push_back(mp(stp,nw));
				break;
			}
			if(nw==stp)app[nw]--;
			else if(app[nw]==1){
				app[nw]--,res.push_back(mp(stp,nw));
				break;
			}
			else app[nw]-=2;
			nw++;
		}
	}
	int cnts=0,cnto=0;
	for(auto i:res)
        cnts+=(i.fir==i.sec),cnto+=(i.fir+1==i.sec);
    if(!cnts&&cnto){
    	for(auto i:res){
    		if(i.fir+1==i.sec){
    			ans-=(ll)d[i.sec];
    			break;
    		}
    	}
    }
    else if(!cnts){
    	int targ=d[ri];
    	bool sme=1;
    	rep(i,le+1,ri)
    	    if(d[i]!=targ)sme=0;
    	if(!sme){
    		puts("-1");
    		return 0;
    	}
    	else ans-=(ll)targ;
    }
    rep(i,2,n)
        d[i]+=d[i-1];
    for(auto i:res)
        ans+=(ll)d[i.sec]-d[i.fir];
    printf("%lld\n",ans);
    return 0;
}
				  	  	  		 		 	 			   	  		