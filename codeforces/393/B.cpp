#include<bits/stdc++.h>
using namespace std ;

int main()
{   
    int n ; cin >> n ;
    double w[n][n] ;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> w[i][j] ;
        }
    }

    double a[n][n] = {0} ;
    double b[n][n] = {0} ;

    for(int i = 0 ; i < n ;i++)
    {
        a[i][i] = w[i][i] ;
    }

    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<n && j!=i;j++)
        {   
            double x = (w[i][j] + w[j][i])/2 ;
            a[i][j]   = a[j][i] = x ;
        }    
    }

    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<n && j!=i;j++)
        {   
            double x = max(w[i][j],w[j][i]) - a[i][j];
            if(w[i][j] > w[j][i])
            {
                b[i][j] = x  ;
                b[j][i] = -x ;
            }
            else
            {
                b[i][j] = -x ;
                b[j][i] = x ;
            }
           
            
        }    
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << fixed << setprecision(8) << a[i][j] << " " ;
        }
        cout << endl ;
    }
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << fixed << setprecision(8) << b[i][j] << " " ;
        }
        cout << endl ;
    }


    return 0;
}
