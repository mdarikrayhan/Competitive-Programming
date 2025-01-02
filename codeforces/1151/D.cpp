#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ; cin >> n;
    long long int a[n],b[n],c[n];
    long long int sum =0;
    long long int suma =0 , sumb =0;
    for (int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        c[i] = a[i] - b[i];
        suma += a[i];
        sumb += b[i];
    }

    sort(c,c+n,greater<int>());
    for(int j=0;j< n;j++)
    {
        sum  += c[j] * (j+1);
    }
    sum = sum - suma + n*sumb;
    cout << sum;
    

}