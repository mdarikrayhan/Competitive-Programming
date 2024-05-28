// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,k;cin >> t >> k;
    while(t--){
	    int n,m;cin >> n >> m;
	    n--,m--;
	    if(k == 1){
            cout << ((n % 2 == 0 && m % 2 == 0) ? "-" : "+") << endl;
		    continue;
	    }
	    if(min(n,m) % (k + 1) == k){
            cout << "+" << endl;
	    }
	    else{
	        cout << (((n + m) % 2) ^ (min(n,m) / (k + 1) % 2) ? "+" : "-") << endl;
	    }
    }
}