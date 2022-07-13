/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define multicase int NoOfTestCase = 1;cin >> NoOfTestCase;for(int testcaseno=1;testcaseno<=NoOfTestCase;testcaseno++)
int main() {
fastio
multicase
{
int n;
cin>>n;
int arr[n+3];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
for(int i=0;i<n;i++){
    int a=arr[i],x;
    string s;
    cin>>x>>s;
    for(int j=0;j<x;j++){
        if(s[j]=='D'){//++
            if(a<9){
                a++;
            }
            else{
                a=0;
            }
        }
        else{//---
            if(a>0){
                a--;
            }
            else{
                a=9;
            }
        }
    }
    cout<<a<<" ";
}
cout<<nl;
}
return 0;
}