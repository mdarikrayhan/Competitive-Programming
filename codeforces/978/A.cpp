#include <bits/stdc++.h>
using namespace std;


//ya rab ostorha
int main()
{
 int n;
 cin>>n;
 int ar[n];
 int f[1001]={0};
 //int br[n]={0};

 for(int i=0;i<n;i++){

    cin>>ar[i];
    f[ar[i]]++;

 }
 int res=0;
 for(int i=0;i<n;i++){
    if(f[ar[i]]>0){
        res++;
        f[ar[i]]=0;
    }
 }
 cout<<res<<endl;
 for(int i=0;i<n;i++){
        int cn=0;
    for(int j=i+1;j<n;j++){
        if(ar[i]==ar[j]){
            cn++;
            break;
        }
    }
    if(cn==0)
        cout<<ar[i]<<' ';
 }


    return 0;
}
