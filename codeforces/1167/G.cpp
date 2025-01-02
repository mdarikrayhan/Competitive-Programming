#include<bits/stdc++.h>
using namespace std;
int n,d,a[200010],Q;
bitset<7100> L,R;
int main()
{
scanf("%d%d",&n,&d);
for(int i=1;i<=n;i++)
{
scanf("%d",&a[i]);
if(a[i]<7050)R.set(a[i]);
}
scanf("%d",&Q);
int pre=0,pl=1,pr=1;
while(Q--)
{
int pos;
scanf("%d",&pos);
int delta=pos-pre;
L<<=delta;R>>=delta;
while(pl<=n&&a[pl]<pos)
{
if(a[pl]>=pos-7050)L.set(pos-a[pl]-1);
pl++;
}
while(pr<=n&&a[pr]<=pos+7050)
{
if(a[pr]>=pos)R.set(a[pr]-pos);
pr++;
}
double ans=atan2(1,min(L._Find_first(),R._Find_first()));
ans=max(ans,2*atan2(1,(L&R)._Find_first()));
ans=max(ans,2*atan2(1,1+((R>>1)&L)._Find_first()));
ans=max(ans,2*atan2(1,1+((L>>1)&R)._Find_first()));
pre=pos;
printf("%.12lf\n",ans);
}
return 0;
}