#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
    string s;
    cin>>s;
    int left=0,right=s.size()-1;
    while(s[left]=='0')
         left++;
    while(s[right]=='0')
       right--;
    int cnt=0;
    for(int i=left;i<=right;i++)
       if(s[i]=='0')
         cnt++;

        cout<<cnt<<endl;
   }

}