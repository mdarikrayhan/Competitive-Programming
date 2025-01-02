// LUOGU_RID: 156301246
#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
int n,m,tot;
int ind[MAX*4],a[MAX];
bool dat[MAX*4];
void add(int u,int L,int R,int v,bool d){
    if(L==R){
        dat[u]=d;
        ind[u]=1;
        return ;
    }
    int mid=(L+R)>>1;
    if(v<=mid) add(u*2,L,mid,v,d);
    else add(u*2+1,mid+1,R,v,d);
    ind[u]=ind[u*2]+ind[u*2+1];
    return ;
}
void del(int u,int L,int R,int v){
    if(L==R){
        ind[u]=0;
        return ;
    }
    int mid=(L+R)>>1;
    if(v<=ind[u*2]) del(u*2,L,mid,v);
    else del(u*2+1,mid+1,R,v-ind[u*2]);
    ind[u]=ind[u*2]+ind[u*2+1];
    return ;
}
void print(int u,int L,int R){
    if(L==R) cout<<dat[u];
    else{
        int mid=(L+R)>>1;
        if(ind[u*2]) print(u*2,L,mid);
        if(ind[u*2+1]) print(u*2+1,mid+1,R);
    }
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int opt;
        cin>>opt;
        if(opt==-1){
            for(int j=1;j<=m&&a[j]-j+1<=ind[1];j++){
                del(1,1,n,a[j]-j+1);
            }
        }
        else add(1,1,n,++tot,opt);
    }
    if(!ind[1]) cout<<"Poor stack!";
    else print(1,1,n);
    return 0;
}
