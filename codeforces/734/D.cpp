#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll x[500005],y[500005],x0,y0;
char s[500005][3];
int main(){
	scanf("%d%lld%lld",&n,&x0,&y0);
	for(int i=0;i<n;i++){
		scanf("%s%lld%lld",s[i],&x[i],&y[i]);
		x[i]-=x0;y[i]-=y0;
	}
	bool flag=false;
	for(int i=0;i<8;i++){
		int pos=-1;
		for(int j=0;j<n;j++)
			if(x[j]==0&&y[j]>0&&(pos==-1||y[j]<y[pos])) pos=j;
		if(pos!=-1&&s[pos][0]!='B') flag=true;
		for(int j=0;j<n;j++){
			if(s[j][0]=='B') s[j][0]='R';
			else if(s[j][0]=='R') s[j][0]='B';
			ll nx=x[j],ny=y[j];
			x[j]=nx-ny;y[j]=nx+ny;
		}
	}
	if(flag) puts("YES");
	else puts("NO"); 
	return 0;
}