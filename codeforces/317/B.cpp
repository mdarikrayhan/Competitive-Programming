#include<bits/stdc++.h>
using namespace std;
int n,t;
int cnt[201][201];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>t;
    cnt[100][100]=n;
    while(1){
        vector<int> x,y,add;
        for(int i=1;i<=200;i++){
            for(int j=1;j<=200;j++){
                if(cnt[i][j]>=4){
                    x.push_back(i+1); y.push_back(j);
                    x.push_back(i-1); y.push_back(j);
                    x.push_back(i); y.push_back(j+1);
                    x.push_back(i); y.push_back(j-1);
                    for(int k=1;k<=4;k++) add.push_back(cnt[i][j]/4);
                    cnt[i][j]%=4;
                }
            }
        }
        if(x.empty()) break;
        for(int i=0;i<x.size();i++){
            cnt[x[i]][y[i]]+=add[i];
        }
    }
    for(int i=1;i<=t;i++){
        int x,y;
        cin>>x>>y;
        if(x+100<0||x+100>200||y+100<0||y+100>200) cout<<0<<'\n';
        else cout<<cnt[x+100][y+100]<<'\n';
    }
    return 0;
}

	  			 				 	 	    				  			 	