// LUOGU_RID: 160388083
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int Max=2e5+10;
int n,q;
struct node {
	int l;
	int r;
	int minn;
	bool lazy;
} tree[Max<<2];
void build(int k,int l,int r){
	tree[k].l=l;
	tree[k].r=r;
	tree[k].minn=0x3f3f3f3f;
	if(l==r){
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void pushup(int k){
	tree[k].minn=min(tree[k<<1].minn,tree[k<<1|1].minn);
}
void change(int k,int pos,int dt){
	if(tree[k].l>pos||tree[k].r<pos){
		return;
	}
	if(tree[k].l==tree[k].r){
		tree[k].minn=min(tree[k].minn,dt);
		return;
	}
	change(k<<1,pos,dt);
	change(k<<1|1,pos,dt);
	pushup(k);
}
int ask(int k,int l,int r){
	if(tree[k].l>r||tree[k].r<l){
		return 0x3f3f3f3f;
	}
	if(l<=tree[k].l&&tree[k].r<=r){
		return tree[k].minn;
	}
	return min(ask(k<<1,l,r),ask(k<<1|1,l,r));
}
set<int> s;
bool flag[Max];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<=n+1;i++){
		s.insert(i);
	}
	build(1,1,n);
	int op,l,r,x;
	for(int i=1;i<=q;i++){
		cin>>op;
		if(op==0){
			cin>>l>>r>>x;
			if(x==0){
				int now=*s.lower_bound(l);
				while(now<=r){
					s.erase(now);
//					cout<<now<<' ';
					flag[now]=1;
					now=*s.lower_bound(l);
				}
			} else {
				change(1,l,r);
			}
		} else {
			cin>>x;
			if(flag[x]){
				cout<<"NO\n";
				continue;
			}
			l=*(--s.lower_bound(x))+1;
			r=*(s.upper_bound(x))-1;
//			cout<<ask(1,l,x)<<' ';
			if(ask(1,l,x)<=r){
				cout<<"YES\n";
			} else {
				cout<<"N/A\n";
			}
		}
	}
	return 0;
}

/*
  time:
  mem:
 */