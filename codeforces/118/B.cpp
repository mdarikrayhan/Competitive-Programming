#include<bits/stdc++.h>
using namespace std;

int main()
  {
    int n;
    cin >> n;

    for(int i = 1;i <= 2*n;i++)
      cout << " ";
    cout << "0\n";
    for(int i = 2;i <= 2*n;i++)
      {
        if(i <= n+1)
          {
            for(int j = 2*i-1;j <= 2*n;j++)
              cout << " ";
            for(int j = 0;j < i;j++)
              cout << j << " ";
            for(int j = i-2;j >= 0;j--){
              if(j == 0)
                cout << j;
              else
                cout << j << " ";
            }
            cout << "\n";
          }
        else
          {
            for(int j = 1;j <= 2*(i-n-1);j++)
              cout << " ";
            for(int j = 0;j <= 2*n+1-i;j++)
              cout << j << " ";
            for(int j = 2*n-i;j >= 0;j--){
              if(j == 0)
                cout << "0";
              else
                cout << j << " ";
            }
            cout << "\n";
          }
      }
    for(int i = 1;i <= 2*n;i++)
      cout << " ";
    cout << "0";
  }