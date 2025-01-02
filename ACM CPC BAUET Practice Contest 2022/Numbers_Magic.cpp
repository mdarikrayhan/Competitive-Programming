/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int T;
cin >> T;
for(int testcaseno=1;testcaseno<=T;testcaseno++)
{
    int arr[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }
    long long row1=0,row2=0,row3=0,row4=0;
    long long col1=0,col2=0,col3=0,col4=0;
    long long diag1=0,diag2=0;
    long long corner1=0,corner2=0,corner3=0,corner4=0;
    for(int i=0;i<4;i++)
    {
        row1+=arr[0][i];
        row2+=arr[1][i];
        row3+=arr[2][i];
        row4+=arr[3][i];
        col1+=arr[i][0];
        col2+=arr[i][1];
        col3+=arr[i][2];
        col4+=arr[i][3];
        diag1+=arr[i][i];
        diag2+=arr[3-i][i];
    }
    corner1=arr[0][0]+arr[0][1]+arr[1][0]+arr[1][1];
    corner2=arr[0][2]+arr[0][3]+arr[1][2]+arr[1][3];
    corner3=arr[2][0]+arr[2][1]+arr[3][0]+arr[3][1];
    corner4=arr[2][2]+arr[2][3]+arr[3][2]+arr[3][3];
    if(row1==row2 && row1==row3 && row1==row4 && row1==col1 && row1==col2 && row1==col3 && row1==col4 && row1==diag1 && row1==diag2&&row1==corner1&&row1==corner2&&row1==corner3&&row1==corner4)
    {
        cout <<"Case "<<testcaseno<< " : YES, Magic!" << nl;
        cout<<row1<<nl;
    }
    else
    {
        cout <<"Case "<<testcaseno<< " : NO, Magic!" << nl;
    }
}
return 0;
}