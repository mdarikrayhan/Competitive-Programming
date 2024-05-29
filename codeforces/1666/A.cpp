#include <bits/stdc++.h>
using namespace std;
char s[20010];
int n,ans=0,deg[20010],cnt=0,v[256];
int main(){
	scanf("%s",s),n=strlen(s);
	for(int i=0,j,u,l;i<n;i++) if(s[i]!='L'&&s[i]!='U'){
		for(j=i;j+1<n&&s[j]=='R'&&s[j+1]=='L';j+=2,ans++);
		if(j>=n||s[j]=='U'||s[j]=='L') continue;
		for(u=j;s[u]!='U'&&u<n;u++);
		if(u>=n) continue;
		for(l=j+1;l+1<n&&s[l]=='L';l++);l--;
		int m=s[j]=='R'?u-j:u-l;
		fill(deg+i,deg+n,0),cnt=0;
		v['L']=-1,v['R']=1,v['U']=-m,v['D']=m;
		for(int k=i;k+m<=n;k+=m){
			bool fl=0;
			if(s[k]=='L'||s[k+m-1]=='R') break;
			for(int p=k;p<k+m;p++){
				if(deg[p]) cnt++;
				int q=p+v[s[p]];
				if(deg[q]){
					fl=1;
					break;
				}
				deg[q]++;
				if(q<p) cnt++;
			}
			if(fl) break;
			if(k>=j&&cnt==k+m-i) ans++;
		}
	}
	printf("%d\n",ans);
}