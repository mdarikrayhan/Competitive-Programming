#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        //cout<<n<<endl;
        if(n%7==0){
            cout<<n<<endl;
        }
        else{
            n-=n%10;
            for(int i=0;i<10;i++){
                //cout<<n<<endl;
                if(n%7==0){
                    cout<<n<<endl;
                    break;
                }
                n++;
            }
        }
    }    
    return 0;
}