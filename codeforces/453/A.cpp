#include<bits/stdc++.h>

using namespace std;

double ans;

int n, m;

int main(){
  cin >> m >> n;
  for(int i = 1; i <= m; ++i){
    ans += (pow(1.0 * i / m, n) - pow(1.0 * (i - 1) / m, n)) * i;
  }
  cout << fixed << setprecision(12) << ans;
  return 0;
}

	  	 	 	 	 	 			 		  		   	