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
        int a1=1;
        int a2=0;
        int b1=0;
        int b2=0;
        int i=2;
        bool cnt=1;
        while(n>=i){
            if(i%4==1 || i%4==0){
                if(cnt){
                    a1+=i/2;
                    a2+=(i+1)/2;
                }
                else{
                    a2+=i/2;
                    a1+=(i+1)/2;
                }
                if(i%2==1){
                    cnt=!cnt;
                }
            }
            else{
                if(cnt){
                    b1+=i/2;
                    b2+=(i+1)/2;
                }
                else{
                    b2+=i/2;
                    b1+=(i+1)/2;
                }
                if(i%2==1){
                    cnt=!cnt;
                }
            }
            n-=i;
            i++;
        }
        if(i%4==1 || i%4==0){
            if(cnt){
                a1+=n/2;
                a2+=(n+1)/2;
            }
            else{
                a2+=n/2;
                a1+=(n+1)/2;
            }
        }
        else{
            if(cnt){
                b1+=n/2;
                b2+=(n+1)/2;
            }
            else{
                b2+=n/2;
                b1+=(n+1)/2;
            }
            if(n%2==1){
                cnt=!cnt;
            }
        }
        cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;
    }
    return 0;
}