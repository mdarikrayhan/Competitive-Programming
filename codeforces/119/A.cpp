#include<bits/stdc++.h>
using namespace std;

int main()
  {
    int a, b, n;
    cin >> a >> b >> n;

    int s = 0, as = 0, ct = 1;
    while(n >= 0)
      {
        if(ct%2)
          {
            if(n >= __gcd(a, n)){
              n -= __gcd(a, n);
              s++;
              ct++;
            }
            else
              break;
          }
        else
          {
            if(n >= __gcd(b, n)){
              n -= __gcd(b, n);
              as++;
              ct++;
            }
            else
              break;
          }
      }
    if(s == as)
      cout << "1";
    else
      cout << "0";
  }