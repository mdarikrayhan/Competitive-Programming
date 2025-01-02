#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector <int> chocolate(n);
	
	for (int i = 0; i < n; i++){
		cin >> chocolate[i];
	}
	
	int cnts_alice = 0, cnts_bob = 0;
	int i = 0, j = n - 1;
	while (i <= j){
		if (cnts_alice + chocolate[i] <= cnts_bob + chocolate[j]){
			cnts_alice += chocolate[i];
			i++;
		}else{
			cnts_bob += chocolate[j];
			j--;
		}
	}
	cout << i << " " << n-i;
	
	return 0;
}