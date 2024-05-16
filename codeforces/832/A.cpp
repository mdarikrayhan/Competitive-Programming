// LUOGU_RID: 159011329
#include <iostream>

using namespace std;
int main(){
	long long n,k;
	cin >> n;
	cin >> k;
	if((n/k)&1){
	cout << "YES";
	} else {
	cout << "NO";
	}
}