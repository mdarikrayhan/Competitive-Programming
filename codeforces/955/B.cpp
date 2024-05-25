#include<bits/stdc++.h>
#define ll long long
#define d double
#define ld long double
#define F first
#define S second
#define ii pair<int,int>
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a;
    cin>>a;
    int n=a.size();
    sort(a.begin(),a.end());
    multiset<int>ms;
    for(int i=1;i<n;i++)
    {
        int cnt=1;
        while(i<n&&a[i]==a[i-1])
            cnt++,i++;
        if(i==n-1)
            ms.insert(1);
        ms.insert(cnt);
    }
    if(ms.size()>1&&ms.size()<5)
    {
        int x=0;
        for(auto z:ms)
            if(z>1)
                x++;
        if(x>1)
            cout<<"Yes"<<endl;
        else if(x==1&&ms.size()>2)
            cout<<"Yes"<<endl;
        else if(ms.size()==4)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    else
        cout<<"No"<<endl;

    return 0;
}
