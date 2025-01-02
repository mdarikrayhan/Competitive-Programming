#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int val=0;
        if(s[0]=='1')
        {
            val=1;
        }
        for(int i=1;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(val>0)
                {
                    cout<<"-";
                    val--;
                }
                else
                {
                    cout<<"+";
                    val++;
                }
            }
            else
        {
            cout<<"-";
        }
        }
        cout<<endl;

    }
}
