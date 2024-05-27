// LUOGU_RID: 160259872
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,k,c,x,fa[600005],siz[600005][3],typ[600005],ans;
char s[300005];
vector <int> g[300005];
int getfa(int pos){
    return (pos == fa[pos]) ? pos : (fa[pos] = getfa(fa[pos]));
}
int getsiz(int pos){
    if(typ[pos]){
        return siz[pos][typ[pos]];
    }
    return min(siz[pos][1],siz[pos][2]);
}
void modify(int pos,int X){
    pos = getfa(pos);
    ans -= getsiz(pos);
    typ[pos] = X;
    ans += getsiz(pos);
}
void merge(int pos1,int pos2){
    pos1 = getfa(pos1);
    pos2 = getfa(pos2);
    if(pos1 != pos2){
        ans -= getsiz(pos1) + getsiz(pos2);
        siz[pos1][1] += siz[pos2][1];
        siz[pos1][2] += siz[pos2][2];
        typ[pos1] = max(typ[pos1],typ[pos2]);
        fa[pos2] = pos1;
        ans += getsiz(pos1);
    }
}
int main(){
    scanf("%d%d %s",&n,&k,s + 1);
    for(int i = 1;i <= k;i++){
        scanf("%d",&c);
        for(int j = 1;j <= c;j++){
            scanf("%d",&x);
            g[x].push_back(i);
        }
    }
    for(int i = 1;i <= k;i++){
        fa[i] = i;
        siz[i][1] = 1;
    }
    for(int i = k + 1;i <= 2 * k;i++){
        fa[i] = i;
        siz[i][2] = 1;
    }
    for(int i = 1;i <= n;i++){
        if(g[i].size() > 1){
            if(s[i] - '0'){
                merge(g[i][0],g[i][1]);
                merge(k + g[i][0],k + g[i][1]);
            }
            else{
                merge(g[i][0],k + g[i][1]);
                merge(k + g[i][0],g[i][1]);
            }
        }
        else if(g[i].size()){
            if(s[i] - '0'){
                modify(g[i][0],2);
                modify(k + g[i][0],1);
            }
            else{
                modify(g[i][0],1);
                modify(k + g[i][0],2);
            }
        }
        printf("%d\n",ans / 2);
    }
    return 0;
}