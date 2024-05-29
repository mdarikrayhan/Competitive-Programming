#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
set<string>s;
int ch[2001000][4];
struct qq{
ll a,b;
qq operator + (const qq &x) const{
if(a==-1||x.a==-1)return (qq){-1,-1};
return (qq){a+x.a,b+x.b};
}
qq operator + (const int &x) const{
if(a==-1)return (qq){-1,-1};
return (qq){a+x,b+x};
}
qq operator * (const qq &x) const{
if(a==-1)return x;if(x.a==-1)return (qq){a,b};
return (qq){min(a,x.a),max(b,x.b)};
}
};
struct hb{qq ab,bc,cd,ad,ac,bd,f;int is;}A[30],f[2001000],I;
bool chk(string a,string b){
for(int i=0;i<n;i++){
if(a[i]!=b[i]){
if(abs(a[i]-b[i])==2)return 0;
for(int j=i+1;j<n;j++)if(a[i]!=b[j]||b[i]!=a[j])return 0;
return 1;
}
}
return 1;
}
hb mer(hb &a,hb &b,hb &c,hb &d){
hb e;
e.f=(qq){-1,-1};
int az=a.is+b.is+c.is+d.is;
if(az==1){
if(a.is)e.f=a.f;if(b.is)e.f=b.f;
if(c.is)e.f=c.f;if(d.is)e.f=d.f;
}
e.f=e.f*(a.bd+c.bd+d.ac+b.ac+4);
e.is=a.is|b.is|c.is|d.is;
e.ab=a.ad+d.ac+c.bd+b.bc+3;
if(!c.is&&!d.is)e.ab=e.ab*(a.ab+b.ab+1);
e.bc=b.ab+a.bd+d.ac+c.cd+3;
if(!a.is&&!d.is)e.bc=e.bc*(b.bc+c.bc+1);
e.cd=c.bc+b.ac+a.bd+d.ad+3;
if(!b.is&&!a.is)e.cd=e.cd*(c.cd+d.cd+1);
e.ad=d.cd+c.bd+b.ac+a.ab+3;
if(!b.is&&!c.is)e.ad=e.ad*(a.ad+d.ad+1);
e.ac=((!d.is)?(a.ab+b.ac+c.bc+2):(qq){-1,-1})*((!b.is)?(a.ad+d.ac+c.cd+2):(qq){-1,-1});
e.bd=((!a.is)?(b.bc+c.bd+d.cd+2):(qq){-1,-1})*((!c.is)?(b.ab+a.bd+d.ad+2):(qq){-1,-1});
return e;
}
int rt=1,cn=1,sta[30];
void ins(string s,int z){
int u=1;
for(int i=0;i<n;i++){
int p=s[i]-'a';
if(!ch[u][p])ch[u][p]=++cn;
sta[i]=u,u=ch[u][p];
}
if(z==1)f[u]=I;else f[u]=A[0];
for(int i=n-1;i>=0;i--){
u=sta[i];
f[u]=mer(ch[u][0]?f[ch[u][0]]:A[n-i-1],ch[u][1]?f[ch[u][1]]:A[n-i-1],ch[u][2]?f[ch[u][2]]:A[n-i-1],ch[u][3]?f[ch[u][3]]:A[n-i-1]);
}
}
int main(){
scanf("%d%d",&n,&q);
A[0].f=(qq){-1,-1};I=A[0],I.is=1;
for(int i=1;i<=n;i++)A[i]=mer(A[i-1],A[i-1],A[i-1],A[i-1]);
for(int i=1;i<=q;i++){
string ss;cin>>ss;
int z;
if(s.find(ss)!=s.end())z=-1,s.erase(ss);
else z=1,s.insert(ss);
ins(ss,z);
qq ans=f[1].f;
if((int)s.size()<=1)ans=ans*((qq){2,2});
if(((int)s.size()==2)&&chk(*s.begin(),*(--s.end())))ans=ans*((qq){2,2});
if(ans.a==-1)puts("-1");
else printf("%lld %lld\n",ans.a,ans.b);
}
return 0;
}