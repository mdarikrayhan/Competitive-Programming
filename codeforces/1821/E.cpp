#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;cin>>t;
	while(t--){
		int a;cin>>a;
		string s;cin>>s;long long ans=0;
		priority_queue<int> pq;
		stack<int> st;
		for(int j=0;j<s.length();j++){
			if(s[j]=='(') st.push(j);
			else{
				int y=st.top();
				st.pop();
				ans+=(((j-1)-y)/2);
				pq.push((j-1)-y);
			}
		}
		while(a--){
			int xx=pq.top();
			pq.pop();
			ans-=xx/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}