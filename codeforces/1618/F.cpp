#include<bits/stdc++.h>
#define int long long

using namespace std;
int x,y;
map<string ,int> mp;
string st , en;

int get_num(string str){
	reverse(str.begin(),str.end());
	int res = 0;
	int mul = 1;
	for(char c: str){
		if(c=='1'){
			res += mul;
		}
		mul *= 2;
	}
	return res;
}

string get_string(int num){
	int high = 63 - __builtin_clzll(num);
	string res = "";
	for (int i = 0; i <= high; ++i)
	{
		if(num & (1ll<<i))
			res += '1';
		else
			res += '0';
	}
	reverse(res.begin() , res.end());
	return res;
}

bool dfs(string str){
	if(str.size() > 64 )
		return false;
	mp[str] = 1;
	string one = str + '1';
	reverse( one.begin() , one.end() );
	int i = str.size()-1;
	while(str[i]=='0')
		i--;
	string zero = str.substr(0,i+1);
	reverse(zero.begin(),zero.end());
	//cout<<str<<" "<<one<<" "<<zero<<endl;
	if(one==en or zero==en)
		return true;
	bool o = (mp.find(one) == mp.end());
	bool z = (mp.find(zero) == mp.end());
	if(o and z)
		return dfs(one) or dfs(zero);
	else if(o)
		return dfs(one);
	else if(z)
		return dfs(zero);
	return false;

}

void solve(){
	cin>>x>>y;
	if(x==y){
		cout<<"YES\n";
		return;
	}
	if(y%2==0){
		cout<<"NO\n";
		return;
	}
	st = get_string(x);
	en = get_string(y);
	//cout<<st<<" "<<en<<endl;
	if(dfs(st)){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}