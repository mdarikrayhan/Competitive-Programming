// LUOGU_RID: 99434142
#include<bits/stdc++.h>
using namespace std;const int N=6e5+2;
int n,a,s,t,d[N],x;vector<int> v[N],g;queue<int> q;
int main(){
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%d",&a);
for(int j=2;j*j<=a;j++)if(a%j==0){
v[i].push_back(n+j),v[n+j].push_back(i);
while(a%j==0)a/=j;
}
if(a>1)v[i].push_back(n+a),v[n+a].push_back(i);
}
scanf("%d%d",&s,&t);
q.push(s),d[s]=1;
while(!q.empty()){
x=q.front(),q.pop();
for(int k:v[x])if(!d[k])d[k]=d[x]+1,q.push(k);
}
if(!d[t]){printf("-1\n");return 0;}
g.push_back(t);
for(int i=t;i!=s;)for(int k:v[i])if(d[k]+1==d[i])
{i=k,g.push_back(k);break;}
reverse(g.begin(),g.end());
printf("%d\n",(g.size()+1)/2);
for(int k:g)if(k<=n)printf("%d ",k);
return printf("\n"),0;
}