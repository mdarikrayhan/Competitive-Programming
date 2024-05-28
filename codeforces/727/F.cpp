// LUOGU_RID: 159987936
#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second
#define pb push_back
#define int long long 
using namespace std;
typedef long long ll;
const int N=2e5+5,M=40005,inf=1e9+7,bs=19491001;
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
int n,m;
int a[N];
vector<int>val;
priority_queue<int>q;
signed main(){
	read(n),read(m);
	rep(i,1,n)
	    read(a[i]);
	repp(i,n,1){
		if(a[i]<0)q.push(a[i]);
	    else{
	    	int nwv=a[i];
	    	while(nwv&&!q.empty()){
	    		int nv=q.top();
	    		q.pop();
	    		if(nwv+nv<0)q.push(nwv+nv),nwv=0;
	    		else nwv+=nv;
	    	}
	    }
	}
	while(!q.empty())
	    val.push_back(-q.top()),q.pop();
	rep(i,0,(int)val.size()-1)
	    val[i]+=!i?0:val[i-1];
	while(m--){
		int x;
		read(x);
		int targ=upper_bound(val.begin(),val.end(),x)-val.begin();
		printf("%lld\n",(int)val.size()-targ);
	}
	return 0;
}