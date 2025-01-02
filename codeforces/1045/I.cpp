#include<bits/stdc++.h>
using namespace std;
void helper(int n){
	for(int i=0;i<26;i++){
		if((n>>i)&1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	cout<<endl<<endl;
}
int main(){
	int n;cin>>n;
	vector<vector<int> > vec(n,vector<int>(26,0));
	map<int,int> mp;
	vector<int> new_vec;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(auto ch: s){
			vec[i][ch-'a']++;
		}
		int bits=0;
		for(int k=0;k<26;k++){
			if(vec[i][k]%2!=0){
				bits=(bits|(1<<k));
			}
		}
		//cout<<endl<<endl;
		new_vec.push_back(bits);
		mp[bits]++;
		//helper(bits);cout<<endl;
	}
	long long int ans=0;
	for(int i=0;i<n;i++){
		// keep same thing and add extra odds
		int bits=new_vec[i];
		//helper(bits);
		ans+=(mp[bits]-1);
		for(int k=0;k<26;k++){
			if(!((bits>>k)&1)){
				int new_bits= (bits|(1<<k));
				//helper(new_bits);

				if(mp.find(new_bits)!=mp.end()) ans+=(mp[new_bits]);
			}
		}
		//cout<<string(20,'_')<<endl;
		for(int k=0;k<26;k++){
			if((bits>>k)&1){
				int new_bits= bits^(1<<k);
				if(mp.find(new_bits)!=mp.end()) ans+=(mp[new_bits]);
			}
		}
	}
	cout<<ans/2;
}