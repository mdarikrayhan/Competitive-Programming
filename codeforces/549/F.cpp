// LUOGU_RID: 158567919
// Problem: Yura and Developers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF549F
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// Genshin Impact launch
// ZYB TXDY
// 
// Powered by CP Editor (https://cpeditor.org)

//%^~
#include <bits/stdc++.h>
#define INF 0x7fffffff
#define MAXN 300005
#define eps 1e-9
#define foru(a,b,c)	for(int a=b;a<=c;a++)
#define RT return 0;
#define LL long long
#define LXF int
#define RIN rin()
#define HH printf("\n")
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using namespace std;
inline LXF rin(){
	LXF x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){ 
	if(ch=='-') w=-1;
	ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
	x=x*10+(ch-'0');
	ch=getchar();
	}
	return x*w;
}
int n;
int a[MAXN];
int k;
LL s[MAXN];
int lf[MAXN];
int rf[MAXN];
stack<int> st;
LL ans;
vector<int> pos[1000005];
int vask(vector<int>& ls,int r){
	if(r<0)	return 0;
	return upper_bound(all(ls),r)-ls.begin();
}
int getx(int l,int r,int x){
	// int ret=0;
	// foru(i,l,r){
		// ret+=(s[i]%k==x);
	// }
	return vask(pos[x],r)-vask(pos[x],l-1);
}
signed main(){
	n=RIN,k=RIN;
	foru(i,1,n){
		a[i]=RIN;
		s[i]=(s[i-1]+a[i])%k;
	}
	foru(i,0,n){
		pos[s[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		while(!st.empty() && a[st.top()]<=a[i])	st.pop();
		if(st.empty())	lf[i]=0;
		else	lf[i]=st.top();
		st.push(i);
	}
	while(!st.empty())	st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty() && a[st.top()]<a[i])	st.pop();
		if(st.empty())	rf[i]=n+1;
		else	rf[i]=st.top();
		st.push(i);
	}
	
	foru(i,1,n){
		LL r=a[i]%k;
		if(i-lf[i] < rf[i]-i){
			foru(j,lf[i]+1,i){
				LL x=(s[j-1]+r+k)%k;
				ans+=getx(i,rf[i]-1,x);
			}
		}else{
			foru(j,i,rf[i]-1){
				LL x=(s[j]-r+k)%k;
				ans+=getx(lf[i],i-1,x);
			}
		}
	}
	cout<<ans-n;
	return 0;
}