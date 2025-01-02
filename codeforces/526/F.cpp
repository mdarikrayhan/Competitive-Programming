// LUOGU_RID: 160209970
#include<bits/stdc++.h>
using namespace std;
const int MaxN=300000;
struct Node{
	int min,tmin;
	int add;
	int l,r;
}tree[MaxN*4+1];
int Left(int u){return u<<1;}
int Right(int u){return u<<1|1;}
void PushDown(int u){
	tree[Left(u)].min+=tree[u].add;
	tree[Left(u)].add+=tree[u].add;
	tree[Right(u)].min+=tree[u].add;
	tree[Right(u)].add+=tree[u].add;
	tree[u].add=0;
}
void PushUp(int u){
	tree[u].min=min(tree[Left(u)].min,tree[Right(u)].min);
	if(tree[Left(u)].min<tree[Right(u)].min)
		tree[u].tmin=tree[Left(u)].tmin;
	else if(tree[Left(u)].min==tree[Right(u)].min)
		tree[u].tmin=tree[Left(u)].tmin+tree[Right(u)].tmin;
	else
		tree[u].tmin=tree[Right(u)].tmin;
}
void Add(int u,int l,int r,int add){
	if(r<tree[u].l||tree[u].r<l)return;
	if(l<=tree[u].l&&tree[u].r<=r){
		tree[u].add+=add;
		tree[u].min+=add;
		return;
	}
	PushDown(u);
	Add(Left(u),l,r,add);
	Add(Right(u),l,r,add);
	PushUp(u);
}
pair<int,int>Ask(int u,int l,int r){
	if(r<tree[u].l||tree[u].r<l)return make_pair(INT_MAX,0);
	if(l<=tree[u].l&&tree[u].r<=r)return make_pair(tree[u].min,tree[u].tmin);
	auto pi1=Ask(Left(u),l,r),pi2=Ask(Right(u),l,r);
	if(pi1.first<pi2.first)
		return pi1;
	else if(pi1.first==pi2.first)
		return make_pair(pi1.first,pi1.second+pi2.second);
	else
		return pi2;
}
void Build(int u,int l,int r){
	tree[u].l=l,tree[u].r=r;
	if(l==r){
		tree[u].min=0,tree[u].tmin=1;
		return;
	}
	int mid=(l+r)/2;
	Build(Left(u),l,mid);
	Build(Right(u),mid+1,r);
	PushUp(u);
}
int n,a[MaxN+1];
void Solve(){
	cin>>n;
	Build(1,1,n);
	for(int i=1,x;i<=n;i++)cin>>x,cin>>a[x];
	stack<int,vector<int> >smin,smax;
	long long ans=0;
	for(int i=1;i<=n;i++){
		Add(1,i,i,a[i]);
		while(smax.size()&&a[smax.top()]<a[i]){
			int last=smax.top();
			smax.pop();
			Add(1,smax.size()?smax.top()+1:1,last,a[i]-a[last]);
		}
		smax.push(i);
		Add(1,i,i,-a[i]);
		while(smin.size()&&a[smin.top()]>a[i]){
			int last=smin.top();
			smin.pop();
			Add(1,smin.size()?smin.top()+1:1,last,a[last]-a[i]);
		}
		smin.push(i);
		Add(1,1,i-1,-1);
		auto pi=Ask(1,1,i);
//		cout<<pi.first<<' '<<pi.second<<'\n';
		if(pi.first==0)ans+=pi.second;
	}
	cout<<ans;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
//	int T;
//	cin>>T;
//	while(T--)
		Solve();
	return 0;
}
//