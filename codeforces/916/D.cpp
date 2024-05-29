// LUOGU_RID: 160489327
#include<iostream>
#include<map>
using namespace std;
const int lim=1000000000;
map<string,int> mp;
string opt,s;
int vr[2],q,wz,vr2,tree[12000005],tree2[12000005],lc[12000005],rc[12000005],lc2[12000005],rc2[12000005],x,rt[100005],rt2[100005];
int modify(int p,int l,int r,int wz,int v){
	int nwrt=++vr[0];
	tree[nwrt]=tree[p];
	lc[nwrt]=lc[p];
	rc[nwrt]=rc[p];
	if(l==r){
		tree[nwrt]=v;
		return nwrt;
	}
	int mid=(l+r)>>1;
	if(wz<=mid){
		lc[nwrt]=modify(lc[p],l,mid,wz,v);
	}
	else{
		rc[nwrt]=modify(rc[p],mid+1,r,wz,v);
	}
	return nwrt;
}
int qry(int p,int l,int r,int wz){
	if(l==r){
		return tree[p];
	}
	int mid=(l+r)>>1;
	if(wz<=mid){
		return qry(lc[p],l,mid,wz);
	}
	else{
		return qry(rc[p],mid+1,r,wz);
	}
}
int modify2(int p,int l,int r,int wz,int v){
	int nwrt=++vr[1];
	tree2[nwrt]=tree2[p];
	lc2[nwrt]=lc2[p];
	rc2[nwrt]=rc2[p];
	if(l==r){
		tree2[nwrt]+=v;
		return nwrt;
	}
	int mid=(l+r)>>1;
	if(wz<=mid){
		lc2[nwrt]=modify2(lc2[p],l,mid,wz,v);
	}
	else{
		rc2[nwrt]=modify2(rc2[p],mid+1,r,wz,v);
	}
	tree2[nwrt]=tree2[lc2[nwrt]]+tree2[rc2[nwrt]];
	return nwrt;
}
int qry2(int p,int l,int r,int pl,int pr){
	if(pl<=l&&r<=pr){
		return tree2[p];
	}
	int mid=(l+r)>>1,ret=0;
	if(pl<=mid){
		ret+=qry2(lc2[p],l,mid,pl,pr);
	}
	if(mid<pr){
		ret+=qry2(rc2[p],mid+1,r,pl,pr);
	}
	return ret;
}
int main(){
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>opt;
		rt[i]=rt[i-1],rt2[i]=rt2[i-1];
		if(opt=="set"){
			cin>>s>>x;
			if(!mp[s]){
				mp[s]=++vr2;
			}
			int tmp=qry(rt[i],1,q,mp[s]);
			if(tmp){
				rt2[i]=modify2(rt2[i],1,lim,tmp,-1);
			}
			rt[i]=modify(rt[i],1,q,mp[s],x);
			rt2[i]=modify2(rt2[i],1,lim,x,1);
		}
		if(opt=="remove"){
			cin>>s;
			if(mp[s]){
				int tmp=qry(rt[i],1,q,mp[s]);
				if(tmp){
					rt[i]=modify(rt[i],1,q,mp[s],0);
					rt2[i]=modify2(rt2[i],1,lim,tmp,-1);
				}
			}
		}
		if(opt=="query"){
			cin>>s;
			int ans=0;
			if(mp[s]&&qry(rt[i],1,q,mp[s])){
				int tmp=qry(rt[i],1,q,mp[s]);
				if(tmp>=2){
					ans=qry2(rt2[i],1,lim,1,tmp-1);
				}
			}
			else{
				ans=-1;
			}
			cout<<ans<<endl;
		}
		if(opt=="undo"){
			cin>>x;
			rt[i]=rt[i-x-1];
			rt2[i]=rt2[i-x-1];
		}
	}
	return 0;
} 