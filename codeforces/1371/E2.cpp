// LUOGU_RID: 159877313
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
int n,p;
int a[maxn];
map<int,int> cnt;
vector<int> ans;
signed main(){
	cin.tie(0),cout.tie(0);
	n=read(),p=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	a[n+1]=a[n]+1;
	for(int i=a[n]-n+1;i<=a[n];i++){
		int t=upper_bound(a+1,a+n+1,i)-a-1;
		cnt[(i-t+p)%p]++;
	}
	int k=max(0ll,a[n]-n+1);
	for(int x=k;x<=a[n];x++){
		if(!cnt[x%p]) ans.eb(x);
		int t=upper_bound(a+1,a+n+1,x)-a-1;
		cnt[(x-t+p)%p]--;
		t=upper_bound(a+1,a+n+1,x+n)-a-1;
		cnt[(x+n-t+p)%p]++;
	}
	cout<<ans.size()<<endl;
	for(int x:ans) cout<<x<<" ";
	cout<<endl;
	return 0;
}