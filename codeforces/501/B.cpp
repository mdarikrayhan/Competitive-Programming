//
// Created by Gamal on 5/16/2024.
// https://vjudge.net/contest/585111#problem/Z
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
struct un_ordered
{
    bool operator()(const long long &a, const long long &b) const
    {
        return true;
    }
};
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int q;
    cin >> q;
    map<string, string> old_new;
    while (q--) {
        string old_handle, new_handle;
        cin >> old_handle >> new_handle;
        if (old_new.find(old_handle) == old_new.end()) {
            old_new[new_handle] = old_handle;
        } else {
            string original_handle = old_new[old_handle];
            old_new.erase(old_handle);
            old_new[new_handle] = original_handle;
        }

    }
    cout << old_new.size() << endl;
        for (const auto &item: old_new) {
            cout << item.second << " " << item.first << endl;
        }
        return 0;

}