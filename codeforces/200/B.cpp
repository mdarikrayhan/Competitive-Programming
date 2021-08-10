#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n=0;
    double sum=0;
    cin>>n;
    double arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    sum=sum/n;
    printf("%.12lf",sum);
}