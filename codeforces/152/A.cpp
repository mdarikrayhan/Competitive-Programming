#include<bits/stdc++.h>

typedef long long ll;

#define min3(a,b,c) min(min(a,b),c)
#define ff first
#define ss second

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    string s[n];
    int cnt=0;
    int best[n]={0};
    for (int i = 0; i < n; ++i)
    {
        cin>>s[i];
    }
    for (int i = 0; i < m; ++i)
    {
        int max=0;
        for (int j = 0; j < n; ++j)
        {
            if (max<(int)s[j][i])
            {
                max=(int)s[j][i];
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (max==(int)s[j][i])
            {
                best[j]=1;
            }
        }
    }
    int sum=0;
    for (int i = 0; i < n; ++i)
    {
        sum+=best[i];
    }
    cout<<sum<<endl;
    return 0;
}
