#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> v;
    int x;
    cin >> x;
    v.push_back(x);
    int g=x;int flag=0;
    for (int i = 1; i < n; i++)
    {
      cin >> x;
      v.push_back(x);
      if(x%g!=0)
      flag=1;
    }
    cout<<(flag==0?"YES":"NO")<<endl;
  }
}