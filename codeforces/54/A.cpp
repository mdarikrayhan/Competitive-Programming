#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, k, c;
	cin>>n>>k>>c;
	bool d[n+1];
	memset(d,0,sizeof(d));
	int idx;
	for (int i=0; i<c; i++) {
		cin>>idx;
		d[idx] = true;
	}
	int ans=0, start=0;
	for (int i=1; i<=n; i++) {
		if (d[i] || i==k+start) {
			ans++;
			start = i;
		}
	}
	cout<<ans<<endl;
}

