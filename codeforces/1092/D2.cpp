#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    stack<int> st;

    int max = *max_element(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i)
    {
        if (st.empty() || st.top() > arr[i])
        {
            st.push(arr[i]);
        }

        else if (st.top() == arr[i])
        {
            st.pop();
        }

        else if (st.top() < arr[i])
        {
            cout << "NO";
            return;
        }
    }
    if (st.size() == 1 && st.top() != max)
        cout << "NO";
    else
    {
        if (st.size() <= 1)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

/*
14

7 7 7 4 3 3 4 5 4 4 5 7 7 7

*/
