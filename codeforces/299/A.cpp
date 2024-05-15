#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,c=0;
    cin>>a;
    int b[a];
    for(int i=0; i<a; i++)
    {
        cin>>b[i];
    }
    sort(b,b+a);
    for(int i=0; i<a; i++)
    {
        if(b[i]%b[0]==0)
        {
            c++;
        }
    }
    if(c==a)
    {
        cout<<b[0]<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
}
