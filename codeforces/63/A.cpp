#include <iostream>
#include <string>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <bits/stdc++.h>

#define $AzH_TxdmN$               \
    ios_base::sync_with_stdio(0); \
    cin.tie(nullptr);             \
    cout.tie(nullptr);
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")

#define ep emplace_back
#define pb push_back
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using __indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using __indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void mal()
{
      int n;
    cin >> n;

    string name, status;
    vector<string> rats, womenandchildren, men, captain;
    while (n--)
    {
        cin >> name >> status;
        if (status == "rat")
        {
            rats.push_back(name);
        }
        else if (status == "woman" || status == "child")
        {
            womenandchildren.push_back(name);
        }
        else if (status == "man")
        {
            men.push_back(name);
        }
        else
        {
            captain.push_back(name);
        }
    }
    for (auto one : rats)
    {
        cout << one << endl;
    }
    for (auto one : womenandchildren)
    {
        cout << one << endl;
    }
    for (auto one : men)
    {
        cout << one << endl;
    }
    for (auto one : captain)
    {
        cout << one << endl;
    }

}
signed main()
{
    mal();
    return 0;
}
