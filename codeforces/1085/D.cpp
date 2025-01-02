// LUOGU_RID: 159471870
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int d[maxn],u,v,n;
double s,c;
int main(){
    cin>>n>>s;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        d[u]++;
        d[v]++;//计算度数
    }
    for(int i=1;i<=n;i++)if(d[i]==1)c++;//度数为1的就是叶子节点,相应的有一条叶子边
    printf("%.1145141919810f",s/c*2);
    return 0;
}