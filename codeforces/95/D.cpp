#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=1e3;
const ll mod=1e9+7;
int n,k;
int nl,nr;
int l[N+10],r[N+10];
int len;
int lim[N+10];
ll f[N+10][N+10][2];
inline ll F(int p,int la,bool is_lk,bool is_u){
	if(!is_u&&~f[p][la][is_lk]){
		return f[p][la][is_lk];
	}
	if(!p){
		if(!is_u){
			f[p][la][is_lk]=is_lk;
		}
		return is_lk;
	}
	ll res=0;
	for(int i=0;i<=(is_u?lim[p]:9);++i){
//		ll tmp=res;
		res=(res+F(p-1,(i==4||i==7)?p:la,is_lk||(la&&(i==4||i==7)&&la-p<=k),is_u&&(i==lim[p])))%mod;
//		if(0&&p==2&&la==3&&is_lk==0&&is_u==0){
//			cout<<"###"<<i<<endl;
//			cout<<"***"<<p<<' '<<la<<' '<<is_lk<<' '<<is_u<<endl;
//			cout<<"!!!"<<p-1<<' '<<((i==4||i==7)?p:la)<<' '<<(is_lk||(la&&(i==4||i==7)&&la-p<=k))<<' '<<(is_u&&(i==lim[p]))<<endl;
//			cout<<"$$$"<<(res+mod-tmp)%mod<<endl;
//		}
	}
	if(!is_u){
		f[p][la][is_lk]=res;
	}
//	cout<<p<<' '<<la<<' '<<is_lk<<' '<<is_u<<' '<<res<<endl;
	return res;
}
inline int check(){
	int la=0;
	for(int i=1;i<=nl;++i){
		if(l[i]==4||l[i]==7){
			if(la&&i-la<=k){
				return 1;
			}
			la=i;
		}
	}
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&k);
	char ch;
	while(n--){
		nl=0;
		nr=0;
		while((ch=getchar())!=' '){
			if(isdigit(ch)){
				l[++nl]=ch-'0';
			}
		}
		while(isdigit(ch=getchar())){
			r[++nr]=ch-'0';
		}
		for(int i=1;i<=nl;++i){
			if(i<nl-i+1){
				swap(l[i],l[nl-i+1]);
			}
		}
		for(int i=1;i<=nr;++i){
			if(i<nr-i+1){
				swap(r[i],r[nr-i+1]);
			}
		}
//		for(int i=1;i<=nl;++i){
//			cout<<l[i];
//		}
//		cout<<endl;
//		for(int i=1;i<=nr;++i){
//			cout<<r[i];
//		}
//		cout<<endl;
		len=nr;
		memcpy(lim,r,sizeof(lim));
		ll ans=F(len,0,0,1);
		len=nl;
		memcpy(lim,l,sizeof(lim));
		ans=(ans+mod-F(len,0,0,1))%mod;
		printf("%lld\n",ans+check());
	}
	return 0;
}
   	    	  		  	 	 		 	   					