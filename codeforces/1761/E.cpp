#include <bits/stdc++.h>
#define F(i,x,y) for(int i=(x);i<=(y);i++)
#define DF(i,x,y) for(int i=(x);i>=(y);i--)
#define ms(x,y) memset(x,y,sizeof(x))
#define SZ(x) (int)x.size()-1
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T> void chkmax(T &x,T y){ x=max(x,y);}
template<typename T> void chkmin(T &x,T y){ x=min(x,y);}
template<typename T> void read(T &FF){
    FF=0;int RR=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') RR=-1;
    for(;isdigit(ch);ch=getchar()) FF=(FF<<1)+(FF<<3)+ch-48;
    FF*=RR;
}
const int N=4010;
int n;
vector<int> G[N];
char str[N];
int siz;
bool vis[N];
int comp;
vector<int> node[N];
void dfs(int u){
    siz++;
    vis[u]=1,node[comp].pb(u);
    for(int v:G[u]) if(!vis[v]) dfs(v);
}
void work(){
    read(n);
    F(i,1,n) G[i].clear();
    F(i,1,n){
        scanf("%s",str+1);
        F(j,1,n) if(str[j]=='1') G[i].pb(j);
    }
    comp=0;
    F(i,1,n) vis[i]=0;
    F(i,1,n) if(!vis[i]){
        siz=0,node[++comp].clear();
        dfs(i);
        if(siz==n){ puts("0");return;}
        if(siz==1){ puts("1"),printf("%d\n",node[comp][0]);return;}
        for(int x:node[comp]) if(G[x].size()!=siz-1){
            sort(node[comp].begin(),node[comp].end(),[&](int x,int y){ return SZ(G[x])<SZ(G[y]);});
            puts("1"),printf("%d\n",node[comp][0]);return;
        }
    }
    if(comp==2){
        if(SZ(node[1])>SZ(node[2])) swap(node[1],node[2]);
        printf("%d\n",(int)node[1].size());
        for(int x:node[1]) printf("%d ",x);puts("");
        return;
    }
    puts("2");
    printf("%d %d\n",node[1][0],node[2][0]);
}
int main(){
    int T;read(T);
    while(T--) work();    
    return 0;
}
