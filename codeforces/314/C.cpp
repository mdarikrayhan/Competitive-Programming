// LUOGU_RID: 160508031
#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int ans=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=(ans<<1)+(ans<<3)+ch-'0';
		ch=getchar();
	}
	return w*ans;
}
const int V=1e6,mod=1e9+7;
int n;
int a[100005];
int f[200005];
int pre[1000005];
int tree[1000005];
int lowbit(int i){
	return i&-i;
}
void add(int pos,int val){
	for(int i=pos;i<=V;i+=lowbit(i))tree[i]=(tree[i]+val)%mod;
}
int ask(int pos){
	int ans=0;
	for(int i=pos;i;i-=lowbit(i))ans=(ans+tree[i])%mod;
	return ans;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		f[i]=(ask(a[i])+1)*a[i]%mod;
		if(pre[a[i]]){
			add(a[i],-f[pre[a[i]]]);
			f[pre[a[i]]]=0;
		}
		pre[a[i]]=i;
		add(a[i],f[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=((ans+f[i])%mod+mod)%mod;
	}
	cout<<ans<<'\n';
	
}