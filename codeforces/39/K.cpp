#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define mk make_pair
#define pb push_back
using namespace std;
struct ppp{
 int x1,x2,y1,y2;
 void mk(int x1_,int x2_,int y1_,int y2_){
  x1=x1_; x2=x2_; y1=y1_; y2=y2_;
 }
}a[120];
long long ans;
int n,m,i,j,k,x,y,l,r,P[220],tot,Pn,u,d;
char c[1010][1010];
int Find(int x){
 return lower_bound(P+1,P+Pn+1,x)-P;
}
int main(){
 scanf("%d%d%*d",&n,&m);
 for(i=1;i<=n;++i)scanf("%s",c[i]+1);
 for(i=1;i<=n;++i)
  for(j=1;j<=m;++j)if(c[i][j]=='*'){
   k=j;
   while(c[i][k]=='*')k++; k--;
   l=i;
   while(c[l][j]=='*')l++; l--;
   for(x=i;x<=l;++x)
    for(y=j;y<=k;++y)c[x][y]='.';
   a[++tot].mk(i,l,j,k);
   P[++Pn]=i; P[++Pn]=l;
  }
 P[++Pn]=0; P[++Pn]=n+1;
 sort(P+1,P+Pn+1);
 Pn=unique(P+1,P+Pn+1)-P-1;
 for(i=1;i<=tot;++i)a[i].x1=Find(a[i].x1),a[i].x2=Find(a[i].x2);
 for(u=2;u<Pn;++u){
  for(d=u;d<Pn;++d){
   long long tmp=0;
   vector<pair<int,int> >Q;
   for(i=1;i<=tot;++i){
    if(a[i].x2<u || a[i].x1>d)continue;
    if(a[i].x1>=u && a[i].x2<=d)Q.pb(mk(a[i].y1,-1)),Q.pb(mk(a[i].y2,1));
    else Q.pb(mk(a[i].y1,-100)),Q.pb(mk(a[i].y2,100));
   }
   sort(Q.begin(),Q.end());
   int num=Q.size(),C,suml,sumr,cc;
   Q.push_back(mk(m+1,0));
   for(int C=1;C<=3;++C){
    suml=sumr=0; cc=0;
    for(l=0,r=0;r<num;++r){
     sumr+=Q[r].second;
     cc+=max(0,Q[r].second);
     if(!sumr){
      while(suml || cc>C){
       suml-=Q[l].second;
       cc-=max(0,Q[l].second);
       l++;
      }
      if(!suml && cc==C)tmp+=(Q[r+1].first-Q[r].first)*(Q[l].first-(!l?0:Q[l-1].first));
     }
    }
   }
   ans+=tmp*(P[u]-P[u-1])*(P[d+1]-P[d]);
  }
 }
 printf("%I64d\n",ans);
}