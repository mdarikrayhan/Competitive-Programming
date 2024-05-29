// LUOGU_RID: 159966600
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using V=array<int,4>;
using CV=const V&;
const int K=65,M=22,N=4005;
int A,B,C,D,mi[M][M][M][M];
ll ans,f[N],g[N];
int sum(CV x) {return x[0]+x[1]+x[2]+x[3];}
bool chk(int x,int k){
	int s=k*(k+1)/2;
	return s>=x&&(s-x)%2==0;
}
int val(int x){
	for(int k=sqrt(x*2);;k++) if(chk(x,k-1)) return k-1;
}
V add(V x,int o,int v) {x[o]=abs(x[o]+v);sort(begin(x),end(x));return x;}
int&pos(CV x) {return mi[x[0]][x[1]][x[2]][x[3]];}
void dfs(int i,V x){
	pos(x)=min(pos(x),i-1);
	if(i>6) return;
	for(int o:{0,1,2,3}) for(int t:{-1,1}) dfs(i+1,add(x,o,i*t));
}
set<V> s[K];
int main(){
	cin>>A>>B>>C>>D;
	memset(mi,0x3f,sizeof mi);
	dfs(1,{0,0,0,0});
	for(int a=0;a*4<M;a++) for(int b=a;a+b*3<M;b++) for(int c=b;a+b+c*2<M;c++) for(int d=c;a+b+c+d<M;d++){
		V x{a,b,c,d};
		for(int i=2;i<7;i++) if(chk(sum(x),i)&&pos(x)>i) s[i].insert(x);
	}
	for(int i=7;i<K;i++){
		auto ok=[&](CV x){
			for(int o:{0,1,2,3}) for(int t:{-1,1}){
				V y=add(x,o,i*t);
				if(chk(sum(y),i-1)&&!s[i-1].count(y)) return 0;
			}
			return 1;
		};
		for(V x:s[i-1]) for(int o:{0,1,2,3}) for(int t:{-1,1}){
			V y=add(x,o,i*t);
			if(chk(sum(y),i)&&ok(y)) s[i].insert(y);
		}
	}
	f[0]=1;
	for(int x:{A,B,C,D}){
		memset(g,0,sizeof g);
		for(int i=-x;i<=x;i++) for(int w=abs(i),j=w;j<N;j++) g[j]+=f[j-w];
		swap(f,g);
	}
	for(int i=1;i<N;i++) ans+=val(i)*f[i];
	V lim{A,B,C,D};
	for(int i=2;i<K;i++){
		int j=i+1;
		while(j*(j+1)/2%2!=i*(i+1)/2%2) j++;
		for(V x:s[i]) do{
			int p=1;
			for(int o:{0,1,2,3})
				if(x[o]>lim[o]) p=0;
				else if(x[o]) p*=2;
			ans+=(j-i)*p;
		}while(next_permutation(begin(x),end(x)));
	}
	cout<<ans;
	return 0;
}