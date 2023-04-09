#include<iostream>
const int mxn=1e6+1;
int idx[mxn],l[mxn*21],r[mxn*21],c[mxn*21],rt[mxn],s,j,n,m;
int f(int i){return (i-1+j)%n+1;}
void add(int &x,int y,int i,int ll,int rr){
    x=++s,c[x]=c[y]+1,l[x]=l[y],r[x]=r[y];
    if(ll^rr){
        int mm=(ll+rr)>>1;
        if(i<=mm)add(l[x],l[y],i,ll,mm);
        else add(r[x],r[y],i,mm+1,rr);
    }
}
int ask(int x,int ql,int qr,int ll,int rr){
    if(!x||ll>qr||rr<ql)return 0;
    if(ll>=ql&&rr<=qr)return c[x];
    int mm=(ll+rr)>>1;
    return ask(l[x],ql,qr,ll,mm)+ask(r[x],ql,qr,mm+1,rr);
}
int main(){
    scanf("%d",&n);
    for(int i=1,a;i<=n;++i)scanf("%d",&a),idx[a]=i;
    for(int i=1,b;i<=n;++i)scanf("%d",&b),add(rt[i],rt[i-1],idx[b],1,n);
    scanf("%d",&m);
    for(int i=1,x,y,z,w;i<=m;++i){
        scanf("%d%d%d%d",&x,&y,&z,&w);
        x=f(x),y=f(y),z=f(z),w=f(w);
        if(x>y)std::swap(x,y);
        if(z>w)std::swap(z,w);
        printf("%d\n",j=(ask(rt[w],x,y,1,n)-ask(rt[z-1],x,y,1,n))),++j;
    }
}