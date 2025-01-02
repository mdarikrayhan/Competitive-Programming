#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int a,b,c;
    cin >>a>>b;
    c = (a+b)/4;
    if (a<c) cout << a << endl;
    else if (b<c) cout << b << endl;
    else cout << c << endl;

  }
}