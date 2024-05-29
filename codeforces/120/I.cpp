#include <cstdio>
#include <cstring>
const int c[]={119,36,93,109,46,107,123,37,127,111};
#define rep(i,a,n) for (int i=a;i<n;i++)
#define cnt(a,b) __builtin_popcount(c[a]&c[b])
int n,k,s;char a[201000];
int main() {
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 scanf("%s",a);
 n=strlen(a);k=n/2;
 rep(i,0,n) a[i]-=48;
 for (int i=n-1;i>=0;i--) {
  int t=a[i>=k?i-k:i+k],ct=cnt(a[i],t),cs,r;
  rep(j,a[i]+1,10) if (s+cnt(t,j)>ct) {
   a[i]=j;cs=s+cnt(t,j)-ct;
   rep(l,i+1,n) {
    r=a[l>=k?l-k:l+k];
    rep(m,0,10) if (cs-cnt(r,a[l])+cnt(r,m)>0) {
     cs+=cnt(r,m)-cnt(r,a[l]);
     a[l]=m;
     break;
    }
   }
   rep(l,0,n) putchar(a[l]+'0');return 0;
  }
  a[i]=8;
  s+=cnt(a[i],t)-ct;
 }
 puts("-1");
}