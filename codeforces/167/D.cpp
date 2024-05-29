#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define X first
#define Y second
#define rep(i,l,r)for(int i=(l);i<=(r);i++)
typedef long long ll;using namespace std;typedef pair<int,int>pii;ll A,B,C,D,p=1000000009;pii a[100020];int n,k,m,x,y;pii ud(pii a,pii b){return pii(a.Y+b.Y,1+max(a.X+b.Y,a.Y+b.X));}struct N{int l,r,v;N*L,*R;pii w;pii qy(){if(this==0||y<l||x>r)return pii(-1,0);if(x<=l&&r<=y)return w;if(v>y||v<x)return max(L->qy(),R->qy());return ud(L->qy(),R->qy());}}t[100020],*o,z;N*bd(int x,int y){if(x>y)return&z;int p=max_element(a+x,a+y+1)-a;t[p].l=a[x].Y,t[p].r=a[y].Y,t[p].v=a[p].Y;t[p].L=bd(x,p-1),t[p].R=bd(p+1,y);t[p].w=ud(t[p].L->w,t[p].R->w);return t+p;}int main(){cin>>n>>k;z.w=pii(-1,0);rep(i,0,k-1)cin>>a[i].X>>a[i].Y;cin>>A>>B>>C>>D;rep(i,k,n-1)a[i].X=(a[i-1].X*A+B)%p,a[i].Y=(a[i-1].Y*C+D)%p;sort(a,a+n);rep(i,0,n-1)swap(a[i].X,a[i].Y);o=bd(0,n-1);cin>>m;rep(i,0,m-1)scanf("%d%d",&x,&y),printf("%d\n",o->qy().Y);return 0;}