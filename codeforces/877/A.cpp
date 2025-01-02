#include<bits/stdc++.h>
using namespace std;

#define tt int t;cin>>t;while(t--)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inparr(arr,n) for(int i=0;i<n;i++){cin>>arr[i];}

int func(string s,string x)
{

    int i=0,count=0;
    while((i=s.find(x,i))!=string::npos)
    {
        count++;
        i+=x.length();
    }
    return count;
}

int main()
{
  fio
  
  string data[5]={"Danil","Olya","Slava","Ann","Nikita"};
  
  string s;
  cin>>s;
  int count=0;
  
  for(int i=0;i<5;i++)
    count+=func(s,data[i]);  
  
  cout<<(count==1?"YES":"NO")<<endl;
}