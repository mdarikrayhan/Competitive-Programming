#include<bits/stdc++.h>
using namespace std;
int T,n,a[200005],b[200005],m,x;

bool bb;
int main()
{
scanf("%d",&T);
while(T--){
bb=0; map<int,int>mapp; stack<int>q;
scanf("%d",&n);
for(int i=1;i<=n;i++) scanf("%d",a+i);
for(int i=1;i<=n;i++) scanf("%d",b+i);
scanf("%d",&m);
for(int i=1;i<=m;i++) scanf("%d",&x),mapp[x]++;
for(int i=1;i<=n;i++){
if(a[i]<b[i]){bb=1;break;}
while(!q.empty()&&q.top()<b[i]) q.pop();
if((q.empty()||(!q.empty()&&q.top()!=b[i]))&&a[i]>b[i]){
q.push(b[i]);
if(mapp[b[i]]<=0){bb=1;break;}
mapp[b[i]]--;
}
}
puts((bb?"NO":"YES"));
}
}