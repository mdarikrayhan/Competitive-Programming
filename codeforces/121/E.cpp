// LUOGU_RID: 160494862
//From: ifffer_2137
#include <bits/stdc++.h>
using namespace std;
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
const int maxb=350;
const int maxm=1e4+5;
int tb[35]={0,4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777};
int n,m,B;
int a[maxn],id[maxn];
int v[maxb][maxm],tag[maxb];
int check(int x){
	while(x){
		if(x%10!=4&&x%10!=7) return 0;
		x/=10;
	}
	return 1;
}
signed main(){
	cin.tie(0),cout.tie(0);
	n=read(),m=read();
	B=sqrt(n)*2;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		int k=(i-1)/B+1;
		v[k][a[i]]++;
		id[i]=k;
	}
	while(m--){
		string op;
		cin>>op;
		if(op=="add"){
			int x=read(),y=read(),k=read();
			if(id[x]==id[y]){
				for(int i=x;i<=y;i++){
					v[id[x]][a[i]]--;
					a[i]+=k;
					v[id[x]][a[i]]++;
				}
				continue;
			}
			for(int i=id[x]+1;i<=id[y]-1;i++) tag[i]+=k;
			int t=min(n,id[x]*B);
			for(int i=x;i<=t;i++){
				v[id[x]][a[i]]--;
				a[i]+=k;
				v[id[x]][a[i]]++;
			}
			for(int i=(id[y]-1)*B+1;i<=y;i++){
				v[id[y]][a[i]]--;
				a[i]+=k;
				v[id[y]][a[i]]++;
			}
		}else{
			int x=read(),y=read();
			int ans=0;
			if(id[x]==id[y]){
				for(int i=x;i<=y;i++) ans+=check(a[i]+tag[id[x]]);
				cout<<ans<<endl;
				continue;
			}
			for(int i=id[x]+1;i<=id[y]-1;i++){
				for(int j=1;j<=30;j++){
					if(tb[j]-tag[i]>=1) ans+=v[i][tb[j]-tag[i]];
				}
			}
			int t=min(n,id[x]*B);
			for(int i=x;i<=t;i++) ans+=check(a[i]+tag[id[x]]);
			for(int i=(id[y]-1)*B+1;i<=y;i++) ans+=check(a[i]+tag[id[y]]);
			cout<<ans<<endl;
		}
	}
	return 0;
}