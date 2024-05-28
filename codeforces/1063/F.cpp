// LUOGU_RID: 159199219
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,P=13331,mod=1000003;
int n,sum[N],pw[N],mp[mod];
string s;
bool f[2][N];
int gethash(int l,int r) {return (sum[r]-1ll*sum[l-1]*pw[r-l+1]%mod+mod)%mod;}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>s,s=' '+s;
	int ans=1,p=0,q=1;
	pw[0]=1;
	for(int i=1;i<=n;i++) f[p][i]=1,pw[i]=1ll*pw[i-1]*P%mod;
	for(int i=1;i<=n;i++) sum[i]=(1ll*sum[i-1]*P%mod+s[i]-'a'+1)%mod;
	while(1)
	{
		memset(f[q],0,sizeof(f[q]));
		memset(mp,0,sizeof(mp));
		for(int i=n;i>=1;i--) if(f[p][i])
		{
			int val=gethash(i,i+ans-1);
			if(!mp[val]) mp[val]=i;
			else
			{
				if(i-1+ans<mp[val]) f[q][i-1]=1;
				if(i+ans<mp[val]) f[q][i]=1;
			}
		}
		bool flg=0;
		for(int i=1;i<=n;i++) flg|=f[q][i];
		if(!flg) break;
		ans++,swap(p,q);
	}
	cout<<ans;
	return 0;
}