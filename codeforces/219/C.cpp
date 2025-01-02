// LUOGU_RID: 160015865
#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,k;
	cin >> n >> k >> s;
	if(k == 2){
		string a,b;
		int x = 0,y = 0;
		for(int i = 0;i < n;i++){
			a += 'A' + (i & 1);
			b += 'A' + !(i & 1);
			x += a[i] != s[i];
			y += b[i] != s[i];
		}
		cout << min(x,y) << '\n' << (move(x) < move(y)?move(a):move(b));
		return 0;
	}
	int ans = 0;
	for(int i = 1;i < n;i++)
		if(s[i] == s[i-1]){
			++ans;
			if(i == n - 1)s[i] = s[i-1] == 'A'?'B':'A';
			else if(s[i-1] == 'A')
				if(s[i+1] == 'B')s[i] = 'C';
			else s[i] = 'B';
			else if(s[i+1] == 'A')
				if(s[i-1] == 'B')s[i] = 'C';
			else s[i] = 'B';
			else s[i] = 'A';
		}
	cout << move(ans) << '\n' << move(s);
}
