#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define int long long
using namespace std;
int a,b,c,p,q,w,x,y,z,ans=1145141919810;
bool inline check(int v1,int v2,int v3){
    int v=v2-w;
    if(v<=0) return false;
    v=(p+v-1)/v;
    v=v1-v*max((int)0,q-v3);
    return v>0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin >> a >> b >> c >> p >> q >> w >> x >> y >> z;
    for(int i=0;i<=10001;i++){
        for(int j=0;j<=201;j++){
            for(int k=0;k<=101;k++){
                if(check(a+i,b+j,c+k)){
                    ans=min(ans,i*x+j*y+k*z);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
 						 	 		 	 	  		 			   		