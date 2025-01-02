#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long int a[n];
    long long int sum=0;
    int even=0,odd=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum=sum+a[i];
        if(a[i]%2==0){
            even++;
        }
        else {
            odd++;
        }
    }
    long long int w;
    if(odd%2==0){
        cout<<sum<<endl;
    }
    else {
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(a[i]%2!=0){
                w=a[i];
                break;
            }
        }
        cout<<sum-w<<endl;
    }
}
