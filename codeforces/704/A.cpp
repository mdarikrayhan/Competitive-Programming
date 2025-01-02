
#include <iostream>
#include <set>
#include <map>

using namespace std;

int n, q;

int main() {
    set< pair<int, int> > nums;
    map< int, set<int> > apps;
    cin >> n >> q;
    int id = 0;
    int t, x;
    for (int i = 0; i < q; i++) {
        cin >> t >> x;
        if (t == 1) {
            id++;
            nums.insert(make_pair(id,x));
            apps[x].insert(id);
        } else if (t == 2) {
            if (apps.count(x) != 0) {
                for (auto c : apps[x]) {
                    nums.erase(nums.find(make_pair(c, x))); 
                }
                apps.erase(x);
            } 
        } else {
            while(nums.size() != 0){
                auto t = nums.begin();
                if (t->first > x) { break; }
                apps[t->second].erase(apps[t->second].begin());
                nums.erase(t);
            }
        }
        cout << nums.size() << endl;
    }
    return 0;
}
	 		  					  	 			    		 	