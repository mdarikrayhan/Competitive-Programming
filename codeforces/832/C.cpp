#include<bits/stdc++.h>
using namespace std;
#define D long double
#define ll long long
const int S=1e6;//between [1,S]
const int MAXN=1e5+50;
const D eps=1e-8;
struct person {
    int x,v,type;
}a[MAXN];
int n,vs;
int sa[S+5],sb[S+5];
void append(D l,D r,int s[]) {
    if(r>S+1) r=S+1;
    if(l<1) l=1;
    if(l>r) return ;
    s[(int)ceil(l)]++;
    s[(int)ceil(r+eps)]--;//!!??
}
bool Sol(D T) {
    memset(sa,0,sizeof(sa));
    memset(sb,0,sizeof(sb));
    for(int i=1;i<=n;++i) if(a[i].type==1) {
        D tmp=(T*(vs+a[i].v)-a[i].x)/vs;
        D l=a[i].x,r=l+tmp*(vs-a[i].v);
        // if(T*a[i].v>=a[i].x) std::cerr<<"*a";
        // else if(l<r) std::cerr<<"a:"<<l<<","<<r<<"\n";
        if(T*a[i].v>=a[i].x) append(0,S,sa);
        else append(l,r,sa);
    }
    else {
        D tmp=(T*(vs+a[i].v)-(S-a[i].x))/vs;
        D l=S-a[i].x,r=l+tmp*(vs-a[i].v);
        // if(T*a[i].v+a[i].x>=S) std::cerr<<"*b";
        // else if(l<r) std::cerr<<"b:"<<S-r<<","<<S-l<<"\n";
        if(T*a[i].v+a[i].x>=S) append(0,S,sb);
        else append(S-r,S-l,sb);
    }
    for(int i=1;i<=S;++i) {
        sa[i]+=sa[i-1];
        sb[i]+=sb[i-1];
    }
    for(int i=1;i<=S;++i) if(sa[i]&&sb[i]) return true;
    return false;
}
int main() {
    // freopen("832c.in","r",stdin);
    // freopen("832c.out","w",stdout);
    scanf("%d%d",&n,&vs);
    for(int i=1;i<=n;++i) {
        scanf("%d%d%d",&a[i].x,&a[i].v,&a[i].type);
    }
    // printf("%d",Sol(14050.6));
    D l=0,r=S;
    while(r-l>eps) {
        D mid=(l+r)/2;
        if(Sol(mid)) r=mid;
        else l=mid;
    }
    printf("%.7Lf",l);
    return 0;
}
  		  				   	  			 				  	   	