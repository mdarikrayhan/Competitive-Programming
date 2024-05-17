#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define usm freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define pii pair<int,int>
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    map<string,int> mp;
    mp["C"] = 0;
    mp["C#"] = 1;
    mp["D"] = 2;
    mp["D#"] = 3;
    mp["E"] = 4;
    mp["F"] = 5;
    mp["F#"] = 6;
    mp["G"] = 7;
    mp["G#"] = 8;
    mp["A"] = 9;
    mp["B"] = 10;
    mp["H"] = 11;
    string x,y,z;
    cin >> x >> y >> z;
    vector<int> arr = {mp[x],mp[y],mp[z]};
    sort(arr.begin(),arr.end());
    do {
        if ((arr[1] == (arr[0]+4)%12) && (arr[2] == (arr[1]+3)%12)){
            cout << "major" << endl;
            return 0;
        }
        if  ((arr[1] == (arr[0]+3)%12) && (arr[2] == (arr[1]+4)%12)){
            cout << "minor" << endl;
            return 0;
        }
    } while (next_permutation(arr.begin(),arr.end()));
    cout << "strange" << endl;
    return 0;
}