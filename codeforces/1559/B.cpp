#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll MOD=1e9+7;
using namespace std;
ll T,N;
char ans[105];
string s;
int main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>N;
		cin>>s;
		char last='B';
		ll id=-1;
		for(int j=0;j<s.length();j++){
			if(s[j]!='?'){
				ans[j]=s[j];
				ll cnt=0;
				for(int k=j-1;k>id;k--){
					cnt++;
					if(cnt%2==0){
						ans[k]=s[j];
					}
					else{
						if(s[j]=='B'){
							ans[k]='R';
						}
						else{
							ans[k]='B';
						}
					}
				}
				id=j;
				last=s[j];
			}
		}
		if(id!=N-1){
			for(int k=id+1;k<N;k++){
				if((k-id)%2==1){
					if(last=='B'){
						ans[k]='R';
					}
					else{
						ans[k]='B';
					}
				}
				else{
					ans[k]=last;
				}
			}
		}
		for(int j=0;j<N;j++){
			cout<<ans[j];
		}
		cout<<endl;
	}
}