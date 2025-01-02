#include<bits/stdc++.h>
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN =  1e5+7;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f;
#define int ll
int a[MAXN];
set<int> se;
struct Info {
	int mn,now;
};
Info operator +(const Info &a,const Info &b) {
	Info c;
	if(a.mn<b.mn){
		c.mn=a.mn;
		c.now=a.now;
	} 
	else{
		c.mn=b.mn;
		c.now=b.now;
	}
	return c;
}
struct node {
	int lazy;
    int cg;
	Info val;
} seg[MAXN<<2];
void up(int id) {
	seg[id].val=seg[id<<1].val+seg[id<<1|1].val;
}
void settag(int id,int l,int r,int tag) {
    seg[id].val.now+=tag;
    seg[id].val.mn=*(se.lower_bound(seg[id].val.now))-seg[id].val.now;
    if(seg[id].cg==-1)
	seg[id].lazy+=tag;
    else seg[id].cg+=tag;
}
void stcg(int id,int tag){
    seg[id].val.now=tag;
    seg[id].val.mn=*(se.lower_bound(seg[id].val.now))-seg[id].val.now;
    seg[id].lazy=0;
    seg[id].cg=tag;
}
void down(int id,int l,int r) {
    if(seg[id].cg!=-1){
        stcg(id<<1,seg[id].cg);
        stcg(id<<1|1,seg[id].cg);
        seg[id].cg=-1;
    }
	if(seg[id].lazy!=0){
        int mid=l+r>>1;
	    settag(id<<1,l,mid,seg[id].lazy);
	    settag(id<<1|1,mid+1,r,seg[id].lazy);
	    seg[id].lazy=0;
    }
	
}
void build(int id,int l,int r) {
    seg[id].cg=-1;
	if(l==r) {
		seg[id].val.now=a[l];
        seg[id].val.mn=*(se.lower_bound(a[l]))-a[l];
		seg[id].lazy=0;
		return;
	}
	int mid = l+r>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	up(id);
}
void modify(int id,int l,int r,int ql,int qr,int val) {
	if (ql==l&&r==qr&&(seg[id].cg!=-1||seg[id].val.mn>val)) {
		settag(id,l,r,val);
		return;
	}
    if(l==r){
        seg[id].val.now+=val;
        seg[id].val.mn=*(se.lower_bound(seg[id].val.now))-seg[id].val.now;
        // if(seg[id].val.mn==0){
        //     seg[id].val.now+=val;
        //     seg[id].val.mn=*(se.lower_bound(seg[id].val.now))-seg[id].val.now;
        // }
        return;
    }
	down(id,l,r);
	int mid =(l+r) >> 1;
	if (qr<=mid)
		modify(id <<1,l,mid,ql,qr,val);
	else if (ql>mid)
		modify(id<<1|1, mid+1,r,ql,qr,val);
	else {
		modify(id<<1,l,mid,ql,mid,val);
		modify(id<<1|1,mid+1,r,mid+1,qr,val);
	}
	up(id);
}
int getmin(int id,int l,int r,int ql,int qr){
    if(ql==l&&qr==r){
        return seg[id].val.mn;
    }
    down(id,l,r);
    int mid=l+r>>1;
    if(qr<=mid) return getmin(id<<1,l,mid,ql,qr);
    else if(ql>mid) return getmin(id<<1|1,mid+1,r,ql,qr);
    else{
        return min(getmin(id<<1,l,mid,ql,mid),getmin(id<<1|1,mid+1,r,mid+1,qr));
    }
}
int query(int id,int l,int r,int pos){
    if(l==r){
        return seg[id].val.now;
    }
    int mid=l+r>>1;
    down(id,l,r);
    if(pos<=mid) return query(id<<1,l,mid,pos);
    else return query(id<<1|1,mid+1,r,pos);
}
void change(int id,int l,int r,int ql,int qr,int val){
    if(ql==l&&qr==r){
        stcg(id,val);
        return;
    }
    down(id,l,r);
    int mid =(l+r) >> 1;
	if (qr<=mid)
		change(id <<1,l,mid,ql,qr,val);
	else if (ql>mid)
		change(id<<1|1, mid+1,r,ql,qr,val);
	else {
		change(id<<1,l,mid,ql,mid,val);
		change(id<<1|1,mid+1,r,mid+1,qr,val);
	}
    up(id);
}
void solve(){
    int now=42;
    while(now<=1e16){
        se.insert(now);
        now*=42;
    }
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int op;cin>>op;
        if(op==1){
            int pos;cin>>pos;
            cout<<query(1,1,n,pos)<<"\n";
        }
        else if(op==2){
            int a,b,x;cin>>a>>b>>x;
            change(1,1,n,a,b,x);
        }
        else{
            int a,b,x;cin>>a>>b>>x;
            modify(1,1,n,a,b,x);
            while(getmin(1,1,n,a,b)==0){
                modify(1,1,n,a,b,x);
            }
        }
    }
}
signed main(){
    close;
	solve();
}
