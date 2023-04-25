// LUOGU_RID: 101310618
#include<bits/stdc++.h>
using namespace std;

const int N=1e3+4;
const int M=5e6+7;

int n,m,fa[M],sz[M],c[M],tr[N][N];
vector<tuple<int,int,int> >a;

inline int find(int x){return x^fa[x]?fa[x]=find(fa[x]):x;}
inline int id(int x,int y,int dir){return 4*(x*N+y)+dir;}
inline void merge(int x,int y){
    x=find(x),y=find(y);
    if(x^y)fa[y]=x,sz[x]^=sz[y],c[x]^=c[y];
    return;
}

int main(){
	scanf("%d%d",&n,&m);
    for(int i=0;i<M;i++)fa[i]=i,sz[i]=1,c[i]=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
    	int x;
    	scanf("%d",&x);
		a.push_back(make_tuple(x,i,j));
	}
    sort(a.begin(),a.end());
    for(auto[x,i,j]:a){
        for(int k=0;k<4;k++)tr[i][j]^=(sz[id(i,j,k)]&x)^c[id(i,j,k)];
        for(int k=0;k<4;k++){
            int o=(k+2+tr[i][j])&3;
            c[id(i,j,k)]=sz[id(i,j,k)]&x;
            if(!o)merge(id(i-1,j,2),id(i,j,k));
            else if(o==1)merge(id(i,j+1,3),id(i,j,k));
            else if(o==2)merge(id(i+1,j,0),id(i,j,k));
            else merge(id(i,j-1,1),id(i,j,k));
        }
    }
    for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;j++)printf("%d",tr[i][j]);
    return 0;
}