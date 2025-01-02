#include<bits/stdc++.h>
using namespace std;
int Points(int p, int t)
{
    return max(3*p/10,p-p/250*t);
}

int main()
{
    int a,b,c,d;

    while(cin>>a>>b>>c>>d)
    {
        int mishapoints=Points(a,c);
        int vasyapoints=Points(b,d);

        if(mishapoints>vasyapoints)
        {
            cout<<"Misha"<<endl;
        }
        else if(vasyapoints>mishapoints)
        {
            cout<<"Vasya"<<endl;
        }
        else
        {
            cout<<"Tie"<<endl;
        }
    }
}
