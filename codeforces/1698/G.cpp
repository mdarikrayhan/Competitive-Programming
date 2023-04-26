#include<bits/stdc++.h>
using namespace std;const int B=1<<18;typedef long long ll;
ll p,bin[B+10],ans,v;char s[40];int st,ed,i;map<ll,int>mp;
inline ll mod(ll x){if(x<(1LL<<(ed-st)))return x;return x^p;}
inline ll mul(ll a,ll b){ll res=0;for(int i=0;i<=ed-st;++i,a<<=1,a=mod(a))if(b>>i&1)res^=a;return mod(res);}
int main(){
	scanf("%s",s+1);ed=strlen(s+1);
	for(st=1;st<=ed&&s[st]=='0';++st);
	if(st>ed){return 0*puts("-1");}
	for(;s[ed]=='0';--ed);
	for(i=st;i<=ed;++i)p=p*2+s[i]-'0';
	if(p<2){printf("%d %d\n",st,st+1);return 0;}
	for(i=bin[0]=1;i<=B;++i)bin[i]=mul(bin[i-1],2),mp[bin[i-1]]=i-1;
	for(ans=B,v=bin[B];1;v=mul(v,bin[B]),ans+=B)
		if(mp.count(v))return 0*printf("%d %lld\n",st,st+ans-mp[v]);
}