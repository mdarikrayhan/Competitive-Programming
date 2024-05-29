#include<bits/stdc++.h>
using namespace std;
inline int read(){
int x=0,f=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
return x*f;
}
#define MN 100000
#define N 131072
#define K 50
struct node{int l,r,u,mx;}T[K+5][N*2+5];
node operator+(const node&a,const node&b){
return(node){a.l+a.u*b.l,b.r+b.u*a.r,a.u*b.u,max(max(a.mx,b.mx),a.r+b.l)};
}
string s[MN+5];
int t[N*2+5],v[MN+5],a[MN+5],an,Z[MN+5],zn,L[MN+5],R[MN+5],ans,S[MN+5];
set<int>st;
void change(int k,int x){for(t[k+=N]=x;k>>=1;)t[k]=max(t[k<<1],t[k<<1|1]);}
int query(int l,int r){
int res=0;
for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1){
if(~l&1)res=max(res,t[l+1]);
if(r&1)res=max(res,t[r-1]);
}
return res;
}
void change(node*t,int k,node x){for(t[k+=N]=x;k>>=1;)t[k]=t[k<<1]+t[k<<1|1];}
node Query(node*t,int l,int r){
node L,R;int ul=0,ur=0;
for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1){
if(~l&1)L=ul?L+t[l+1]:(ul=1,t[l+1]);
if(r&1)R=ur?t[r-1]+R:(ur=1,t[r-1]);
}
return ul?ur?L+R:L:R;
}
void renew(int x){
cin>>s[x];change(x,s[x].size());
if(v[x]>K)st.erase(x);if(v[x+1]>K)st.erase(x+1);
for(v[x]=0;v[x]<s[x].size()&&v[x]<s[x-1].size()&&s[x][v[x]]==s[x-1][v[x]];)++v[x];
for(v[x+1]=0;v[x+1]<s[x].size()&&v[x+1]<s[x+1].size()&&s[x][v[x+1]]==s[x+1][v[x+1]];)++v[x+1];
if(v[x]>K)st.insert(x);if(v[x+1]>K)st.insert(x+1);
node a=(node){0,0,0,0},b=(node){1,1,1,1};
for(int i=1;i<=K;++i)change(T[i],x,v[x]<i?a:b),change(T[i],x+1,v[x+1]<i?a:b);
}
void dfs(int x){
S[x]=1;
if(L[x])dfs(L[x]),S[x]+=S[L[x]];
if(R[x])dfs(R[x]),S[x]+=S[R[x]];
ans=max(ans,v[x]*(S[x]+1));
}
int p(const set<int>::iterator&i){return i!=st.end()?*i:MN+1;}
int main(){
int n,m,i,l,r,z;
n=read();m=read();
for(i=1;i<=n;++i)renew(i);
while(m--)
if(read()==1){
l=read();r=read();
ans=query(l,r);
if(l<r)for(i=1;i<=K;++i)z=Query(T[i],l+1,r).mx,ans=max(ans,i*(z?z+1:0));
set<int>::iterator it=st.upper_bound(l);
for(z=p(it);z<=r;){
for(a[an=1]=z;(z=p(++it))<=r&&z==a[an]+1;)a[++an]=z;
for(i=1,zn=0;i<=an;++i){
L[a[i]]=R[a[i]]=0;
while(zn&&v[a[i]]<v[a[Z[zn]]])L[a[i]]=a[Z[zn--]];
R[a[Z[zn]]]=a[i];Z[++zn]=i;
}
dfs(a[Z[1]]);
}
printf("%d\n",ans);
}
else renew(read());
}