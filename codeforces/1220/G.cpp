#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const int mn=1e5+10;
ll x[mn],y[mn],d[mn];
inline ld sq(ld x){return x*x;}
inline ll sq(ll x){return x*x;}
ld eps=1e-8;
ld i1x,i1y,i2x,i2y;
vector<pll>ans;
void idk(ll xx,ll yy,int i,int n){
    if(sq(xx-x[0])+sq(yy-y[0])!=d[i])return;
    vector<ll>v;
    for(int j=0;j<n;j++)v.push_back(sq(xx-x[j])+sq(yy-y[j]));
    sort(v.begin(),v.end());
    for(int j=0;j<n;j++)if(d[j]!=v[j])return;
    ans.push_back({xx,yy});
}
void intersect(ld x1,ld y1,ld r1,ld x2,ld y2,ld r2,ld r12,ld r22,int i,int n){
    ld dis=sqrt(sq(x1-x2)+sq(y1-y2));
    ld dis2=sq(x1-x2)+sq(y1-y2);
    if(dis>r1+r2+eps)return;
    ld t=atan2(y2-y1,x2-x1);
    ld p=(r12+dis2-r22)/2/r1/dis;
    if(p>1)p=1;
    if(p<-1)p=-1;
    ld k=acos(p);
    i1x=x1+r1*cos(t+k);
    i1y=y1+r1*sin(t+k);
    i2x=x1+r1*cos(t-k);
    i2y=y1+r1*sin(t-k);

    for(int j=-6;j<=6;j++){for(int k=-6;k<=6;k++) {
                idk((ll)i1x+j, (ll)i1y+k, i, n);
                idk((ll)i2x+j, (ll)i2y+k, i, n);
            }}

}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld%lld",x+i,y+i);
    ld sx=0,sy=0,sxy=0;
    for(int i=0;i<n;i++)sx+=x[i],sy+=y[i];
    ld cx=sx/n,cy=sy/n;
    for(int i=0;i<n;i++)sxy+=sq(cx-x[i])+sq(cy-y[i]);
    int m;
    scanf("%d",&m);
    while(m--){
        ans.clear();
        for(int i=0;i<n;i++)scanf("%lld",d+i);
        ll h1=0,h2=0;
        for(int i=0;i<n;i++)h1+=d[i]/1000000000,h2+=d[i]%1000000000;
        ld r2=(((ld)h1)*1e9+((ld)(h2)-sxy))/n;
        for(int i=0;i<n;i++){
            if(i&&d[i]==d[i-1])continue;
            intersect(cx,cy,sqrt(r2),x[0],y[0],sqrt(d[i]),r2,d[i],i,n);

        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        printf("%d",ans.size());
        for(auto hail:ans)printf(" %lld %lld",hail.first,hail.second);
        printf("\n");
    }
}
//1 22424303 86152320