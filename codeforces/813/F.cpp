// LUOGU_RID: 160442558
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const int N=2e5+5,M=4e5+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
inline void Swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
	return;
}
struct edge{
	int u,v;
	bool operator <(edge x)const{
		if(u!=x.u)return u<x.u;
		return v<x.v;
	}
}e[M];
vector<edge> g[N<<1];
map<edge,int>mp;
int n,q,k,st[N<<1],top;
int f[N<<1],siz[N<<1];
inline int find(int u){
	if(u==f[u])return u;
	return find(f[u]);
}
inline void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(siz[x]>siz[y])Swap(x,y);
	f[x]=y;
	siz[y]+=siz[x];
	st[++top]=x;
    return;
}
inline void del(int x){
	siz[f[x]]-=siz[x];
	f[x]=x;
	return;
}
void update(int l,int r,int u,edge x,int ll,int rr){
	if(l>rr||r<ll)return;
	if(l>=ll&&r<=rr){
		g[u].push_back(x);
		return;
	}
	int mid=(l+r)>>1;
	update(l,mid,u<<1,x,ll,rr);
	update(mid+1,r,u<<1|1,x,ll,rr);
	return;
}
void query(int l,int r,int u){
	int flag=1,now=top;
	for(int i=0;i<g[u].size();i++){
		int x=g[u][i].u;
		int y=g[u][i].v;
		if(find(x)==find(y)){
			for(int k=l;k<=r;k++)puts("NO");
			flag=0;
			break;
		}
		merge(x,y+n);
		merge(y,x+n);
	}
	if(flag){
		if(l==r)puts("YES");
		else{
			int mid=(l+r)>>1;
			query(l,mid,u<<1);
			query(mid+1,r,u<<1|1);
		}
	}
	while(top>now)del(st[top--]);
	return;
}
int main(){
	n=read(),q=read();
	for(int i=1;i<=n<<1;i++)f[i]=i,siz[i]=1;
	for(int i=1;i<=q;i++){
        e[i].u=read(),e[i].v=read();
        if(e[i].u>e[i].v)swap(e[i].u,e[i].v);
        if(mp.find(e[i])==mp.end())mp[e[i]]=i;
		else{
			update(1,q,1,e[i],mp[e[i]],i-1);
            mp.erase(e[i]);
		}
    }
    for(auto i:mp)update(1,q,1,i.first,i.second,q);
	query(1,q,1);
	return 0;
}
/*
我好想做嘉然小姐的狗啊。
可是嘉然小姐说她喜欢的是猫，我哭了。 
我知道既不是狗也不是猫的我为什么要哭的。因为我其实是一只老鼠。
我从没奢望嘉然小姐能喜欢自己。我明白的，所有人都喜欢理解余裕上手天才打钱的萌萌的狗狗或者猫猫，没有人会喜欢阴湿带病的老鼠。
但我还是问了嘉然小姐:“我能不能做你的狗?”
我知道我是注定做不了狗的。但如果她喜欢狗，我就可以一直在身边看着她了，哪怕她怀里抱着的永远都是狗。
可是她说喜欢的是猫。
她现在还在看着我，还在逗我开心，是因为猫还没有出现，只有我这老鼠每天蹑手蹑脚地从洞里爬出来，远远地和她对视。
等她喜欢的猫来了的时候，我就该重新滚回我的洞了吧。
但我还是好喜欢她，她能在我还在她身边的时候多看我几眼吗?
嘉然小姐说接下来的每个圣诞夜都要和大家一起过。我不知道大家指哪些人。好希望这个集合能够对我做一次胞吞。
猫猫还在害怕嘉然小姐。
我会去把她爱的猫猫引来的。
我知道稍有不慎，我就会葬身猫口。
那时候嘉然小姐大概会把我的身体好好地装起来扔到门外吧。
那我就成了一包鼠条，嘻嘻。
我希望她能把我扔得近一点，因为我还是好喜欢她。会一直喜欢下去的。
我的灵魂透过窗户向里面看去，挂着的铃铛在轻轻鸣响，嘉然小姐慵懒地靠在沙发上，表演得非常温顺的橘猫坐在她的肩膀。壁炉的火光照在她的脸庞，我冻僵的心脏在风里微微发烫。
*/