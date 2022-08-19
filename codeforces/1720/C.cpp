/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, m,no1=0,flag=0;
        cin >> n >> m;
        char a[n+5][m+5];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='1')
                {
                    no1++;
                }
            }
        }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(a[i][j]=='0'&&(a[i+1][j+1]=='0'||a[i+1][j]=='0'||a[i][j+1]=='0')){
                flag=1;
                break;
            }
            else if(a[i+1][j]=='0'&&a[i][j+1]=='0'){
                flag=1;
                break;
            }
            else if((a[i][j+1]=='0'||a[i+1][j]=='0')&&a[i+1][j+1]=='0'){
                flag=1;
                break;
            }
        }
        if(flag==1)
        break;
    }
        if(flag==1){
            cout<<no1<<nl;
        }
        else if(no1==(m*n)){
            cout<<no1-2<<nl;
        }
        else{
            cout<<no1-1<<nl;
        }
    }
    return 0;
}