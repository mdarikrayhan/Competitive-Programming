// LUOGU_RID: 159378757
#include<bits/stdc++.h>
using namespace std;

constexpr int N=1e5+5;

int a[N];
map<int,int> mp[N];
vector<int> suf[N],suf2[N];

int dfs(int l,int r)
{
	if(mp[r].count(l))return mp[r][l];

	int res=0;
	for(int i:suf[r])
        if(r-i*2+1>=l)res=max(res,dfs(l,r-i)+1);
	for(int i:suf2[l])
        if(l+i*2-1<=r)res=max(res,dfs(l+i,r)+1);
	return mp[r][l]=res;
}

int main()
{
    int n,m=0,len=0;
	scanf("%d",&n);
	while(n--)
    {
        int x;
		scanf("%d",&x),a[++m]=x;
		if(a[m-1]==x)suf[m]={1};

        for(int i:suf[m-1])
            if(a[m-i*2-1]==x)suf[m].push_back(i+1);
        
        int pos=0;
        for(int i:suf[m])
            if(lower_bound(suf[m-i].begin(),suf[m-i].end(),i)!=upper_bound(suf[m-i].begin(),suf[m-i].end(),i))pos=i;
		for(int i:suf[m])suf2[m-i*2+1].push_back(i);
		if(!pos)dfs(1,m);
        else for(pos<<=1,len++;pos--;)
        {
            for(int i:suf[m])suf2[m-i*2+1].pop_back();
            suf[m].clear(),mp[m].clear(),m--;
        }

		printf("%d ",len*2+mp[m][1]);
	}

	return 0;
}