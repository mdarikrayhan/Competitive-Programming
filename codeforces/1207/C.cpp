#include<bits/stdc++.h>
#define int long long
using namespace std;
const int oo=(1ll<<62); 
const int N=2e5+10;
int n,a,b;
string s;
int f[N][2];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> a >> b;
        cin >> s;
        f[0][0] = b;
        f[0][1] = oo;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                f[i+1][0] = min(f[i][0],f[i][1] + a) + a + b;
                f[i+1][1] = min(f[i][0] + a , f[i][1]) + a + 2*b;
            }
            else{
                f[i+1][1] = f[i][1] + a + 2*b;
                f[i+1][0] = oo;
            }
        }
        cout << f[n][0] << endl;
    }
    return 0;
}