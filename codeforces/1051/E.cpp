#include<bits/stdc++.h>
using namespace std;
typedef long long ull;
typedef long long ll;
const int N=1e6+5;
const ull P=131;
const ll mod=998244353;
const ll MD=1e9+9;
int n,m,k,len;
char a[N],l[N],r[N];
ull p[N],ha[N],hl[N],hr[N];
int zr[N];
int gzr(int l,int r){
	return zr[r]-zr[l-1];
}
ull a_get(int l,int r){
	return (ha[r]-ha[l-1]*p[r-l+1]%MD+MD)%MD;
}
ull l_get(int l,int r){
	return (hl[r]-hl[l-1]*p[r-l+1]%MD+MD)%MD;
}
ull r_get(int l,int r){
	return (hr[r]-hr[l-1]*p[r-l+1]%MD+MD)%MD;
}
bool l_chk(int l_,int r_){
	if(!l_)return 0;
	int len=r_-l_+1;
	if(len>m){
		len=len-m;
		if(gzr(l_,l_+len-1)==len){
			l_+=len;
		}
		else{
			return 1;
		}
		len=r_-l_+1;
	}
	if(len<m)return 0;
	int p=-1,L=1,R=len,mid;
	while(L<=R){
		mid=L+((R-L)>>1);
		if(a_get(l_,l_+mid-1)!=l_get(1,mid)){
			p=mid;
			R=mid-1;
		}
		else{
			L=mid+1;
		}
	}
	if(p==-1)return 1;
	if(a[l_+p-1]<l[p]){
		return 0;
	}
	return 1;
}
bool r_chk(int l_,int r_){
	if(!l_)return 0;
	int len=r_-l_+1;
	if(len>k){
		len=len-k;
		if(gzr(l_,l_+len-1)==len){
			l_+=len;
		}
		else{
			return 0;
		}
		len=r_-l_+1;
	}
	if(len<k)return 1;
	int p=-1,L=1,R=len,mid;
	while(L<=R){
		mid=L+((R-L)>>1);
		if(a_get(l_,l_+mid-1)!=r_get(1,mid)){
			p=mid;
			R=mid-1;
		}
		else{
			L=mid+1;
		}
	}
	if(p==-1)return 1;
	if(r[p]<a[l_+p-1]){
		return 0;
	}
	return 1;
}
ll f[N],sf[N];
ll Q(int l,int r){
	if(l>r)return 0;
	if(!l)return sf[r];
	return (sf[r]+mod-sf[l-1])%mod;
}
int main(){
	scanf("%s",a+1);
	scanf("%s",l+1);
	scanf("%s",r+1);
	for(int i=1;a[i];i++,n++){
		zr[i]=zr[i-1]+(a[i]=='0');
	}
	for(int i=1;l[i];i++,m++);
	for(int i=1;r[i];i++,k++);
	len=max(max(n,m),k);
	p[0]=1;
	for(int i=1;i<=len;i++){
		p[i]=p[i-1]*P%MD;
		ha[i]=(ha[i-1]*P%MD+a[i])%MD;
		hl[i]=(hl[i-1]*P%MD+l[i])%MD;
		hr[i]=(hr[i-1]*P%MD+r[i])%MD;
	}
	f[0]=1;
	sf[0]=1;
	int fl=0,fr=0;
	for(int r=1;r<=n;r++){
		while(fr+1<=r-1&&l_chk(fr+1,r)){
			fr++;
		}
		while(fl+1<=r-1&&!r_chk(fl,r)){
			fl++;
		}
		if(l_chk(fr,r)&&r_chk(fl,r)&&fl<=fr){
			f[r]=Q(fl-1,fr-1);
		}
		if(l_chk(r,r)&&r_chk(r,r)){
			f[r]=(f[r]+f[r-1])%mod;
		}
		if(a[r+1]=='0'){
			sf[r]=sf[r-1];
		}
		else{
			sf[r]=(sf[r-1]+f[r])%mod;
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}
/*
8698272232067125804692796793285996652907461532074057999849092982935510140661249431760679611642931478
6
68270

336970248
*/