//   you're already the best
//             _
//   ^ ^      //
// >(O_O)<___//
//   \ __ __  \
//    \\ \\ \\\\
//
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	
	if(n<9){
		cout<<1<<endl;
		return;
	}
	
	int t=n,cnt=0,idx;
	while(t){
		cnt++;
		idx=t%10;
		t/=10;
	}
	idx++,cnt--;
	
	cout<<(int)pow(10,cnt)*idx-n<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return (0-0);
}
