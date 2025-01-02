#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x,q;
int c[10];
int num[1<<10],cnt;
struct stone{
    int pos,val;
    bool operator<(const stone &x)const{
        return pos<x.pos;
    }
};
stone a[30];
struct node{
    int mp[80][80];
    int n,m;
    node(){
        n=0,m=0;
        memset(mp,0x3f,sizeof(mp));
    }
    node(int x,int y){
        n=x,m=y;
        memset(mp,0x3f,sizeof(mp));
    }
    friend node operator*(node &a,node &b);
};
node e;
node operator*(node &a,node &b){
    int n=a.n;
    int m=b.m;
    int z=a.m;
    memset(e.mp,0x3f,sizeof(e.mp));
    e.n=n;
    e.m=m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=z;k++){
                e.mp[i][j]=min(e.mp[i][j],a.mp[i][k]+b.mp[k][j]);
            }
        }
    }
    return e;
}
node init(node a){
    int n=a.n;
    for(int i=1;i<=n;i++){
        a.mp[i][i]=0;
    }
    return a;
}
node qpow(node a,int b){
    node res(cnt,cnt);
    res=init(res);
    while(b){
        if(b&1){
            res=res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}
signed main(){
    scanf("%lld%lld%lld%lld",&x,&k,&n,&q);
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
    }
    int sum=0;
    for(int i=1;i<=q;i++){
        scanf("%lld%lld",&a[i].pos,&a[i].val);
        if(a[i].pos>=n-x+1){
            sum+=a[i].val;
        }
    }
    sort(a+1,a+q+1);
    for(int i=1;i<(1<<k);i++){
        if(__builtin_popcount(i)==x){
            num[i]=++cnt;
        }
    }
    node B(cnt,cnt);
    for(int i=1;i<(1<<k);i++){
        if(!num[i]){
            continue;
        }
        if(i&1){
            for(int j=1;j<=k;j++){
                if(!(i&(1<<j))){
                    B.mp[num[i]][num[(i|(1<<j))>>1]]=c[j];
                }
            }
        }
        else{
            B.mp[num[i]][num[i>>1]]=0;
        }
    }
    node A(cnt,cnt);
    A=init(A);
    int now=1;
    for(int i=1;i<=q;i++){
        if(a[i].pos>=n-x+1){
            break;
        }
        node res=qpow(B,a[i].pos-now);
        A=A*res;
        now=a[i].pos;
        for(int j=1;j<(1<<k);j+=2){
            if(!num[j]){
                continue;
            }
            for(int l=1;l<=cnt;l++){
                A.mp[l][num[j]]+=a[i].val;
            }
        }
    }
    B=qpow(B,n-x+1-now);
    A=A*B;
    printf("%lld\n",A.mp[1][1]+sum);
    return 0;
}