// LUOGU_RID: 160548999
#include<bits/stdc++.h>
using namespace std;
int n,dxy[4][2]={1,1,-1,-1,-1,1,1,-1};
char a[55][55];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]=='0') continue;
            int cnt=0;
            for(int k=0;k<=3;k++)
                if(a[i+dxy[k][0]][j+dxy[k][1]]!='0')
                    cnt++;
            if(a[i][j]-'0'!=cnt){
                cout<<"No";
                return 0; 
            }
        }
    cout<<"Yes"; 
    return 0; 
}