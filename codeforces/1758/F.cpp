#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,c[N];
vector<pair<int,int> >add,del;
set<pair<int,int> >s;
void Add(int x,int k){for(;x<=2e5;x+=x&-x)c[x]+=k;}
int ask(int x) {
	if(x<0||x>2e5)return 0;
	int res=0;for(;x;x-=x&-x)res+=c[x];
	return res;
}
void merge(int l,int r) {
	auto it=s.lower_bound({l,-1e9});
	if(it==s.end()||(*it).second>r)return add.push_back({l,r}),s.insert({r,l}),void();
	int tl=(*it).second,tr=(*it).first;del.push_back({tl,tr}),s.erase(it);
	int x=min(r,tr)-max(l,tl)+1;
	merge(min(l,tl),max(r,tr)+x);
}
int Ask(int x) {
	if(x<1||x>2e5)return -1;
	return ask(x)-ask(x-1);
}
void split(int x) {
	auto it=s.lower_bound({x,-1e9});
	int l=(*it).second,r=(*it).first,p=2;del.push_back({l,r}),s.erase(it);
	while(p&&l<=r&&Ask(l)==-1)l++,p--;
	while(p&&l<=r&&Ask(r)==-1)r--,p--;
	if(!p) {
		if(l<r)add.push_back({l,r}),s.insert({r,l});
		return;
	}
	int t1=ask(l-1),t2=ask(r),res=0;
	for(int i=l;i<=r;i++)if(ask(i)-t1==0&&t2-ask(i+p)==0){res=i;break;}
	add.push_back({l,res}),add.push_back({res+p+1,r}),s.insert({res,l}),s.insert({r,res+p+1});
}
void print() {
	printf("%d\n",del.size());
	for(auto i:del)printf("%d %d\n",i.first,i.second);
	printf("%d\n",add.size());
	for(auto i:add)printf("%d %d\n",i.first,i.second);puts("");
}
int main() {
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=2e5;i++)Add(i,-1);
	for(int i=1,x;i<=n;i++) {
		scanf("%d",&x);
		add.clear(),del.clear();
		if(ask(x)-ask(x-1)==1)Add(x,-2),split(x);
		else Add(x,2),merge(x,x+1);
		print();
	}
	return 0;
}