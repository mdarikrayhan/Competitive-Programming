/*

*/

#include <bits/stdc++.h>

using namespace std;

using lt = long long;

void solve()
{

}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    lt t;
    cin>>t;
    while (t--)
    {
        lt n;
        cin>>n;
        vector<lt> a(n);
        for (lt i=0;i!=n;++i) cin>>a[i];
        reverse(begin(a),end(a));
        set<lt> st;
        lt I=n;
        for (lt i=0;i!=n;++i)
        {
            lt p=size(st);
            st.insert(a[i]);
            if (size(st)!=p+1)
            {
                I=i;
                break;
            }
        }
        printf("%lld\n",n-I);
    }
}
