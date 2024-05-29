#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int h,w,n,yl,yr,v,ans;
int dp[100005];
stack<int>b[265000];
struct caofangbo{int u,l,r,s;}a[100005];
bool cmp(caofangbo a,caofangbo b){
return a.u<b.u;
}
void fill(int k,int l,int r,int x,int y,int v){
if(l==x&&r==y){
b[k].push(v);
return;
}
int mid=(l+r)/2;
if(y<=mid)fill(k*2,l,mid,x,y,v);
else if(x>mid)fill(k*2+1,mid+1,r,x,y,v);
else fill(k*2,l,mid,x,mid,v),fill(k*2+1,mid+1,r,mid+1,y,v);
}
void ask(int k,int l,int r){
for(;!b[k].empty();b[k].pop()){
int x=b[k].top();
if(a[x].u+a[x].s>=yr)break;
}
if(!b[k].empty()&&(v==-1||a[b[k].top()].u>a[v].u))v=b[k].top();
if(l!=r){
int mid=(l+r)/2;
if(yl<=mid)ask(k*2,l,mid);
else ask(k*2+1,mid+1,r);
}
}
int que(int x,int y){
yl=y;yr=x;v=-1;
ask(1,1,w);
return v!=-1?dp[v]:1;
}
int main(){
scanf("%d%d%d",&h,&w,&n);
for(int i=1;i<=n;i++)
scanf("%d%d%d%d",&a[i].u,&a[i].l,&a[i].r,&a[i].s);
sort(a+1,a+n+1,cmp);
for(int i=1;i<=n;i++){
if(a[i].l==1)dp[i]=que(a[i].u,a[i].r+1)*2%mo;
else if(a[i].r==w)dp[i]=que(a[i].u,a[i].l-1)*2%mo;
else dp[i]=(que(a[i].u,a[i].l-1)+que(a[i].u,a[i].r+1))%mo;
fill(1,1,w,a[i].l,a[i].r,i);
}
for(int i=1;i<=w;i++)
ans=(ans+que(h+1,i))%mo;
printf("%d",ans);
}