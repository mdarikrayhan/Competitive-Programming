# include<stdio.h>
# include<vector>
# include<algorithm>
# include<iostream>
using namespace std;

const int M=100010;
int n;
pair<int,int>p[2][M];
int maxp[M],maxs[M],minp[M],mins[M];

inline long long s(long long x){
return x*x;
}

inline long long g(int x){
for(int i=1;i<=n;++i){
maxp[i]=max(maxp[i-1],p[x][i].second);
minp[i]=min(minp[i-1],p[x][i].second);
}
for(int i=n;i>=1;--i){
maxs[i]=max(maxs[i+1],p[x][i].second);
mins[i]=min(mins[i+1],p[x][i].second);
}

long long l=-1,r=1e18;
while(r-l>1){
long long mid=l+r>>1;
int ri=1,le=1;
bool g=s(p[x][n].first-p[x][1].first)<=mid;
while(!g&&ri<=n){
while(s(p[x][ri].first-p[x][le].first)>mid)le++;
long long a=min(minp[le-1],mins[ri+1]),b=max(maxp[le-1],maxs[ri+1]);
if(s(a-b)<=mid&&max(s(a),s(b))+max(s(p[x][ri].first),s(p[x][le].first))<=mid)g=1;
++ri;
}
if(g)r=mid;
else l=mid;
}
return r;
}

int main(){
scanf("%d",&n);
for(int i=1,x,y;i<=n;++i){
scanf("%d%d",&x,&y);
p[0][i]=make_pair(x,y);
p[1][i]=make_pair(y,x);
}
sort(p[0]+1,p[0]+n+1);
sort(p[1]+1,p[1]+n+1);
cout<<min(g(1),g(0))<<endl;
return 0;
}