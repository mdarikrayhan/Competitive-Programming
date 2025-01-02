#include<iostream>
#include<algorithm>
using namespace std;
int main(){
long long int t,n,k,total=0,j=0;
cin>>t;
for(int i=0;i<t;i++){
    cin>>n>>k;
    int arr1[n],arr2[n];
    for(j=0;j<n;j++)
        cin>>arr1[j];
    for(j=0;j<n;j++)
        cin>>arr2[j];
    sort(arr1,arr1+n);
    sort(arr2,arr2+n);

    for(j=0;j<k;j++){
        if(arr1[j]<arr2[n-j-1])
            arr1[j]=arr2[n-j-1];
    }

    for(j=0;j<n;j++)
        total+=arr1[j];
    cout<<total<<endl;
    total=0;

}
}