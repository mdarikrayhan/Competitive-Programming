#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n == 0){
    	cout << 1;
    }else if (n == 1){
    	cout << 4;
    }else{
    	int k = 2*n/sqrt(2) - 1;
		cout << 4*(k+1);
    }
    

	return 0;
} 