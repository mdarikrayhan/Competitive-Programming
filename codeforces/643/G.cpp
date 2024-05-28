#include<bits/stdc++.h>
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN =  3e5+7;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f;
int a[MAXN];
int k;
struct Info {
	vector<array<int,2>> vec;
};
bool bj(array<int,2> a,array<int,2> b){
    return a[1]>b[1];
}
Info operator +(const Info &a,const Info &b) {
	Info c;
	c=a;
    for(auto &p:b.vec){
        int flag=0;
        for(auto &q:c.vec){
            if(q[0]==p[0]){
                q[1]+=p[1];
                flag=1;
                break;
            }
        }
        if(!flag) c.vec.push_back(p);
    }
    sort(c.vec.begin(),c.vec.end(),bj);
    while(c.vec.size()>k){
        for(auto &p:c.vec){
            p[1]-=(*c.vec.rbegin())[1];
        }
        c.vec.pop_back();
    }
	return c;
}
struct node {
    int lazy;
	Info val;
} seg[MAXN<<2];
void up(int id) {
	seg[id].val=seg[id<<1].val+seg[id<<1|1].val;
}
void settag(int id,int l,int r,int tag) {
	seg[id].val.vec.clear();
    seg[id].val.vec.push_back({tag,r-l+1});
	seg[id].lazy=tag;
}
void down(int id,int l,int r) {
	if(seg[id].lazy==-1) return;
	int mid=l+r>>1;
	settag(id<<1,l,mid,seg[id].lazy);
	settag(id<<1|1,mid+1,r,seg[id].lazy);
	seg[id].lazy=-1;
}
void build(int id,int l,int r) {
    seg[id].lazy=-1;
	if(l==r) {
		seg[id].val.vec.push_back({a[l],1});
		
		return;
	}
	int mid = l+r>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	up(id);
}
void modify(int id,int l,int r,int ql,int qr,int val) {
	if (ql==l&&r==qr) {
		settag(id,l,r,val);
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
Info query(int id,int l ,int r,int ql,int qr) {
	if(ql==l&&r==qr) {
	return seg[id].val;
	}
	down(id,l,r);
	int mid=l+r>>1;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}
void solve(){
	int n,q;cin>>n>>q>>k;
    k=100/k;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int op;cin>>op;
        int l,r;cin>>l>>r;
        int id;
        if(op==1){
            cin>>id;
            modify(1,1,n,l,r,id);
        } 
        else{
            auto it=query(1,1,n,l,r).vec;
            cout<<it.size()<<" ";
            for(auto &p:it) cout<<p[0]<<" ";
            cout<<"\n";
        }
    }

}
signed main(){
    close;
	solve();
}
