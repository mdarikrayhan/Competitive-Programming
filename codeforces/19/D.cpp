// LUOGU_RID: 160419785
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>

using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
	return x*f;
}

string reads() {
	char ch=getchar();
	string s;
	while(isspace(ch))ch=getchar();
	for(;!isspace(ch);ch=getchar())s+=ch;
	return s;
}

void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}

const int M=2e5+5;

class segment_tree{
public:
	void build(int sz){
		for(size=1;size<sz+2;size<<=1);
	}
	void update(int x,int val){
		_update(size+x,val);
	}
	bool q(int l,int r,int y){
		return _q(size+l-1,size+r+1)>=y;
	}
private:
	int size;
	int tree[M<<2];
	void _update(int x,int val){
		tree[x]=val;
		for(int i=x>>1;i;i>>=1)tree[i]=max(tree[i<<1],tree[i<<1|1]);
	}
	int _q(int l,int r){
		int res=0;
		for(;l^1^r;l>>=1,r>>=1){
			if(~l&1)res=max(res,tree[l^1]);
			if(r&1)res=max(res,tree[r^1]);
		}
		return res;
	}
}t;
int n;
vector<int> x;
using iter=vector<int>::iterator;
set<int> y[M];
unordered_map<int,int> umap;
int aumap[M];
int cnt=0;
using obj=tuple<string,int,int>;
vector<obj> vec;

void add(int a,int b){
	y[a].insert(b);
	if(*y[a].rbegin()==b)t.update(a,b);
	return;
}

void remove(int a,int b){
	y[a].erase(b);
	if(y[a].empty())t.update(a,0);
	else if(b>*y[a].rbegin())t.update(a,*y[a].rbegin());
	return;
}

iter lb(int a,int b){
	iter l=lower_bound(x.begin(),x.end(),a),r=x.end(),it;
	if(l==x.end())return l;
	r--;
	for(;l<r;){
		it=l+(r-l)/2;
		if(t.q(*l,*it,b))r=it;
		else l=it,l++;
	}
	it=l+(r-l)/2;
	return it;
}

void find(int a,int b){
	iter it=lb(a+1,b+1);
	if(it==x.end())return putchar('-'),putchar('1'),putchar('\n'),void();
	if(y[*it].empty()||*y[*it].rbegin()<=b)return putchar('-'),putchar('1'),putchar('\n'),void();
	return write(aumap[*it]),putchar(' '),write(*y[*it].upper_bound(b)),putchar('\n'),void();
}

int main(){
	n=read();
	vector<int> x0,y0;
	string opt;
	int a,b;
	while(n--){
		opt=reads(),a=read(),b=read();
		vec.emplace_back(opt,a,b);
		x0.push_back(a);
	}
	sort(x0.begin(),x0.end());
	x0.erase(unique(x0.begin(),x0.end()),x0.end());
	for(auto i:x0)umap[i]=++cnt,aumap[cnt]=i;
	t.build(cnt);
	for(auto &[opt,a,b]:vec){
		a=umap[a];
		if(opt=="add")x.push_back(a);
	}
	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	for(auto [opt,a,b]:vec){
		if(opt=="add")add(a,b);
		else if(opt=="remove")remove(a,b);
		else find(a,b);
	}
	return 0;
}