#include <bits/stdc++.h>
using namespace std;


//ya rab ostorha
int main()
{
 int n;
 cin>>n;
 string s;
 cin>>s;
 int st=0;
 int res=0;
 for(int i=0;i<n;i++){
    if(s[i]=='x')
        st++;
        else{
            st=0;
        }
        if(st>2){
            res++;
        }
 }
 cout<<res;
    return 0;
}
