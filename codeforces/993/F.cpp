#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,x,n)for(int i=x;i<(int)(n);++i)
int const N=50;char in[N+1];int fr[4],c[4];pair<int,ll>g[N];inline int bc(ll x){int an=0;while(x){x^=x&-x;++an;}return an;}inline int tp(){if(in[0]=='a')return 0;if(in[0]=='o')return 2;if(in[1]=='a')return 1;return 3;}inline pair<int,ll>sc(){scanf("%s",in);int t=tp();scanf("%s",in);int n=strlen(in);ll an=0;f(i,0,n)if(in[i]=='x')an|=1ll<<i;return make_pair(t,an);}void kl(){scanf("%s",in);c[3]=tp();scanf("%s",in);int n=strlen(in),z=0;ll an=0;f(i,0,n)if(in[i]=='x')an|=g[i].second,c[++z]=g[i].first;if(c[1]>c[2])swap(c[1],c[2]);c[0]=bc(an);}int main(){int m,k;scanf("%*d%d%d",&m,&k);f(i,0,m)g[i]=sc();f(i,0,k){kl();if(c[0]==4)continue;if(c[0]==3){if(c[1]==0&&c[2]==3&&!(c[3]&1))++fr[bc(c[3])&1];else if(c[1]==1&&c[2]==2&&c[3]&1)++fr[bc(c[3])&1];}else if(c[1]==0&&c[2]==3&&!(c[3]&1))++fr[bc(c[3])&1];else if(c[1]==1&&c[2]==2&&c[3]&1)++fr[bc(c[3])&1];else if((c[1]^c[2])==1)++fr[(bc(c[3])&1)+2];}printf("%d\n",fr[2]||fr[3] ? k-max(fr[2] ? fr[2]+fr[0] : 0,fr[3] ? fr[3]+fr[1] : 0):-1);}