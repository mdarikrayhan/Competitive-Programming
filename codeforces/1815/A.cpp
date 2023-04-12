#include <iostream>
using namespace std;
int main(){
	int T, N, x;
	for(cin >> T; T; T--){
		cin >> N;
		long long s[2] = {0, 0};
		for(int i=0; i<N; i++){
			cin >> x;
			s[i%2] += x;
		}
		if(N%2 || s[0] <= s[1])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}


//////