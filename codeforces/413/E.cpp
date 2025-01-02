// LUOGU_RID: 159029452
#include<bits/stdc++.h>
#define ls u<<1
#define rs u<<1|1
using namespace std;
struct node{
	int l,r,d1,d2,d3,d4;//
}t[800001];
string s1,s2;
void build(int u,int l,int r){
	t[u].l=l,t[u].r=r;
	t[u].d1=t[u].d2=t[u].d3=t[u].d4=1000000000;
	if(l==r){
		if(s1[l]=='.')t[u].d1=0;
		if(s2[l]=='.')t[u].d3=0;
		if(s1[l]=='.'&&s2[l]=='.')t[u].d2=t[u].d4=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[u].d1=min(1000000000,min(t[ls].d1+t[rs].d1,t[ls].d2+t[rs].d4)+1);
	t[u].d2=min(1000000000,min(t[ls].d1+t[rs].d2,t[ls].d2+t[rs].d3)+1);
	t[u].d3=min(1000000000,min(t[ls].d3+t[rs].d3,t[ls].d4+t[rs].d2)+1);
	t[u].d4=min(1000000000,min(t[ls].d3+t[rs].d4,t[ls].d4+t[rs].d1)+1);
}
node query(int u,int l,int r){
	if(t[u].l>=l&&t[u].r<=r){
		return t[u];
	}
	int mid=(t[u].l+t[u].r)>>1;
	if(l<=mid&&r<=mid)return query(ls,l,r);
	else if(l>mid&&r>mid)return query(rs,l,r);
	else{
		node p,q,ans={1000000000,1000000000,1000000000,1000000000};
		p=query(ls,l,r);
		q=query(rs,l,r);
		ans.d1=min(1000000000,min(p.d1+q.d1,p.d2+q.d4)+1);
	    ans.d2=min(1000000000,min(p.d1+q.d2,p.d2+q.d3)+1);
	    ans.d3=min(1000000000,min(p.d3+q.d3,p.d4+q.d2)+1);
	    ans.d4=min(1000000000,min(p.d3+q.d4,p.d4+q.d1)+1);
	    return ans;
	}
}
void solve(){
	int n,q;
	cin>>n>>q;
	cin>>s1>>s2;
	s1=" "+s1;
	s2=" "+s2;
	build(1,1,n);
	while(q--){
		int u,v;
		cin>>u>>v;
		if(u<=n&&v<=n){
			if(u>v)swap(u,v);
			node ans=query(1,u,v);
			cout<<(ans.d1==1000000000?-1:ans.d1)<<endl;
		}
		else if(u>n&&v>n){
			u-=n,v-=n;
			if(u>v)swap(u,v);
			node ans=query(1,u,v);
			cout<<(ans.d3==1000000000?-1:ans.d3)<<endl;
		}
		else if(u<=v&&v>n){
			v-=n;
			if(u>=v){
				node ans=query(1,v,u);
				cout<<(ans.d4==1000000000?-1:ans.d4)<<endl;
			}
			else{
				node ans=query(1,u,v);
				cout<<(ans.d2==1000000000?-1:ans.d2)<<endl;
			}
		}
		else{
			u-=n;
			if(u>=v){
				node ans=query(1,v,u);
				cout<<(ans.d2==1000000000?-1:ans.d2)<<endl;
			}
			else{
				node ans=query(1,u,v);
				cout<<(ans.d4==1000000000?-1:ans.d4)<<endl;
			}
		}
	}
}
signed main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	} 
}