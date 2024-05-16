#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int a;
    cin >> a;
    vector <int> s(a+1);
    for(int i=1; i<=a; i++)
    {
        cin >> s[i];
    }
    //======================================
    if(a==1)
    {
        cout << 1;
        return 0;
    }
    //======================================
    int sum_max=1;
    int j=1;
    while(s[j+1] <= s[j] and j <= a-1)
    {
        sum_max++;
        j++;
    }
    if(sum_max==a)
    {
        cout << sum_max;
        return 0;
    }
    //======================================
    for(int i=2; i<=a; i++)
    {
        int mi=i, ma=i;
        int sum=1;
        while(s[mi-1]<=s[mi] and mi-1 >= 1)
              {
              mi--;
              sum++;
              }
        while(s[ma+1]<=s[ma] and ma+1 <= a)
              {
              ma++;
              sum++;
              }
        if(sum == a)
        {
            cout << a;
            return 0;
        }
        if(sum > sum_max)
        {
            sum_max = sum;
        }
    }
    cout << sum_max;
}