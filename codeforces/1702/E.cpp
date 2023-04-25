#include <bits/stdc++.h>
using namespace std;
int t,n,fa[200005],cnt[200005],num[200005];
inline int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
signed main()
{cin>>t;
while(t--){
cin>>n;
bool flag=0;
for(int i=1;i<=n;i++)
fa[i]=i,cnt[i]=num[i]=0;
for(int i=1;i<=n;i++){
	int x,y;
	cin>>x>>y;
	num[x]++,num[y]++;
    x=find(x),y=find(y);
	fa[x]=y;
}
for(int i=1;i<=n;i++){
	cnt[find(i)]++;
}
for(int i=1;i<=n;i++)
if((cnt[i]&1)||(num[i]!=2))
flag=1;
if(flag)
cout<<"NO"<<endl;
else
cout<<"YES"<<endl;
}
}