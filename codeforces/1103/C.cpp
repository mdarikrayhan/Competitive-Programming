// LUOGU_RID: 159832595
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> edge[250005];
int fa[250005],dep[250005],vis[250005];
int isleaf[250005];
void dfs(int x){
    vis[x]=isleaf[x]=1;
    for(int y:edge[x])if(!vis[y])fa[y]=x,dep[y]=dep[x]+1,dfs(y),isleaf[x]=0;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++)if(dep[i]+1>=(n+k-1)/k){
        printf("PATH\n%d\n",dep[i]+1);
        for(int j=i;j;j=fa[j])printf("%d ",j);puts("");
        return 0;
    }
    puts("CYCLES");
    for(int i=1;i<=n;i++)if(isleaf[i]){
        for(int j:edge[i]){
            int flag=0;
            for(int k:edge[i])if(dep[j]>dep[k]&&(dep[j]-dep[k]+2)%3){
                printf("%d\n",dep[j]-dep[k]+2);
                printf("%d ",i);
                for(int p=j;p!=k;p=fa[p])printf("%d ",p);
                printf("%d\n",k);
                flag=1;
                break;
            }
            if(flag)break;
        }
        if(!--k)return 0;
    }
    return 0;
}
