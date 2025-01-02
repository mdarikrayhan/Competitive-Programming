// LUOGU_RID: 160253565
#include<bits/stdc++.h>
#include<unordered_map>
#pragma GCC optimize(2)
using namespace std;
//#define int long long
#define endl '\n'
#define x first
#define y second
#define ll pair<int,int>
#define _up(x) (int)ceil(1.0*x)
const int mod=998244353;
/*int power(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a %mod;
        a = a * a%mod;
        b >>= 1;
    }
    return res;
}*/
/*int find(int a,int s){
	if(a!=fa[s][a]) fa[s][a]=find(fa[s][a],s);
	return fa[s][a];
}
void merge(int a,int b,int s){
	a=find(a,s),b=find(b,s);
	if(a!=b){
		fa[s][a]=b;
		//si[b]+=si[a];
	}
}*/
const int N=1e5+10;
int a[N],f[N],nex[N],pre[N];
vector<int>v;
vector<int>q[N];
vector<int>ans(N);
int n;
int op;
int lowbit(int x){
	return x&(-x);
}
void modify(int x,int k){
	for(int i=x;i<N;i+=lowbit(i)){
		f[i]+=k;
	}
}
int get(int k){
	int pos=0;
	int sum=0;
	for(int i=20;i>=0;i--){
		if(pos+(op<<i)<=n&&sum+f[pos+(op<<i)]<=k){
			pos+=(op<<i);
			sum+=f[pos];
		}
	}
	return pos;
}
void solve(){//其实这里树状数组倍增都只是一个简单的工具吧和值域线段树上二分差不多啊，这里其实是在用值域树状数组啊。 
	cin>>n;
	op=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(pre[a[i]]!=0){
			nex[pre[a[i]]]=i;
		}
		else{
			v.push_back(i);
			modify(i,1);
		}
		pre[a[i]]=i;
	}//这里的操作其实不太好写的啊。 
	for(int i=1;i<=n;i++){
		q[1].push_back(i);
	}
	for(int i=0;i<n;i++){
		if(i){
			modify(i,-1);
			if(nex[i]) modify(nex[i],1);
		}
		for(auto p:q[i+1]){
			ans[p]++;
			q[get(p)+1].push_back(p);
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int w=1;
	//cin>>w;
    while (w--){
        solve();
    }
    return 0;
}