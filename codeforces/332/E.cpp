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
#define pb push_back
using namespace std;
typedef long long ll;
const int N=605,M=205,mo=998244353,inf=1e9+7,bs=19491001;
const double eps=1e-7;
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
string p,s;
int n,m,k;
string ans;
bool check(int num,int id,int npos){
	int targ=id-1;
	for(int i=npos;i<n;i+=k){
		if(targ>=m||s[targ]!=p[i])return 0;
		targ+=num;
	}
	return 1;
}
string solve(int cnt){
	string res;
	rep(i,0,k-1)
	    res.push_back('0');
	int frn=m-n/k*cnt,bkn=cnt-frn;
	repp(i,k-1,n%k){
		if(!bkn)break;
		if(check(cnt,bkn+frn,i))res[i]='1',bkn--;
	}
	if(bkn)return ans;
	repp(i,n%k-1,0){
		if(!frn)return res;
		if(check(cnt,frn,i))res[i]='1',frn--;
	}
	if(!frn)return res;
	return ans;
}
int main(){
	getline(cin,p),getline(cin,s);
	read(k),n=p.size(),m=s.size();
	rep(i,1,k+1)
	    ans.push_back('1');
    rep(i,1,m){
    	int len=n/k;
    	if(len*i>m||(len+1)*i<m)continue;
    	ans=min(ans,solve(i));
    }
    if((int)ans.size()==k+1)printf("0");
    else cout<<ans;
    return 0;
}
  	 		 					  		 		 		 	 		 	