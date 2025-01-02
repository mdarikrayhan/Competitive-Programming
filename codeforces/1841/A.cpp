#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        cout<<"Alice"<<endl;
        else if(n==2||n==3||n==4)
        cout<<"Bob"<<endl;
        else
        cout<<"Alice"<<endl;
    }
    return 0;
}