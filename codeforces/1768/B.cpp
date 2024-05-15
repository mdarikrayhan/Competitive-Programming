#include <math.h>
#include <stdio.h>
#include <string.h>
#include <set>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>

#include <climits>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#define ll long long int
#define lf long float

#define PI 3.1415926535897932384626433832795
using namespace std;

int main()
{

     int t;
    cin >> t;
    while (t--)
    {
     int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt = 1;
	for(int i=0;i<n;i++){
		if(a[i] == cnt){
			cnt++;
		}
	}
	cout<<(n-cnt+k)/k<<endl;

    }
    return 0;
}
