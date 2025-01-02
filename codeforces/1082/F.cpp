// LUOGU_RID: 160434809
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
int N,K,l[509],r[509],va[509],s[509],dep[509],p[509],s2[509],
ch[509][10],cnt,k=1,dp[509][12],la[509][12];char ss[509];
bool cmp(int mm,int nn) {
	return l[mm]<l[nn];
}
void dfs(int n) {
	l[n]=cnt+1;
	if(va[n]) s[++cnt]=va[n]*dep[n],s2[cnt]=va[n];
	for(int i=0;i<10;i++) {
		if(ch[n][i]) dep[ch[n][i]]=dep[n]+1,dfs(ch[n][i]);
	}
	r[n]=cnt;
	p[n]=n;
}
void sv(int n) {
	for(int i=0;i<10;i++) {
		if(ch[n][i]) sv(ch[n][i]);
	}
	memset(la,0x3f,sizeof(la));la[0][0]=0;
	l[0]=r[0]=l[n]-1;r[k+1]=l[k+1]=r[n]+1;
	for(int i=1;i<=k+1;i++) {
		if((r[p[i]]<l[n]||l[p[i]]>r[n])&&i!=k+1) continue;
		for(int j=0;j<i;j++) {
			if(j>0&&r[p[j]]<l[n]) continue;
			if(r[p[j]]<l[p[i]]) {
				int x=r[p[j]]+1,y=l[p[i]]-1;
				int v1=s[y]-s[x-1]-(s2[y]-s2[x-1])*dep[n];
				//printf("%d %d %d %d\n",n,i,j,v1);
				for(int k=0;k<=K+1;k++) {
					if(la[j][k]==INF) continue;
					for(int l=0;l+k<=K+1;l++) {
						la[i][k+l]=std::min(la[i][k+l],
						la[j][k]+dp[p[i]][l]+v1);
					}
				}
			}
		}
	}
	for(int l=0;l<=K;l++) dp[n][l+1]=la[k+1][l];
}
signed main(void) {
	scanf("%d %d",&N,&K);
	for(int i=1;i<=N;i++) {
		int w;
		scanf("%s %d",ss+1,&w);
		int q=1;
		for(int j=1;ss[j];j++) {
			if(!ch[q][ss[j]-'0']) ch[q][ss[j]-'0']=++k;
			q=ch[q][ss[j]-'0'];
		}
		va[q]+=w;
	}
	memset(dp,0x3f,sizeof(dp));dp[k+1][0]=0;
	dfs(1);
	for(int i=1;i<=cnt;i++) s[i]+=s[i-1];
	for(int i=1;i<=cnt;i++) s2[i]+=s2[i-1];
	std::sort(p+1,p+k+1,cmp);p[k+1]=k+1;
	sv(1);
	int as=INF;
	for(int i=1;i<=K+1;i++) as=std::min(as,dp[1][i]);
	printf("%d",as);
}