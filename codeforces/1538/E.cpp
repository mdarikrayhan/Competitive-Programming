#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x;
map<string,pair<string,long long > > mp;
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		string s1,s2,s3,s4,c,op;
		for(int i=0; i<n; i++) {
			cin>>s2>>op;
			if(op[0]==':') {
				cin>>s1,x=0,k=s1.size();
				if(k>3&&s1.substr(0,4)=="haha"||k>4&&s1.substr(1,4)=="haha") x++;
			} else {
				cin>>s1>>c>>s3;
				x=mp[s1].second+mp[s3].second, s1=mp[s1].first,s3=mp[s3].first;
				s4=s1.size()>=4?s1.substr(s1.size()-3,3):s1;
				s4+=s3.size()>=4?s3.substr(0,3):s3;
				if(s1.size()>=4) s1=s1.substr(0,3);
				s1+=s3.size()>=4?s3.substr(s3.size()-3,3):s3;
				k=s4.size();
				if(k>=4&&s4.substr(0,4)=="haha"||k>=5&&s4.substr(1,4)=="haha") x++;
				if(k>=6&&s4.substr(2,4)=="haha") x++;
			}
			mp[s2].first=s1,mp[s2].second=x;
		}
		cout<<mp[s2].second<<endl;
	}
	return 0;
}