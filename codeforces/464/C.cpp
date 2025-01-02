// LUOGU_RID: 158926966
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
const int maxn=1e5+5;
const int mod=1e9+7;
string s;
int n,q,ans;
int a[maxn];
string t[maxn];
int d[10],v[10];
signed main(){
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	q=read();
	for(int i=1;i<=q;i++){
		a[i]=read();
		cin>>t[i];
	}
	for(int i=0;i<=9;i++){
		d[i]=10;
		v[i]=i;
	}
	for(int i=q;i>=1;i--){
		if(t[i]==">"){
			d[a[i]]=1;
			v[a[i]]=0;
			continue;
		}
		int l=t[i].size();
		int nv=0,nd=1;
		for(int j=1;j<l;j++){
			nd=nd*d[t[i][j]-'0']%mod;
			nv=(nv*d[t[i][j]-'0']%mod+v[t[i][j]-'0'])%mod;
		}
		d[a[i]]=nd;v[a[i]]=nv;
	}
	for(int i=0;i<n;i++){
		ans=(ans*d[s[i]-'0']%mod+v[s[i]-'0'])%mod;
	}
	cout<<ans<<endl;
	return 0;
}
//Begin: 20:54
//Finish: 21:01