#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    char copy[250][250],update[250][250],basic[5][5];
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> basic[i][j];
    for(int i=0;i<249;i++) for(int j=0;j<249;j++) copy[i][j]=update[i][j]='*';
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) copy[i][j]=update[i][j]=basic[i][j];

    int n_basic=n;
    for(int index=1;index<k;index++)
    {
        for(int i=0;i<249;i++) for(int j=0;j<249;j++) update[i][j]='*';
        for(int i=0;i<n_basic;i++)
        {
            for(int j=0;j<n_basic;j++)
            {
                if(basic[i][j]=='.')
                {
                    for(int i1=i*n,i2=0;i1<(i*n)+n;i1++,i2++)
                    {
                        for(int j1=j*n,j2=0;j1<(j*n)+n;j1++,j2++)
                        {
                            update[i1][j1]=copy[i2][j2];
                        }
                    }
                }
            }
        }
        n*=n_basic;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) copy[i][j]=update[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << update[i][j];
        }cout << '\n';
    }
}
//