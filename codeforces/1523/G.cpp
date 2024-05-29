// LUOGU_RID: 158888519
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4,M=1e5,INF=1e9;
struct node{
    int ls,rs,v;
}c[M<<8];//空间？
int tot;
void pushup(int x){
    c[x].v=min(c[c[x].ls].v,c[c[x].rs].v);
}//初始化为INF
void change(int l,int r,int p,int x,int v){
    if(l==r){
        c[p].v=min(c[p].v,v);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
        if(!c[p].ls){
            c[p].ls=++tot;
            c[tot].v=INF;
        }
        change(l,mid,c[p].ls,x,v);
    }
    else{
        if(!c[p].rs){
            c[p].rs=++tot;
            c[tot].v=INF;
        }
        change(mid+1,r,c[p].rs,x,v);
    }
    pushup(p);
}
int query(int l,int r,int p,int L,int R){
    if(!p){
        return INF;
    }
    if(L<=l&&r<=R){
        return c[p].v;
    }
    int mid=(l+r)>>1;
    if(R<=mid){
        return query(l,mid,c[p].ls,L,R);
    }
    if(L>mid){
        return query(mid+1,r,c[p].rs,L,R);
    }
    return min(query(l,mid,c[p].ls,L,R),query(mid+1,r,c[p].rs,L,R));
}
int rt[N+2];
int n,m;
void add(int l,int r,int v){
    while(r<=n){
        change(1,n,rt[r],l,v);
        r+=r&-r;
    }
}
int ask(int l,int r){
    int ans=INF;
    while(r){
        ans=min(ans,query(1,n,rt[r],l,n));
        r-=r&-r;
    }
    return ans;
}
void prework(){
    c[0].v=INF;
    for(int i=1;i<=n;i++){
        c[i].v=INF;
        rt[i]=++tot;
    }
    // tot=n;
}
int l[M+2],r[M+2],s[M+2];
int ans[M+2];
int solve(int x,int y){
    if(x>y){
        return 0;
    }
    int temp=ask(x,y);
    if(temp==INF){
        return 0;
    }
    return r[temp]-l[temp]+1+solve(x,l[temp]-1)+solve(r[temp]+1,y);
}
bool cmp(int x,int y){
    return r[x]-l[x]+1>r[y]-l[y]+1;
}
int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    prework();
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
        s[i]=i;
    }
    sort(s+1,s+m+1,cmp);
    for(int i=n,j=0;i>=1;i--){
        while(j<m&&r[s[j+1]]-l[s[j+1]]+1>=i){
            j++;
            add(l[s[j]],r[s[j]],s[j]);
        }
        ans[i]=solve(1,n);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}