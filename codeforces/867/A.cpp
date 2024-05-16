#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int a=0,b=0;
    for(int i=1;i<n;i++)
    {
        if(str[i]==str[i-1])
        {
            continue;
        }
        else
        {
            if(str[i]=='S' && str[i-1]=='F')
            {
                a++;
            }
            else
            {
                b++;
            }
        }
    }
    if(a<b)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}