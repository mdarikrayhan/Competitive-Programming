#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n; cin >> n;
	string s; cin >> s;
	ll re = (n * (n - 1)) / 2;
	for(ll i = 0; i < n; i++){
		ll j = i;
		while(j < n - 1 && s[j + 1] != s[i])
			j++;
		re -= j - i;
		if(j > i) i = j - 1;
	}
	for(ll i = n - 1; i > 0; i--){
		ll j = i;
		while(j > 0 && s[j - 1] != s[i])
			j--;
		if(j < i - 1) re -= (i - j - 1);
		if(j < i) i = j + 1;
	}
	cout << re << "\n";
}