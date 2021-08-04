#include <iostream>
using namespace std;
int main()
{
    int n,n2,x=0,max=0;
    cin >> n;
    n2=n*2;
    int arr[n2];
    int sum[n];
    for (int i = 0; i < n2; i++)
    {
    cin >> arr[i];  
    }
     for (int i = 0; i < n2; i=i+2)
    {
    x=x-arr[i]+arr[i+1];
    if(x>max){
        max=x;
    }
    }
    cout<<max;

}