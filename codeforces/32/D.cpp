// LUOGU_RID: 159679077
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    char c[n+1][m+1];
    for(int i=1;i<=n;++i)
    	for(int j=1;j<=m;++j)
    		cin>>c[i][j];
    int num=0;
    for(int r=1;r<=min(n,m);r++){
        for(int i=r+1;i+r<=n;i++){
            for(int j=r+1;j+r<=m;j++){
                if(c[i][j]=='*'&&c[i-r][j]=='*'&&c[i+r][j]=='*'&&c[i][j-r]=='*'&&c[i][j+r]=='*'){
    				if(num==k-1){
    					cout<<i<<' '<<j<<endl<<i-r<<' '<<j<<endl<<i+r<<' '<<j<<endl<<i<<' '<<j-r<<endl<<i<<' '<<j+r<<endl;
    					return 0;
    				}
    				else
    					++num;
    			}
            }
        }
    }
    	
    cout<<-1<<endl;
    return 0;
}