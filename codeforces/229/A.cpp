#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> v(n,vector<char> (m));
        bool flag=0;
        for(int i=0;i<n;i++) {
            bool flag1=1;
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                if(v[i][j]=='1') flag1=0;
            }
            flag|=flag1;
        }
        if(flag) cout<<-1<<endl;
        else{
            vector<vector<int>> diff(n,vector<int> (m,m));
            for(int i=0;i<n;i++){
                int ind=-1e9;
                int first=-1,last;
                for(int j=0;j<m;j++){
                    if(v[i][j]=='1') last=j;
                    if(v[i][j]=='1'&&first==-1) first=j;
                }
                for(int j=0;j<m;j++){
                    if(v[i][j]=='1') ind=j;
                    diff[i][j]=min(diff[i][j],(j-ind));
                    if(j<=last) diff[i][j]=min(diff[i][j],m-last+j);
                }
                ind=1e9;
                for(int j=m-1;j>=0;j--){
                    if(v[i][j]=='1') ind=j;
                    diff[i][j]=min(diff[i][j],(ind-j));
                    if(j>=first) diff[i][j]=min(diff[i][j],first+m-j);
                }
            }
            int ans=INT_MAX;
            for(int j=0;j<m;j++){
                int ct=0;
                for(int i=0;i<n;i++){
                    ct+=diff[i][j];
                }
                ans=min(ans,ct);
            }

            cout<<ans<<endl;
        }

    }
    
    return 0;
}