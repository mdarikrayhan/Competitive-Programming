#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> pow2(31, 1);
    for(int i = 1; i<31; i++){
        pow2[i] = pow2[i-1] * 2;
    }
    int n, l;
    cin >> n >> l;
    vector<pair<double, pair<long long, long long>>> bottles;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        bottles.push_back({(double)a / pow2[i], {pow2[i], a}});//cost per liter,   amount in bottle,    cost of bottle overall
    }
    sort(begin(bottles), end(bottles));
    /*
    for(int i = 0; i<n; i++){
        cout << bottles[i].first << " " << bottles[i].second.first << " " << bottles[i].second.second<<endl;
    }*/
    long long remaining = l;
    long long bestcost = 1e18;
    long long curcost = 0;
    for(int i = 0; i<n; i++){
        //get as many as possible at the current location, without getting any extra
        curcost += (remaining / bottles[i].second.first) * bottles[i].second.second;
        remaining -= ((remaining / bottles[i].second.first)*bottles[i].second.first);
        bestcost = min(bestcost, curcost + (remaining / bottles[i].second.first + (remaining % bottles[i].second.first == 0 ? 0 : 1)) * bottles[i].second.second);
        //cout << bestcost << " " << endl;
    }
    cout << bestcost << endl;
}