#include<bits/stdc++.h>

using namespace std;

const int MAX = 2e5+5;

// ost = ordered set
// omp = ordered map
#define fbo find_by_order
#define ook order_of_key
//op.fbo(x); cari data x-th(ini pointer)[0-indexing]
//op.ook(x); hitung jumlah data yg lbh kcl dari x
#define del(op,val) op.erase(op.fbo(op.ook(val)))

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;
template<class T, class U>
using omp = tree<T, U, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

int n,x,y;
long long ans,ls,nw,k;
map<int,vector<int>> v;
ost<int> op;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	while(n--){
		cin>>x>>y;
		v[-y].push_back(x);
	}
	for(auto &[_,i]:v){
		sort(i.begin(), i.end());
		for(auto j:i)op.insert(j);
		ans+= (long long)op.size()*(op.size()+1);
		ls = 0;
		for(auto j:i){
			nw = op.ook(j);
			k = nw-ls;
			ls = nw+1;
			ans-= k*(k+1);
		}
		k = op.size()-ls;
		ans-= k*(k+1);
	}
	cout<<ans/2<<endl;
	return 0;
}