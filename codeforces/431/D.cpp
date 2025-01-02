// LUOGU_RID: 159800429
//From: ifffer_2137
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x7fffffff
#define eb emplace_back
#define pii pair<int,int>
#define mkpr make_pair
#define fir first
#define sec second
inline int read(){
    char ch=getchar();int x=0,w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48,ch=getchar();return w==1?x:-x;
}
int C[65][65];
int n,k;
string bt(int x){
	string s="";
	while(x){
		s=char('0'+(x&1))+s;
		x/=2;
	}
	return s;
}
int count(int x){
	string s=bt(x);
	int cnt=0,one=0;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(!(s[i]-'0')) continue;
		if(k<one) break;
		cnt+=C[l-i-1][k-one];
		one++;
	}
	return cnt;
}
int calc(int x){
	return count(x*2)-count(x);
}
signed main(){
	cin.tie(0),cout.tie(0);
	for(int i=0;i<=64;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
	n=read(),k=read();
	int l=1,r=1e18,ans=0;
	while(l<=r){
		int m=(l+r)/2;
		int x=calc(m);
		if(x==n){
			ans=m;
			break;
		}else if(x<n){
			l=m+1;
		}else{
			r=m-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}