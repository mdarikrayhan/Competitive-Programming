#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int num(char s){
	return s - '0';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s ; cin >> s;
	int n = (int)s.size();
	int pref[n] , suf[n];
	pref[0] = num(s[0]);
	suf[n - 1] = num(s[n - 1]);
	for(int i = 1 ; i < n ; i++){
		pref[i] = pref[i - 1] * num(s[i]);
	}
	for(int i = n - 2 ; i >= 0 ; i--){
		suf[i] = suf[i + 1] * num(s[i]);
	}
	int ans = 0 , tem = 1;

	for(int i = 0 ; i < n ; i++){
		if(num(s[i]) - 1 > 0){
			int tem1 = (i > 0 ? pref[i - 1] :1) * (num(s[i]) - 1) * (pow(9,n - i - 1));
			int tem2 = (i > 0 ? pref[i - 1] :1)  * suf[i];
			int tem3 = max(tem1 , tem2);
			ans = max(ans , tem3);
		}else if(num(s[i]) - 1 == 0 and i == 0){
			int tem4 = pow(9 , n - i - 1);
			ans = max(ans , tem4);
		}
	}
	cout << ans << '\n';

}
		  			 			     	  		 			 	 	