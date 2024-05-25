#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<< #x <<" : "<<x<<endl;
#define dbgv(v) cout<< #v <<" : ";for(auto &i:v) cout<<i<<" ";cout<<endl;
#define endl '\n'
const int MOD = 1e9+ 7;
int seg[1000005];

int main() {
    ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
    int T = 1,i;
    while(T--) {
        int N,M; cin>>N>>M; vector<int>ans; int Q=-1; int P=0; int X=0;
        for(int i=1;i<=N;i++){
            if(i%2==0){
                P=((i)*(i-2))/4;
                if(P>=M){ Q=i; break;}
            }
            else{
                P = ((i-1)*(i-1))/4;
                if(P>=M){ Q=i; break;}
            }
        }
        if(Q==-1){ cout<<-1<<endl;}
        else{
            if(P>M){ Q--;}
            for(int i=1;i<=Q;i++){ ans.push_back(i);}
            if(Q%2==0){ X=2*(M-((Q)*(Q-2))/4);}
            else{ X=2*(M-((Q-1)*(Q-1))/4);}
            if(X>0){
                reverse(ans.begin(),ans.end()); int Z=ans[X-1];
                reverse(ans.begin(),ans.end()); ans.push_back(Z+ans.back());
            }
            int rem=N-int(ans.size());
            if(ans.empty()==true){ for(int i=0;i<N;i++){ ans.push_back(50000 + i+1);}}
            else{ for(int i=0;i<rem;i++){ ans.push_back(50000 + ans.back() + 1);}}
            for(int i=0;i<ans.size();i++){ cout<<ans[i]<<" ";} cout<<endl;
        }
    }
}