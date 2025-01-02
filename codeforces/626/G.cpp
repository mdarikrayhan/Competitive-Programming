// LUOGU_RID: 157386514
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int N=2e5+5;
int n,t,m,p[N],w[N],g[N],sms;
double res;
struct node{
    double sm;int x,y;
    friend bool operator<(node a,node b){
        return a.sm<b.sm;
    }
    friend bool operator>(node a,node b){
        return a.sm>b.sm;
    }
};
priority_queue<node,vector<node>,greater<node> >q1;
priority_queue<node>q2;
struct nodes{
    double sm;
    int x,y;
    friend bool operator<(nodes a,nodes b){
        return a.sm<b.sm;
    }
};
priority_queue<nodes>q;
double gets(int x,int y){
    if(y>p[x])return 0;
    return w[x]*(double)(p[x])/((p[x]+y)*(p[x]+y-1));
}
void solve(){
    while(q.size())q.pop();
    for(int i=1;i<=n;i++)q.push((nodes){w[i]*1.0/(p[i]+1),i,1});
    for(int i=1;i<=t;i++){
        nodes qq=q.top();int x=qq.x;
        q.pop();
        g[x]++;
        res+=qq.sm;
        q.push((nodes){gets(x,qq.y+1),x,qq.y+1});
    }
}
bool eq(double a,double b){
    return abs(a-b)<1e-12;
}
void init(){
    while(!eq(q1.top().sm,gets(q1.top().x,g[q1.top().x]))||q1.top().y!=g[q1.top().x])q1.pop();
    while(!eq(q2.top().sm,gets(q2.top().x,g[q2.top().x]+1))||q2.top().y!=g[q2.top().x])q2.pop();
}
void Solve(){
    init();
    while(q1.top().sm<q2.top().sm){
        node a=q1.top(),b=q2.top();
        q1.pop();q2.pop();
        res-=a.sm;res+=b.sm;
        a.y--;b.y++;
        q2.push(a);q1.push(b);
        g[b.x]++;g[a.x]--;
        if(g[a.x])q1.push((node){gets(a.x,g[a.x]),a.x,g[a.x]});
        q2.push((node){gets(b.x,g[b.x]+1),b.x,g[b.x]});
        init();
    }
}
signed main(){
    cin>>n>>t>>m;
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
    solve();
    for(int i=1;i<=n;i++){if(g[i])q1.push((node){gets(i,g[i]),i,g[i]});q2.push((node){gets(i,g[i]+1),i,g[i]});}
    for(int ii=1;ii<=m;ii++){
        int op,x;
        scanf("%lld%lld",&op,&x);
        for(int i=1;i<=g[x];i++){res-=gets(x,i);if(i>p[x])break;}
        if(op==1)p[x]++;
        else p[x]--;
        if(g[x])q1.push((node){gets(x,g[x]),x,g[x]});
        q2.push((node){gets(x,g[x]+1),x,g[x]});
        for(int i=1;i<=g[x];i++){res+=gets(x,i);if(i>p[x])break;}
        Solve();
        printf("%.15Lf\n",res);
    }
}