#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main(){
	ll T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		if(n%2==1){
			cout << "Bob" << endl;
		}
		else{
			if(log2(1.0*n) == (int)log2(1.0*n)){
				if((int)log2(n)%2==0){
					cout << "Alice" << endl;
				}
				else{
					cout << "Bob" << endl;
				}
			}
			else{
				cout << "Alice" << endl;
			}
		}
	}
	return 0;
}
