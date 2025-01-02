#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>a(n,vector<int>(m));
        int cnt1=0,cnt2=0;
        a[0][0]=0;
        for(int i=1;i<m;i++){
            if(cnt1<2){
                a[0][i]=1;
                cnt1++;
            }
            else{
                a[0][i]=0;
                cnt2++;
                if(cnt2==2){
                    cnt1=0;
                    cnt2=0;
                }
            }
        }
        int cnt=0;

        for(int i=1;i<n;i++){
                for(int j=0;j<m;j++){
                    if(cnt==0){
                        a[i][j]=(!a[i-1][j]);
                    }
                    else if(cnt==1){
                        a[i][j]=a[i-1][j];
                    }
                }
                cnt=(!cnt);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}