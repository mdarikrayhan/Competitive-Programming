#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b)for(int i=(a);i<=(b);++i)
typedef long long LL;

struct P{
int x,y;
bool operator<(P r)const{return x<r.x;}
};
map<LL,set<P>>d2;
map<double,int>num;
int n,s=0,t,x,y;

void add(set<P>a,int x,int y,int z){
s+=z;
num[1.0*y/x]+=z;
for(auto u:a)num[1.0*(u.y+y)/(u.x+x)]+=z*2;
}

int main(){
scanf("%d",&n);
while(n--){
scanf("%d%d%d",&t,&x,&y);
LL d=1ll*x*x+1ll*y*y;
if(t==1)add(d2[d],x,y,1),d2[d].insert({x,y});
else if(t==2)d2[d].erase({x,y}),add(d2[d],x,y,-1);
else printf("%d\n",s-num[1.0*y/x]);
}
return 0;
}