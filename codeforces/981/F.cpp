// LUOGU_RID: 158177582
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N=8e5+5;
int n,L,a[N],b[N],al[N],ar[N];
int read(){
	int w=0,f=1;
	char c=getchar();
	while (c>'9'||c<'0'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		w=(w<<3)+(w<<1)+(c^48);
		c=getchar();
	}
	return w*f;
}
bool check(int x){
    for (int l=1,r=0,i=n+1;i<=n*3;i++){
        while (r<n*4&&b[r+1]-a[i]<=x) ++r;
        while (l<=r&&a[i]-b[l]>x) ++l;
        al[i]=l,ar[i]=r;
    }
    //cout<<x<<"\n";
    //for (int i=n+1;i<=n+n;i++) cout<<al[i]<<" "<<ar[i]<<"\n";
    int maxn=-3e9;
    for (int i=n+1;i<=n*3;i++){
        maxn=max(maxn,al[i]-i);
        //cout<<"===="<<i<<" "<<maxn<<" "<<al[i]<<'\n';
        if (ar[i]-i<maxn) return 0;
    }
    return 1;
}
signed main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
#endif  
    n=read(),L=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++) b[i]=read();
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for (int i=1;i<=n+n;i++) a[i+n]=a[i]+L;
    for (int i=1;i<=n*3;i++) b[i+n]=b[i]+L;
    int l=0,r=L/2,ans=0;
    while (l<=r){
        int mid=l+r>>1;
        if (check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<"\n";
	return 0;
}
 