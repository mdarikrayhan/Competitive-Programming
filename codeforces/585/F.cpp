// LUOGU_RID: 158595176
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e3+5,M=25e3+5,P=1e9+7;
int n,m,K,ch[M][10],nxt[M],tot=1; char s[N],sl[55],sr[55]; bool vw[M];
void buildAC(){
	queue<int> q; q.push(1); for(int i=0;i<10;i++) ch[0][i]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<10;i++){
			if(ch[u][i]) nxt[ch[u][i]]=ch[nxt[u]][i],q.push(ch[u][i]);
			else ch[u][i]=ch[nxt[u]][i];
		}
	}
}
int f[2][M][2][2][2];
int main(){
	scanf("%s%s%s",s+1,sl+1,sr+1); n=strlen(s+1); m=strlen(sl+1); K=m/2;
	for(int i=1;i<=n-K+1;i++){
		int u=1;
		for(int j=i;j<=i+K-1;j++){
			int c=s[j]-'0';
			if(!ch[u][c]) ch[u][c]=++tot;
			u=ch[u][c];
		} vw[u]=1;
	} buildAC(); int nw=0;
	f[0][1][1][1][0]=1;
	for(int i=1;i<=m;i++){
		nw^=1;
		for(int u=1;u<=tot;u++) 
			for(int li=0;li<2;li++) for(int ri=0;ri<2;ri++) for(int sc=0,bf;sc<2;sc++) if((bf=f[nw^1][u][li][ri][sc])){
				int nl=li?sl[i]-'0':0,nr=ri?sr[i]-'0':9;
				for(int c=nl;c<=nr;c++) (f[nw][ch[u][c]][li && c==nl][ri && c==nr][sc | vw[ch[u][c]]]+=bf)%=P;
				f[nw^1][u][li][ri][sc]=0;
			}
	} int ans=0;
	for(int u=1;u<=tot;u++) 
		for(int li=0;li<2;li++) for(int ri=0;ri<2;ri++)
			(ans+=f[nw][u][li][ri][1])%=P;
	printf("%d\n",ans);
	return 0;
}//ww