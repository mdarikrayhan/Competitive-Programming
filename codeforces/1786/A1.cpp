#include <iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n--;
        int a=1;
        int b=0;
        int i=2;
        while(n>=i){
            if(i%4==1 || i%4==0){
                a+=i;
            }
            else{
                b+=i;
            }
            n-=i;
            i++;
        }
        if(i%4==1 || i%4==0){
            a+=n;
        }
        else{
            b+=n;
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}