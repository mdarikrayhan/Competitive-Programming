#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve() {
    int n,x,a[55];
cin>>n;
		for(int i=0;i<=54;i++) a[i]=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			while(x>n) x/=2;
			while(a[x]&&x>0) x/=2;
			a[x]=1;
		}
		if(a[0]) puts("NO");
		else puts("YES");
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T = 1;
cin >> T;
while(T--) {
solve();
}
return 0;
}