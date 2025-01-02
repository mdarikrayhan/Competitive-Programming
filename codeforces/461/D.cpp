#include<cstdio>
#include<vector>
#include<algorithm>

std::vector<std::pair<int,int>>a[111111];
int v[111111];
char s[4];

int r=1;

void dfs(int x,int y){
if(v[x]){
if(v[x]!=y)r=0;
return;
}
int i;
v[x]=y;
for(i=0;i<a[x].size();i++){
if(a[x][i].second)dfs(a[x][i].first,3-y);
else dfs(a[x][i].first,y);
}
}

int main(){
int i,j,x,y,n,m;
scanf("%d%d",&n,&m);
while(m--){
scanf("%d%d%s",&i,&j,s);
x=std::abs(j-i)+1;
y=n-std::abs(i+j-n-1);
a[x].push_back(std::make_pair(y+2,s[0]=='o'));
a[y+2].push_back(std::make_pair(x,s[0]=='o'));
}
dfs(1,1);
dfs(2,1);
for(i=3;i<=n+2;i++)if(!v[i]){
r=2LL*r%1000000007;
dfs(i,1);
}
printf("%d\n",r);
}