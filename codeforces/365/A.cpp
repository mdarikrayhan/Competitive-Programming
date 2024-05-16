#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,cnt=0;
    cin>>n>>k;
    while(n--)
    {
        string a;
        cin>>a;
        int freq[10]={};
        for(int i = 0; i < a.size();i++)
        {
            freq[(int)a[i]-'0']=1;
        }
        bool valid=true;
        for(int i = 0; i <= k;i++)
        {
            if(freq[i] != 1)
            {
                valid = false;
                break;
            }
        }
        if(valid)
            cnt++;
    }
    cout<<cnt<<endl;

}
