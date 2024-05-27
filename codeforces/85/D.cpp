// LUOGU_RID: 160498483
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll key,val,ls,rs,siz;
	ll sum[6];
}e[1500000];
ll cnt=0,n,m,root;
ll Newnode(ll x){
	ll h=++cnt;
	e[h].val=x;
	e[h].key=rand();
	e[h].ls=e[h].rs=0;
	e[h].siz=1;
	e[h].sum[1]=x;
	e[h].sum[2]=e[h].sum[3]=e[h].sum[4]=e[h].sum[5]=0;
	return h;
}
void Pushup(ll h){
	for(ll i=1;i<=5;i++){
		e[h].sum[i]=e[e[h].ls].sum[i]+e[e[h].rs].sum[(i+3-e[e[h].ls].siz%5)%5+1];
		if(e[e[h].ls].siz%5+1==i) e[h].sum[i]+=e[h].val;
	}
}
void zig(ll &h){
	ll t=e[h].rs,p=e[h].siz;
	e[h].siz-=e[e[t].rs].siz+1;
	e[h].rs=e[e[h].rs].ls;
	e[t].siz=p;
	e[t].ls=h;
	h=t;
}
void zag(ll &h){
	ll t=e[h].ls,p=e[h].siz;
	e[h].siz-=e[e[t].ls].siz+1;
	e[h].ls=e[e[h].ls].rs;
	e[t].siz=p;
	e[t].rs=h;
	h=t;
}
void Insert(ll &h,ll x){
	if(h==0){
		h=Newnode(x);
		return ;
	}
	else{
		e[h].siz++; 
		if(x>=e[h].val){
			Insert(e[h].rs,x);
			if(e[e[h].rs].key<e[h].key){
				zig(h);
				Pushup(e[h].ls);
			}
		}
		else{
			Insert(e[h].ls,x);
			if(e[e[h].ls].key<e[h].key){
				zag(h);
				Pushup(e[h].rs);
			}
		}
	}
	Pushup(h);
}
void Delete(ll &h,ll x){
	if(h==0) return ;
	if(e[h].val==x){
		if(e[h].ls==0||e[h].rs==0) h=e[h].ls+e[h].rs;
		else if(e[e[h].ls].key<e[e[h].rs].key){
			zag(h);
			Delete(e[h].rs,x);
		}
		else{
			zig(h);
			Delete(e[h].ls,x);
		}
	}
	else{
		if(e[h].val<x) Delete(e[h].rs,x);
		else Delete(e[h].ls,x);
	}
	if(h!=0){
		e[h].siz=e[e[h].ls].siz+e[e[h].rs].siz+1;
		Pushup(h);
	}
}
ll Rank(ll h,ll x){
	if(h==0) return 0;
	if(e[h].val>=x) return Rank(e[h].ls,x);
	else return e[e[h].ls].siz+1+Rank(e[h].rs,x);
}
ll Find(ll h,ll x){
	if(h==0) return -1;
	if(e[e[h].ls].siz>=x) return Find(e[h].ls,x);
	if(e[e[h].ls].siz+1==x) return e[h].val; 
	return Find(e[h].rs,x-e[e[h].ls].siz-1);
}
ll Front(ll h,ll x){
	if(h==0) return -1;
	if(e[h].val>=x) return Front(e[h].ls,x);
	return max(e[h].val,Front(e[h].rs,x));
}
ll Back(ll h,ll x){
	if(h==0) return 0x3f3f3f3f3f3f3f;
	if(e[h].val<=x) return Back(e[h].rs,x);
	return min(e[h].val,Back(e[h].ls,x));
}
int main(){
	e[0].key=0x3f3f3f3f3f3f3f3f;
	srand(time(NULL));
	ll x;
	cin>>n;
	string s;
	for(ll i=1;i<=n;i++){
		cin>>s;
		if(s=="sum") printf("%lld\n",e[root].sum[3]);
		else if(s=="add"){
			cin>>x;
			Insert(root,x);
		}
		else{
			cin>>x;
			Delete(root,x);
		}
	}
	return 0;
}