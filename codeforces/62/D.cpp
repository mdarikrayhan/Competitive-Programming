#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,a[2001],path[2001];
int e[101][101];

int gao(int x, int r, int gt){
path[r]=x;
if(r++==m) return gt;
for(int y=gt?1:a[r];y<=n;y++) if(e[x][y]){
e[x][y]--;e[y][x]--;
if(gao(y,r,gt|y>a[r])) return 1;
e[x][y]++;e[y][x]++;
}
return 0;
}

int main(){
scanf("%d%d%d",&n,&m,a);
for(int i=1;i<=m;i++){
scanf("%d",a+i);
e[a[i-1]][a[i]]++;
e[a[i]][a[i-1]]++;
}
if(!gao(*a,0,0)) return puts("No solution");
for(int i=0;i<=m;i++) printf("%d ",path[i]);
}