#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

const int M=1000+10;
typedef long long int ll;



int main() {
	
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	int n,a,b; cin>>n>>a>>b;
	int x = -1; int y = -1;
	for (int i = 0; i * a <= n; i++){
		int v = n - i * a;
		if (v % b == 0 && v >= 0){
			x = i;
			y = v / b;
			break;
		}
	}
	
	if (x == -1){
		cout<<-1<<endl;
		return 0;
	}
	
	for (int i = 1; i <= x * a; i+=a){
		int low = i;
		int high = low + a - 1;
		for (int j = low + 1; j <= high; j++){
			cout<<j<<" ";
		}
		cout<<low<<" ";
	}
	for (int i = x * a + 1; i <= n; i+=b){
		int low = i;
		int high = low + b - 1;
		for (int j = low + 1; j <= high; j++){
			cout<<j<<" ";
		}
		cout<<low<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
