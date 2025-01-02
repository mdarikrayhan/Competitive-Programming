#include <bits/stdc++.h>

void solve(){
	int n;
	int p1 = 0, p2 = 0;
	std::cin >> n;
	if(n <= 7) {
		std::cout << "NO\n";
		return;
	}
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			p1 = i;
			n /= i;
			break;
		}
	}
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0 && i > p1 && n != i*i){
			p2 = i;
			n /= i;
			break;
		}
	}
	if(!p1 || !p2) std::cout << "NO\n";
	else std::cout << "YES\n" << p1 << ' ' << p2 << ' ' << n << '\n';
	return;
}

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}
}