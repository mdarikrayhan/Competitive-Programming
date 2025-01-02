#include<cstdio>
#include<algorithm>
using namespace std;
int _,n,c,l,r,ans,cnt;
char s[100001];
int main(){
	scanf("%d",&_);
	while(_--){
		scanf("%d%s",&n,s+1);ans=1e9;
		for(c='a';c<='z';c++){
			l=1;r=n;cnt=0;
			while(l<=r){
				if(s[l]==s[r])l++,r--;
				else if(s[l]==c)l++,cnt++;
				else if(s[r]==c)r--,cnt++;
				else{cnt=1e9;break;}
			}
			ans=min(ans,cnt);
		}
		printf("%d\n",ans==1e9?-1:ans);
	}
}