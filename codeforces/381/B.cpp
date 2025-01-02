/* -----------------  إِنَّا لا نُضِيعُ أَجْرَ مَنْ أَحْسَنَ عَمَلا  ----------------- */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ld long double
#define For1(n) for(int i=0; i<n; i++)
#define For2(n) for(int j=0; j<n; j++)
#define test int t; cin >> t; while(t--) solve();
#define sb << '\n'
#define pi 3.14159265358979323846
using namespace std;
//#pragma GCC optimize("Ofast,unroll-loops,O3")
//#pragma GCC target("avx2,tune=native")
/* **************************************************************** */
int freq[500001];
void solve() //SOLVE
{
    int m,sum;cin >> m;
    int arr[m];
    vector<pair<int,int>>ans;
    deque<int>dq;
    For1(m){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    For1(5001){
        if(!freq[i])continue;
        sum=0;
        for(int j=1; j<i; j++){
            if(!freq[j])continue;
            sum+=min(2,freq[j]);
        }
        ans.emplace_back(sum,i);
    }
    sort(ans.begin(), ans.end());
    dq.emplace_back(ans.back().second);
    for(int j=dq.front()-1; j>0; j--){
        if(!freq[j])continue;
        if(freq[j]>1)
            dq.emplace_back(j),dq.emplace_front(j);
        else dq.emplace_back(j);
    }
    cout << dq.size() sb;
    For1(dq.size()) cout << dq[i] << ' ';
}
/* **************************************************************** */
int main() //MAIN
{
    IOS
    //test
    solve();

    return 0;
}