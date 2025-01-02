#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline LL read(){
	LL x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

const int MAXN = 100010;
const int INF = 1e9;
const LL PW = 10000000LL;
const LL PW2 = 1000000LL;
LL Pw;

int T; int s[2][11][1000010]; LL N,K;
inline void dfs1(int d,int k,int x,int last,LL nw,int fr,int frt){
	if(k==8){
		s[d][fr][(nw-frt+N)%N]++;
		//if(nw%N==38483&&fr==2) cout<<"yest:"<<nw<<endl;
		return ;
	} 
	for(int i=0;i<10;i++)
		if((k==1||((last<i)^x))&&i!=last) 
			dfs1(d,k+1,(k==1?x:(last<i)),i,nw*10+i,(k==1?i:fr),(k==1?i:frt*10));
	return ;
} LL D=0;
inline void dfs4(int k,int x,int last,LL nw,LL lft){
	if(k==8){
		if(nw%N==lft) {
			--K;
			if(!K){
				printf("%lld\n",D*PW+nw);
				exit(0);
			}
		} return ;
	}
	for(int i=0;i<10;i++)
		if(((last<i)^x)&&i!=last) 
			dfs4(k+1,(last<i),i,nw*10+i,lft);
}
inline void Find(int l,int r,int last,LL lft){
	LL t=lft;
	lft=(lft-l*Pw%N+N)%N;
	for(int i=l;i<r;i++){
		if(i!=last){
			if(lft<PW2){
				if(K<=s[last<i][i][lft]) 
					dfs4(2,(last<i),i,i,t);
				K-=s[last<i][i][lft];
			}
		}
		lft=lft-Pw; if(lft<0) lft+=N;
	} return ;
}
inline void dfs2(int k,int x,int last,LL nw,int fr,int frt){
	if(k==8){
		D=nw;
		if(!nw) return ;
		//cout<<nw<<endl;
		LL lft=nw*PW%N;
		//if(nw==180) cout<<5270103%N<<" "<<lft<<":"<<last<<" "<<x<<" "<<lft<<endl;
		lft=(lft?N-lft:0);
		if(lft>=PW) return ;
		if(nw<10){
			Find(0,10,last,lft);
		} else if(x){
			Find(0,last,last,lft);
		} else{
			//if(nw==180) dgx
			Find(last+1,10,last,lft);
		} return ;
	} if(!nw) last=-1;
	for(int i=0;i<10;i++)
		if((k<=2||nw<10||((last<i)^x))&&i!=last) 
			dfs2(k+1,(k==1?2:(last<i)),i,nw*10+i,(k==1?i:fr),(k==1?i:frt*10));
	return ;
}
inline void dfs3(int k,int x,int last,LL nw){
	if(k==T){
		if(nw%N==0) --K;//cout<<nw<<endl;
		if(!K){
			printf("%lld\n",nw);
			exit(0);
		}
		return ;
	} if(!nw) last=-1;
	for(int i=(k==1?1:0);i<10;i++)
		if((k<=2||nw<10||((last<i)^x))&&i!=last) 
			dfs3(k+1,(k==1?2:(last<i)),i,nw*10+i);
	return ;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(),K=read(); Pw=(PW/10)%N;
	//cout<<"tt:"<<Pw<<endl;
	dfs1(0,1,0,-1,0,0,0);
	dfs1(1,1,1,-1,0,0,0);
	for(int i=2;i<=8;i++) {T=i; dfs3(1,2,-1,0);}
	dfs2(1,2,-1,0,0,0); puts("-1");
	return 0;
}
  		 	 			   					  	 			 	 		