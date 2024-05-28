// LUOGU_RID: 160378672
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define pb push_back
#define M 998244353
#define int long long
#define double long double
void in(int &x){
    int f=1;x=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-')c=getchar();
    if(c=='-')f=-1,c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    x*=f;
}
int t,n,m,k,x,y,a[100005];
double ans;
struct BIT{
    int c[100005];
    void upd(int x,int y){while(x<=n)c[x]+=y,x+=(x&(-x));}
    int query(int x){int ans=0;while(x>=1)ans+=c[x],x^=(x&(-x));return ans;}
}T1,T2;
signed main(){
    in(n);int all=n*(n+1);
    for(int i=1;i<=n;i++)in(a[i]);
    for(int i=1;i<=n;i++){
        ans+=(n-i+1)*T1.query(a[i]-1)*1.0/all;
        ans+=(T2.query(n)-T2.query(a[i]))-(n-i+1)*(T1.query(n)-T1.query(a[i]))*1.0/all;
        T1.upd(a[i],i);T2.upd(a[i],1);
    }
    printf("%.15Lf\n",ans);
}