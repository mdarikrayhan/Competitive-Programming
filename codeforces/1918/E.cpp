// LUOGU_RID: 160482936
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<ctime>
#include<cmath>
#include<cctype>
#include<bitset>
#include<vector>
#include<cstdio>
#include<random>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
#define INF 1e9
#define LLINF 1e18
#define ll long long
#define N 2005
using namespace std;
int read(){
	int x=0,f=1,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f=(ch=='-')?-1:1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
void print(int x){
	if(x<0) putchar('-'),x=~(x-1);
	if(x>9) print(x/10);
	putchar(x%10+48);
}
int n,ans[N],p[N];
vector<int>vec;
char query(int p){
	printf("? %d\n",p);fflush(stdout);
	char c;cin>>c;return c;
}
void tox(int p){
	char tmp;
	do{tmp=query(p);}while(tmp!='=');
}
void solve(vector<int>v,int l){
	if(v.empty()) return;
	if(v.size()==1){
		ans[v[0]]=l+1;
		return;
	}
	if(v.size()==2){
		tox(v[0]);
		char c=query(v[1]);
		if(c=='>') ans[v[0]]=l+1,ans[v[1]]=l+2;
		else ans[v[0]]=l+2,ans[v[1]]=l+1;
		return;
	}
	random_shuffle(v.begin(),v.end());
	int p=rand()%v.size();
	tox(v[p]);vector<int>v1,v2;
	for(int i=0;i<v.size();++i){
		if(i==p) continue;
		char op=query(v[i]);
		if(op=='>') v1.push_back(v[i]);
		else v2.push_back(v[i]);
		query(v[p]);
	}
	ans[v[p]]=l+v2.size()+1;
	solve(v1,v2.size()+1+l),solve(v2,l);
}
int main(){
	int T=read();
	while(T--){
		srand(time(NULL));
		n=read();vec.clear();
		for(int i=1;i<=n;++i) vec.push_back(i);
		random_shuffle(vec.begin(),vec.end());
		solve(vec,0);printf("! ");
		for(int i=1;i<=n;++i) printf("%d ",ans[i]);
		puts("");fflush(stdout);
		for(int i=1;i<=n;++i) ans[i]=0;
	}
	return 0;
}