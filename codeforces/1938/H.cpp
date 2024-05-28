#include <bits/stdc++.h>
using namespace std;
int n,cnt[100001][2],res,mask;
string s;
int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(nullptr);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> s;
        for (auto c:s)
            cnt[i][c-'0']++;
        res+=min(cnt[i][0],cnt[i][1]);
        mask|=(cnt[i][0]<cnt[i][1]?1:2);
    }
    if (!res){
        cout << 0;
        return 0;
    }
    if (mask!=3){
        int mn=1e9;
        for (int i=1;i<=n;i++)
            mn=min(mn,abs(cnt[i][0]-cnt[i][1]));
        res+=mn;
    }
    cout << res;
}
