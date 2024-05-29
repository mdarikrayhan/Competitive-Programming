#include<bits/stdc++.h>
#define No() return puts("-1"),0
using namespace std;
int n,ans[3010][2],cnt=0;
struct node{
int deg,id;
bool operator <(const node &b)const{
return deg>b.deg;
}
}a[2010];
void add(int i,int j){
a[i].deg--,a[j].deg--;
ans[++cnt][0]=a[i].id,ans[cnt][1]=a[j].id;
}
int main(){
scanf("%d",&n);
for(int i=1;i<=n;i++) scanf("%d",&a[i].deg),a[i].id=i;
while(true){
sort(a+1,a+n+1);
while(n&&!a[n].deg) n--;
if(!n) break;
if(a[n].deg==1){
int pos=1;
for(int i=1;i<=n;i++) if((a[i].deg&1)&&a[i].deg>1){
pos=i;
break;
}
if(a[pos].deg==1&&n>2) No();
add(pos,n);
}
else if(a[n].deg==2){
if(n<3) No();
if(a[1].deg==2){
for(int i=1;i<n;i++) add(i,i+1);
add(1,n);
}
else{
if(a[n-1].deg!=2) No();
add(n-1,n),add(n,1),add(1,n-1);
}
}
else No();
}
printf("%d\n",cnt);
for(int i=1;i<=cnt;i++) printf("2 %d %d\n",ans[i][0],ans[i][1]);
}
