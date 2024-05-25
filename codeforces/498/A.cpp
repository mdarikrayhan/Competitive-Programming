#include <iostream>
using namespace std;

int main()
{
    long long int x1, y1, x2, y2, n;
    cin>>x1>>y1>>x2>>y2>>n;
    long long int d[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>d[i][j];
        }
    }
    long long int ans = 0;
    for(int i=0;i<n;i++)
    {
        long long int d1 = d[i][0]*x1+d[i][1]*y1+d[i][2];
        long long int d2 = d[i][0]*x2+d[i][1]*y2+d[i][2];
        if ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) ans++;
    }
    cout<<ans<<'\n';
}