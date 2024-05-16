#include<bits/stdc++.h>
using namespace std;

int main(){
	int times; cin >> times;
	while(times--){
		int n; cin >> n;
		int l[n], r[n];
		vector mark(n + 1, vector<bool>(n + 1));
		for(int i = 0 ; i < n ; i++){
			cin >> l[i] >> r[i];
			mark[l[i]][r[i]] = 1;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = l[i]; j <= r[i]; j++) {
				if ((j == l[i] or mark[l[i]][j - 1]) and (j == r[i] or mark[j + 1][r[i]])) {
					cout << l[i] << ' ' << r[i] << ' ' << j << endl;
					break;
				}
			}
		}
	}
	
	return 0;
}
 		   			      	  						 		 			