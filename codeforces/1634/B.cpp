#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
long long n,x,y,a;
void solve()
{
		cin>>n>>x>>y;
		for(int i=0;i<n;i++){
			cin>>a;
			x=x+a%2;
		}
		if((y-x)%2)printf("Bob\n");
		else printf("Alice\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}