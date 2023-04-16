#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main() {
	int t;cin>>t;
	while(t--){
		string s;
		cin>>s;
		s+=s;
		int n=s.length();
		int cnt=0;
		int curr=0;
		for(int i=0;i<n-1;i++){
			if(s[i]=='0'){
				cnt=max(cnt,curr);
				curr=0;
				
			}else{
				curr++;
			}
		}
		cnt=max(cnt,curr);
		if(cnt>=n){
			cout<<n*n<<endl;
		}else{
			cnt++;
			cout<<(cnt/2)*(cnt-cnt/2)<<endl;
		}
    }
}