#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int first=0,last=n-1,max,k=0,sereja=0,dima=0;
    while(first<=last)
    {
        if(a[first]>=a[last])
        {
            max=a[first];
            first++;
        }
        else
        {
            max=a[last];
            last--;
        }
        if(k%2==0)
        {
            dima=dima+max;
        }
        else
        {
            sereja=sereja+max;
        }
        k++;
    }
    cout<<dima<<" "<<sereja<<endl;
    return 0;
}
