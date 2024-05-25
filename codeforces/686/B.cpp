#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    vector<int>a(n);   
    map<int,int>m;
    for(int i=0;i<n;i++){
      cin>>a[i];
      m[a[i]]=i+1;
      
    }
      for(int i=0;i<n;i++)
    for(int i=0;i<n-1;i++){
      if(a[i]>a[i+1])
      {
        cout<<i+1<<" "<<i+2<<"\n";
        swap(a[i],a[i+1]);
      }
    }   

    return 0;
}