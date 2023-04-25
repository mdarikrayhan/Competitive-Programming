#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t[26],T,n,len,p[26],ans,w;
char s[N],q[N];
bool cmp(int x,int y){
return t[x]>t[y];
}
int main(){
scanf("%d",&T);
while(T--){
scanf("%d%s",&n,s);
for(int i=0;i<n;i++) t[s[i]-'a']++;
for(int i=0;i<26;i++) p[i]=i;
sort(p,p+26,cmp),ans=99999999;
for(int i=1;i<=26;i++){
if(n%i) continue;
int x=n/i,s=0;
for(int j=0;j<i;j++) s+=max(0,x-t[p[j]]);
if(s<ans) ans=s,w=i;
}
for(int j=0;j<w;j++){
if(t[p[j]]>n/w) t[p[j]]=n/w;
else for(int i=t[p[j]];i<n/w;i++) q[++len]=p[j]+'a';
}
for(int j=w;j<26;j++) t[p[j]]=0;
for(int i=0;i<n;i++){
int x=s[i]-'a';
if(t[x]) t[x]--;
else s[i]=q[len--];
}
printf("%d\n%s\n",ans,s),len=0;
}
}