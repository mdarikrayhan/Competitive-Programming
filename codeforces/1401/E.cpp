#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


signed main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    /*#ifdef ONLINE_JUDGE
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    #endif*/ //fast IO
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> sweepbegin;
    vector<pair<int,int>> sweepend; //x,y
    /*sweepbegin.push_back({0,0});
    sweepbegin.push_back({0,1000000});
    sweepend.push_back({1000000,0});
    sweepend.push_back({1000000,1000000});*/
    int tau = 0;
    for (int i=0; i<n; i++) {
        int y,l,r;
        cin >> y >> l >> r;
        if (l==0 && r==1000000) {
            tau++;
        }
        sweepbegin.push_back({l,y});
        sweepend.push_back({r,y});
    }
    sort(sweepbegin.begin(), sweepbegin.end());
    sort(sweepend.begin(), sweepend.end());
    int pbeg = 0;
    int pend = 0;
    vector<vector<int>> vert;
    for (int i=0; i<m; i++) {
        int x,l,r;
        cin >> x >> l >> r;
        if (l==0 && r==(1<<20)-48576) {
            tau++;
        }
        vert.push_back({x,l,r});
    }
    //vert.push_back({1000000,0,1000000});
    //vert.push_back({0,0,1000000});
    ordered_set currenthory;
    sort(vert.begin(), vert.end());
    int regions = 0;
    for (int i=0; i<vert.size(); i++) {
        int curx = vert[i][0];
        while (pbeg<sweepbegin.size() && sweepbegin[pbeg].first<=curx) {
            currenthory.insert(sweepbegin[pbeg].second);
            pbeg++;
        }
        while (pend<sweepend.size() && sweepend[pend].first<curx) {
            currenthory.erase(sweepend[pend].second);
            pend++;
        }
        int le = vert[i][1];
        int ri = vert[i][2];
        int a1 = currenthory.order_of_key(le);
        int a2 = currenthory.order_of_key(ri+1);
        /*cout << "VARS" << " " << i << endl;
        cout << i << " " << a1 <<" " << a2 << " " << a2-a1 << " " << pbeg <<" " << pend << " " << sweepend[pend].first << endl;
        cout << "CURRENT SET" << endl;
        for (auto j:currenthory) {
            cout << j << " ";
        }
        cout << endl;*/
        regions+=a2-a1;
        
    }
    cout << regions+1+tau << endl;
    
}

