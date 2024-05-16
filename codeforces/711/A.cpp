#include<bits/stdc++.h>
using namespace std;

int main()
  {
    int n;
    cin >> n;
    string arr[n];
    for(int i = 0;i < n;i++)
      cin >> arr[i];

    int i, seat1, seat2;
    for(i = 0;i < n;i++)
      {
        if(arr[i][0] == 'O' && arr[i][1] == 'O'){
          seat1 = 0;
          seat2 = 1;
          break;
        }
        else if(arr[i][3] == 'O' && arr[i][4] == 'O'){
            seat1 = 3;
            seat2 = 4;
            break;
        }
      }
    if(i == n)
      cout << "NO\n";
    else
      {
        cout << "YES\n";
        for(int j = 0;j < n;j++)
          {
              for(int k = 0;k < 5;k++)
                {
                    if((j == i && k == seat1) || (j == i && k == seat2))
                      cout << "+";
                    else
                      cout << arr[j][k];
                }
              cout << "\n";
          }
      }
  }