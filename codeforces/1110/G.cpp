// LUOGU_RID: 159975259
#include<bits/stdc++.h>
using namespace std;

const int N=6e5+100;

int n; char col[N];
int head[N],ne[N*2],v[N*2],tot=0,deg[N];
void add(int x,int y){ 
	ne[++tot]=head[x]; v[tot]=y; head[x]=tot;
	ne[++tot]=head[y]; v[tot]=x; head[y]=tot;
	deg[x]++; deg[y]++;
}

int main(){
	
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1,x,y;i<n;i++) scanf("%d %d", &x, &y),add(x,y);
		scanf("%s", col+1); int n1=n;
		for(int i=1;i<=n;i++) if(col[i]=='W') add(i,n1+1),add(n1+1,n1+2),add(n1+1,n1+3),n1+=3;
		n=n1; int cnt=0,f=0;
		for(int i=1;i<=n;i++){
			if(deg[i]>=4){ f=1; break; }
			if(deg[i]==3) cnt++;
		}
		if(!f){
			for(int i=1,res=0;i<=n;i++){
				if(deg[i]<3) continue;
				res=0;
				for(int j=head[i];j;j=ne[j]) if(deg[v[j]]>=2) res++;
				if(res>=2){ f=1; break; }
			}
			if(cnt==2&&((n-4)&1)) f=1;
		}
		printf(f?"White\n":"Draw\n");
		tot=0; for(int i=1;i<=n;i++) head[i]=0,deg[i]=0;
	}
	return 0;
}