#include <bits/stdc++.h>

using namespace std;
//https://codeforces.com/problemset/problem/1935/D

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;



#define ordered_set tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

#define uni(a) cout<<a<<endl;
#define duo(a,b) cout<<a<<" "<<b<<endl;
#define tri(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;

#define forn(a,b,i) for (int i=  a; i < b; i++)


#define db(v) for (auto x: v) cout<<x<<" "; cout<<endl;
#define dbii(v) for(auto x: v) cout<<x.first<<" "<<x.second<<endl;

#define iosFast ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
#define int long long
#define endl '\n'

const int mod = 1e18+9;

/*
Suffix array O(n lg^2 n)
LCP table O(n)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

namespace SuffixArray
{
    const int MAXN = 1 << 21;
    const char * S;
    int N, gap;
    int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

    bool sufCmp(int i, int j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i < N && j < N) ? pos[i] < pos[j] : i > j;
    }

    void buildSA()
    {
        N = strlen(S);
        REP(i, N) sa[i] = i, pos[i] = S[i];
        for (gap = 1;; gap *= 2)
        {
            sort(sa, sa + N, sufCmp);
            REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
            REP(i, N) pos[sa[i]] = tmp[i];
            if (tmp[N - 1] == N - 1) break;
        }
    }

    void buildLCP()
    {
        for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
        {
            for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
            ++k;
            lcp[pos[i]] = k;
            if (k)--k;
        }
    }
    
    vector<int> SAC(string s){
    	S = s.c_str();
    	buildSA();
    	vector<int> ans(sa, sa + s.length());
    	return ans;
    }
    
    vector<int> RLCP(){
    	buildLCP();
    	vector<int> ans(lcp, lcp + N-1);
    	return ans;
    }
    
} // end namespace SuffixArray


vector<int> kasai(string s, vector<int> sa)
{
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);

    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}

signed main(){
	iosFast;
	int n; cin>>n;
	string s; cin>>s;
	reverse(s.begin(), s.end());
	string bm; cin>>bm;
	reverse(bm.begin(), bm.end());
	//cout<<s<<endl;
	vector<int> sa = SuffixArray::SAC(s);
	
	vector<int> lcp1 = kasai(s,sa);
	//db(sa);
	//db(lcp1);
	vector<int> lcp;
	int ans  = 0;
	for (int i = bm.length() -1; i >= 0; i--) if (bm[i] != '1') ans = bm.length() - i;
	vector<int> bb(n);
	for (int i = 0;i < n; i++) bb[i] = '1' - bm[sa[i]];
	//db(bb);
	vector<int> div;
	for (int i = 0; i < n ;i++) if (bb[i] == 1) div.push_back(i);
	//db(div);
	for (int i = 1; i < div.size(); i++){
		int ans = 1e6;
		for (int j = div[i-1]; j < div[i]; j++){
			ans = min(ans, lcp1[j]);
		}
		lcp.push_back(ans);
	}
	//db(lcp);
	//cout<<ans<<endl;
	ordered_set ss;
	//	cout<<ans<<endl;
	if (ans == 0){
		cout<<0<<endl;
		return false;
	}
	//db(sp);
	
	
	
	map<int, vector<int>> m;
	for (int i = 0; i < lcp.size(); i++) m[lcp[i]].push_back(i);
	
	for (auto x: m){
		for (int i = 0; i < x.second.size(); i++){
			int pos = x.second[i];
			//cout<<pos<<endl;
			int ini = ss.order_of_key(pos);
			int fin = ini;
			//cout<<pos<<" "<<x.first<<endl;
			if (ini != 0){
				ini = *ss.find_by_order(ini-1)+1;
			}
			if (fin == ss.size()){
				fin = lcp.size() - 1;
			}else{
				//cout<<fin<<endl;
				//db(ss);
				fin = *ss.find_by_order(fin)-1;
				
				//cout<<fin<<endl;
				//return false;
			}
			//cout<<pos<<"---"<<ini<<"=="<<fin<<endl;
			ans = max(ans, x.first*(fin - ini+2));
			
			
		}//cout<<endl;
		for (int i = 0; i < x.second.size(); i++){
			ss.insert(x.second[i]);
		}
	}
	cout<<ans<<endl;
	
	
}