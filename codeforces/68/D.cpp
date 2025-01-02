// LUOGU_RID: 158399492
#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=10000000;
int n,m,nn;
struct stk
{
    int a[40],tot;
    stk(){tot=0;}
    inline void push(const int x){a[++tot]=x;}
    inline int top(){return a[tot];}
    inline void pop(){tot--;}
    inline int get(){return a[tot--];}
    inline bool have(){return tot;}
};
stk st;
int ls[N],rs[N],sum[N],tot=0;
void upd(int &x,stk &s,int v)
{
    if(!x)x=++tot;
    if(s.have())
    {
        sum[x]+=v;
        if(s.get())upd(x[rs],s,v);
        else upd(x[ls],s,v);
    }
    else sum[x]+=v;
}
double ask(int x,int ma)
{
    double ans=0;if(ma>=x[sum])return ma;
    return (ask(x[ls],max(ma,x[sum]-x[ls][sum]))+ask(x[rs],max(ma,x[sum]-x[rs][sum])))/2;
}
void trans(stk &s,int x)
{
    while(s.have())s.pop();
    while(x){s.push(x&1),x>>=1;}s.pop();
}
int main()
{
    cin>>n>>m;nn=1<<n;int rt=0;
    for(int i=1;i<=m;i++)
    {
        string s;cin>>s;
        if(s[0]=='a')
        {
            int p,x;cin>>p>>x;
            trans(st,p);upd(rt,st,x);
        }
        else printf("%.10lf\n",ask(rt,0));
    }
    return 0;
}