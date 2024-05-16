#include<iostream>
using namespace std;
int main()
{
    int n,m,c=0,co=0,run=0;
    cin>>n>>m;
    int arr[2*m];
    for(int i=0;i<n;i++)
    {
    int flag=0;
    for(int j=0;j<(2*m);j++)
    {
        cin>>arr[j];
        c++;
        if(flag!=1)
        {
        if(arr[j]==1){
        flag=1;
        run=1;
        }
        }
        if(flag==1&&run==1)
        {
        co+=1;
        run=0;
        }
        if(c==2){
        c=0;
        flag=0;
        }
    }
    }
    cout<<co;
}