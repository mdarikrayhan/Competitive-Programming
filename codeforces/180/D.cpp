// LUOGU_RID: 158566160
#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)
using namespace std;
const ll N=1e6+9;
ll n,m,cnt[27];
char s[N],t[N],ans[N],cur[N];
bool cmp(char*s,char*t){
	rep(i,1,max(n,m)){
		if(s[i]>t[i])return 1;
		if(s[i]<t[i])return 0;
	}
	return 0;
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	rep(i,1,n)cnt[s[i]-'a']++;
	sort(s+1,s+n+1,greater<char>());
	if(!cmp(s,t))return puts("-1"),0;
	rep(i,1,n)ans[i]=s[i];
	rep(i,0,m){
		ll lb=(i==m?0:t[i+1]-'a'+1),nxt=-1;
		rep(j,lb,25){
			if(cnt[j]){nxt=j;break;}
		}
		if(nxt!=-1){
			cur[i+1]=nxt+'a';
			cnt[nxt]--;
			ll len=i+1;
			rep(j,0,25){
				rep(k,1,cnt[j])cur[++len]=j+'a';
			}
			if(cmp(ans,cur))memcpy(ans,cur,sizeof(cur));
			cnt[nxt]++;
		}
		if(i==m)break;
		cnt[t[i+1]-'a']--;
		cur[i+1]=t[i+1];
		if(cnt[t[i+1]-'a']<0)break;
	}
	rep(i,1,n)cout<<ans[i];
	return 0;
}