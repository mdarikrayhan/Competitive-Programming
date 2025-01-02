#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main()
{
    int n, m,i,j=0,k,l,p,x;

    cin>>n>>m;

    vector<pi> a(m+1);
    for (i=0; i<m; i++)
    {
        cin>>x;
        a[i]= {x,i};
    }

    sort(a.rbegin(), a.rend());
    vector<int>ans(n);

    for (i=0; i<n; i+=2)
    {
        if (a[j].first == 0) j++;
        if (j == m)
        {
            ans.resize(0);
            break;
        }
        ans[i] = a[j].second+1;
        a[j].first--;
    }

    if (n > 1 && n%2 == 1 && j == 0)
    {
        j++;
        if (j >= m)
        {
            ans.resize(0);
        }
        a[j].first--;
        ans[n-1] = a[j].second + 1;
    }

    if (ans.size() > 0)
    {
        if (j == 0) j++;
        for (i=1; i<n; i+=2)
        {
            if (a[j].first == 0) j++;
            if (j >= m)
            {

                ans.resize(0);
                break;
            }
            ans[i] = a[j].second+1;
            a[j].first--;
        }
    }


    if (n > 1 && ans.size() > 0 && ans[n-2] == ans[n-1])
    {
        j++;
        if (j >= m)
        {

            ans.resize(0);
        }
        else
        {
            ans[n-1] = a[j].second + 1;
        }
    }

    if (ans.size() == 0)
    {
        cout<<-1<<"\n";
    }

    for (i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}


