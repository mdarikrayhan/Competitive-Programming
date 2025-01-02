// LUOGU_RID: 159932269
//Man always remember love because of romance only!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int n=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) n=(n<<3)+(n<<1)+(ch^48),ch=getchar();
    return w?-n:n;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,k;
int c[500005];
bool check1(int x){
	int now=0;
	for(int i=1;i<=n;i++){
		if(c[i]>x) now+=c[i]-x;
	}
	return now<=k;
}
bool check2(int x){
	int now=0;
	for(int i=1;i<=n;i++){
		if(c[i]<x) now+=x-c[i];
	}
	return now<=k;
}
signed main(){
	n=read(),k=read();
	int r1=0,sum=0;
	for(int i=1;i<=n;i++){
		c[i]=read();
		sum+=c[i];
		r1=max(r1,c[i]);
	}
	int l1;
	if(sum%n==0) l1=sum/n;
	else l1=sum/n+1;
	while(l1<r1){
		int mid=(l1+r1)/2;
		if(check1(mid)) r1=mid;
		else l1=mid+1;
	}
	int l2=1,r2=sum/n;
	while(l2<r2){
		int mid=(l2+r2+1)/2;
		if(check2(mid)) l2=mid;
		else r2=mid-1;
	}
	write(l1-l2);
	return 0;
}
