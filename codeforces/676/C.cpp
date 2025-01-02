#include<bits/stdc++.h>
#define al long long
#define pb push_back
#define ff first
#define st second
#define af cout
#define ak "\n"
#define an endl
#define all(x) x.begin(),x.end()
#define OK  cout << __LINE__ << "| "<< "-----------------OK--------------" << endl;
#define deb(x) cout << __LINE__ << "| "<< #x  << " = " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
const al mod=1e9+7;
const al inf=1e18,nn=1e6+9;
al n,k,ans;
al d[nn][3];
string s;
void tp(){
	cin>>n>>k>>s;
	s=")"+s;
	for(al i=1;i<=n;i++){
		d[i][1]=d[i-1][1];
		d[i][0]=d[i-1][0];
		d[i][s[i]-'a']++;
	}
	for(al i=1;i<=n;i++){
		for(al j=0;j<=1;j++){
			al ok=i-1,l=i,r=n;
			while(l<=r){
				al m=(l+r)/2;
				if(d[m][j]-d[i-1][j]<=k){
					ok=m;
					l=m+1;
				}
				else{
					r=m-1;
				}
			}
			ans=max(ans,ok-i+1);
		}
	}
	af<<ans<<ak;
}
signed main(){
    // OPEN;
    al tt=1;
    fast;
//    cin>>tt;
    while(tt--){
        tp();
    }
}
