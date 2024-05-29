#pragma GCC optimize("O3", "Ofast", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s;
    cin>>n>>s;
    int c3=0, c4=0, c5=0;
    for(int i=1, x; i<=n; i++)
    {
        cin>>x;
        if(x==3)++c3;
        else if(x==4)++c4;
        else ++c5;
    }
    int minim=1e9, ans3, ans4, ans5;
    for(int k3=s/n; k3>=0; k3--)
    {
        for(int k4=(s-c3*k3)/(c4+c5); k4>=k3; k4--)
        {
            if((s-c3*k3-c4*k4)%c5==0)
            {
                int k5=(s-c3*k3-c4*k4)/c5;
                if(c5*k5-c4*k4 > minim)
                    break;
                if(k5<k4)continue;
                if(minim > abs(c3*k3 - c4*k4) + abs(c4*k4-c5*k5))
                {
                    minim=abs(c3*k3 - c4*k4) + abs(c4*k4-c5*k5);
                    ans3=k3, ans4=k4, ans5=k5;
                }
            }
        }
    }
    if(minim==1e9)
        cout<<-1;
    else
        cout<<ans3<<' '<<ans4<<' '<<ans5;
    return 0;
}
