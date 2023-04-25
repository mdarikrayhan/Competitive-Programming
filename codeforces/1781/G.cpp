#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4;
int n,p[N],ch[2][N],f[N];
bool g[N],leaf[N];
void sol(){
	scanf("%d",&n),memset(ch[0],0,n<<2),memset(ch[1],0,n<<2);
	for(int i=1;i<n;i++){
		scanf("%d",&p[i]),p[i]--;
		ch[ch[0][p[i]]>0][p[i]]=i;
		if(i==3&&p[2]==1&&p[3]==1)puts("2");
		else puts(i&1?"0":"1");
	}
	memset(leaf,0,n),memset(g,0,n);
	for(int i=n-1;~i;i--){
		int ls=ch[0][i],rs=ch[1][i];
		if(ls&&rs){
			if(leaf[ls]&&leaf[rs])f[i]=-1;
			else f[i]=(f[ls]^f[rs]^1)&1;
		}else if(ls){
			if(f[ls]<0)f[i]=2;
			else f[i]=f[ls]&1^1;
		}else leaf[i]=1,f[i]=1;
	}
	for(int i=0;i<n;i++){
		putchar(g[i]?'b':'w');
		int ls=ch[0][i],rs=ch[1][i];
		if(ls&&rs){
			if(f[i]<0)g[ls]=g[rs]=g[i]^1;
			else{
				int p=f[ls],q=f[rs];
				if(p>q)swap(p,q),swap(ls,rs);
				if(p==1&&q==1&&leaf[ls])g[ls]=g[i]^1,g[rs]=g[i];
				else if(q-p<2&&(p!=1||q!=2))g[ls]=g[i],g[rs]=g[i]^1;
				else{
					g[ls]=g[rs]=g[i]^1;
					if(~p)g[ch[0][rs]]=1;
				}
			}
		}else if(ls){
			g[ls]^=g[i]^1;
			if(f[ls]>1)g[ch[0][ls]]=1;
		}
	}
	puts("");
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}