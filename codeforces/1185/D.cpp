#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x,y,z,flag=0,tmp=0;
    cin>>x;
    ll arr[x];
    map<ll,ll>mp;
    for (ll i = 0; i < x; i++)cin >> arr[i],mp[arr[i]]=i+1;
    sort(arr, arr + x);
    z = (arr[1] - arr[0]);
    y = arr[0];
    for (ll i = 2; i < x; i++) {
        if (((arr[i] - arr[0]) % i != 0 || ((arr[i] - arr[0]) / i) != z) && flag == 0)flag = 1, y = arr[i];
        else if (flag) {
            if (((arr[i] - arr[0]) % (i - 1)) != 0 || ((arr[i] - arr[0]) / (i - 1)) != z)tmp = 1;
        }
    }
    if (tmp == 0)cout << mp[y] << "\n";
    else {
        z = arr[2] - arr[1], flag = 0;
        for (ll i = 3; i < x; i++) {
            if (((arr[i] - arr[1]) % (i - 1) != 0 || ((arr[i] - arr[1]) / (i - 1)) != z) && flag == 0)
                flag = 1, y = arr[i];
        }
        if (!flag)cout << mp[arr[0]] << "\n";
        else {
            z = arr[2] - arr[0];
            flag = 0;
            for (ll i = 3; i < x; i++) {
                if (((arr[i] - arr[0]) % (i - 1) != 0 || ((arr[i] - arr[0]) / (i - 1)) != z) && flag == 0)flag = 1;
            }
            if(!flag)cout<<mp[arr[1]]<<"\n";
            else cout<<-1<<"\n";
        }
      }
}
