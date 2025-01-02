// LUOGU_RID: 159104386
#include<bits/stdc++.h>
#define mod1 998244853
#define mod2 1000000009
#define int long long
using namespace std;
int n,m,cnt[310],num[310][2],h[505],b[255][255][255],now[255][2],a[255],s[505],ans,p[605],tot;
char c[255][255];
void manacher(int ll,int rr){
        if(ll>rr)return;
        int tot=0,l=1,r=1;s[++tot]=-1;
        for(int i=ll;i<=rr;i++)s[++tot]=a[i],s[++tot]=-1;
	memset(h,0,sizeof h),h[1]=1;
	for(int i=2;i<=tot;i++){
		if(i<=r)h[i]=min(r-i+1,h[l+r-i]);
		while(i+h[i]<=tot&&i-h[i]>=1&&s[i+h[i]]==s[i-h[i]])h[i]++;
		if(i+h[i]-1>r)l=i-h[i]+1,r=i+h[i]-1;
	}
	for(int i=1;i<=tot;i++)ans+=h[i]/2;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
        for(int i=2;tot<=600;i++){
        	int flag=0;
        	for(int j=2;j*j<=i;j++)flag|=(i%j==0);
        	if(!flag)p[++tot]=i;
	}
	for(int i=1;i<=300;i++)num[i][0]=p[i],num[i][1]=p[i*2];
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>c[i][j];
        for(int k=1;k<=n;k++)for(int i=1;i<=m;i++){
        	int nw=0;
        	for(int j=i;j<=m;j++){
        		cnt[c[k][j]]++;
        		if(cnt[c[k][j]]&1)nw++;
        		else nw--;
        		if(nw<=1)b[k][i][j]=1;
		}
		for(int j=i;j<=m;j++)cnt[c[k][j]]--;
	}
	for(int i=1;i<=m;i++){
		for(int k=1;k<=n;k++)now[k][0]=now[k][1]=1;
		for(int j=i;j<=m;j++){
			int nw=1;
			for(int k=1;k<=n;k++){
				now[k][0]=now[k][0]*num[c[k][j]][0]%mod1;
				now[k][1]=now[k][1]*num[c[k][j]][1]%mod2;
				a[k]=(now[k][0]<<30)+now[k][1];
				if(!b[k][i][j])manacher(nw,k-1),nw=k+1;
			}
			manacher(nw,n);
		}
	}
    cout<<ans;
    return 0;
}