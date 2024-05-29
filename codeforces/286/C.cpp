#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  vector<int>is_closed(n);
  int k;
  cin>>k;
  while(k--)
  {
      int x;
      cin>>x;
      is_closed[x-1]=true;
  }
  stack<int>st;
  for(int i=n-1;i>=0;i--)
  {
      if(st.empty()||is_closed[i]||a[i]!=st.top())
      {
          st.push(a[i]);
          a[i]=-a[i];
      }
      else
      {
          st.pop();
      }
  }
  if(st.size())
  {
      cout<<"NO"<<endl;
      return 0;
  }
  cout<<"YES"<<endl;
  for(int i=0;i<n;i++)cout<<a[i]<<" ";
}