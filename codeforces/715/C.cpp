// LUOGU_RID: 160498481
#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long read(){
	long long x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void write(long long x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=1e5+10;
int n,s[N],t,c[N];
ll m,ans,d[N],num1[N],num2[N],m10[N],nim10[N];
vector<int>e[N],a[N],a2;
vector<ll>w[N];
vector<pair<ll,int> >a1;
pair<ll,int> gg;
bool v1[N],v2[N];
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(!b){
        x=1;y=0;
        return a;
    }
    long long d=exgcd(b,a%b,x,y);
    long long z=x;x=y;y=z-y*(a/b);
    return d;
}
long long qni_ol(long long a,long long p){
    long long x,y;
    exgcd(a,p,x,y);
    return x;
}
void add(int u,int v,ll W){
	e[u].push_back(v);
	w[u].push_back(W);
}
struct Tree_Center{
	int sum;
	int size[N],weight[N];
	int center;
	void dfs(int x,int fa){
		size[x]=1;
		weight[x]=0;
		for(int i=0;i<e[x].size();i++){
			if(e[x][i]==fa||v2[e[x][i]])
				continue;
			dfs(e[x][i],x);
			size[x]+=size[e[x][i]];
			weight[x]=max(weight[x],size[e[x][i]]);
		}
		weight[x]=max(weight[x],sum-size[x]);
		if(weight[x]<weight[center])
			center=x;
	}
	void ask(int root,int n){
		sum=n;
		weight[center=0]=1e9;
		dfs(root,0);
	}
}tree;
void dfs(int x,int fa,int col){
	s[x]=1;
	d[x]=d[fa]+1;
	for(int i=0;i<e[x].size();i++){
		if(e[x][i]==fa||v2[e[x][i]])
			continue;
		num1[e[x][i]]=(num1[x]*10%m+w[x][i])%m;
		num2[e[x][i]]=(num2[x]+w[x][i]*m10[d[x]]%m)%m;
		c[e[x][i]]=col;
		a[col].push_back(num2[e[x][i]]);
		gg.first=num1[e[x][i]];gg.second=e[x][i];
		a1.push_back(gg);
		a2.push_back(num2[e[x][i]]);
		dfs(e[x][i],x,col);
		s[x]+=s[e[x][i]];
	}
}
ll get(int col,ll need){
	return upper_bound(a[col].begin(),a[col].end(),need)-
	lower_bound(a[col].begin(),a[col].end(),need);
}
void calc(int x){
	d[x]=0;
	while(a1.size())
		a1.pop_back();
	while(a2.size())
		a2.pop_back();
	for(int i=0;i<e[x].size();i++){
		if(v2[e[x][i]])
			continue;
		while(a[e[x][i]].size())
			a[e[x][i]].pop_back();
		num1[e[x][i]]=num2[e[x][i]]=w[x][i]%m;
		c[e[x][i]]=e[x][i];
		a[e[x][i]].push_back(num2[e[x][i]]);
		gg.first=num1[e[x][i]];gg.second=e[x][i];
		a1.push_back(gg);
		a2.push_back(num2[e[x][i]]);
		dfs(e[x][i],x,e[x][i]);
		sort(a[e[x][i]].begin(),a[e[x][i]].end());
	}
	sort(a1.begin(),a1.end());
	sort(a2.begin(),a2.end());
	ll need;
	for(int i=0;i<a1.size();i++){
		if(!a1[i].first)
			ans++;
		need=(m-a1[i].first*nim10[d[a1[i].second]]%m)%m;
		ans+=upper_bound(a2.begin(),a2.end(),need)-
		lower_bound(a2.begin(),a2.end(),need)-get(c[a1[i].second],need);
	}
	for(int i=0;i<a2.size();i++)
		if(!a2[i])
			ans++;
}
void DFZ(int x,int sum){
	tree.ask(x,sum);
	int center=tree.center;
	calc(center);
	v2[center]=1;
	for(int i=0;i<e[center].size();i++){
		if(v2[e[center][i]])
			continue;
		DFZ(e[center][i],s[e[center][i]]);
	}
}
int main(){
	n=read();m=read();
	m10[0]=1;
	for(int i=1;i<=n;i++){
		m10[i]=m10[i-1]*10%m;
		nim10[i]=qni_ol(m10[i],m);
	}
	int u,v,w;
	for(int i=1;i<n;i++){
		u=read()+1;v=read()+1;w=read();
		add(u,v,w);add(v,u,w);
	}
	DFZ(1,n);
	write(ans);
	return 0;
}
