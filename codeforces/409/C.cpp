#include<bits/stdc++.h>
#define For(i,a,n) for(int i =a ; i < n ; ++i )
#define all(x) (x).begin(),(x).end()
#define n(x) (int)(x).size()
#define pb(x) push_back(x)
#define fr first
#define sc second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int smax = 9999;
int val[5]={1,1,2,7,4};
int a[5];

int main()
{
	ios::sync_with_stdio(false);
	For(i,0,5){
		cin >> a[i];
		smax = min(a[i]/val[i],smax);
	}
	cout << smax << endl;
	return 0;
}