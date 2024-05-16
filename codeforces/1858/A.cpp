#include<iostream>
using namespace std;

int main()
{
    int t;cin>>t;
    for(int j=0;j<t;j++)
    {
        int arr[3];
        for(int i=0;i<3;i++)
        {
            cin>>arr[i];
        }
        if(arr[2]%2==0)
        {
            if(arr[0]<=arr[1])
            {
                cout<<"Second"<<endl;
            }
            else
            {
                cout<<"First"<<endl;
            }
        }
        else{
            if(arr[0]>=arr[1])
            {
                cout<<"First"<<endl;
            }
            else{
                cout<<"Second"<<endl;
            }
        }
    }
}